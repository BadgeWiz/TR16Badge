/*
 * Copyright (c) 2014, Texas Instruments Incorporated - http://www.ti.com/
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*---------------------------------------------------------------------------*/
/**
 * \addtogroup pwm-peripherals
 * @{
 *
 * \file
 *  Driver for the Badge pwm
 */
/*---------------------------------------------------------------------------*/
#include "contiki-conf.h"
#include "pwm.h"
#include "ti-lib.h"
#include "lpm.h"

#include <stdint.h>
#include <string.h>
#include <stdio.h>
/*---------------------------------------------------------------------------*/
static uint8_t pwm_on;
LPM_MODULE(pwm_module, NULL, NULL, NULL, LPM_DOMAIN_PERIPH);
/*---------------------------------------------------------------------------*/
void pwm_init()
{
	pwm_on = 0;
}

/*---------------------------------------------------------------------------*/
uint8_t pwm_state()
{
	return pwm_on;
}

/*---------------------------------------------------------------------------*/
void pwm_start(int freq)
{
	uint32_t load;

	/* Enable GPT0 clocks under active, sleep, deep sleep */
	ti_lib_prcm_peripheral_run_enable(PRCM_PERIPH_TIMER0);
	ti_lib_prcm_peripheral_sleep_enable(PRCM_PERIPH_TIMER0);
	ti_lib_prcm_peripheral_deep_sleep_enable(PRCM_PERIPH_TIMER0);
	ti_lib_prcm_load_set();
	while (!ti_lib_prcm_load_get()) ;

	/* Drive the I/O ID with GPT0 / Timer A */
	ti_lib_ioc_port_configure_set(BOARD_IOID_LCD_PWM,
				      IOC_PORT_MCU_PORT_EVENT0, IOC_STD_OUTPUT);

	/* GPT0 / Timer A: PWM, Interrupt Enable */
	HWREG(GPT0_BASE + GPT_O_TAMR) =
	    (TIMER_CFG_A_PWM & 0xFF) | GPT_TAMR_TAPWMIE;

	pwm_on = 1;

	/*
	 * Register ourself with LPM. This will keep the PERIPH PD powered on
	 * during deep sleep, allowing the pwm to keep working while the chip is
	 * being power-cycled
	 */
	lpm_register_module(&pwm_module);

	/* Stop the timer */
	ti_lib_timer_disable(GPT0_BASE, TIMER_A);

	if (freq > 0) {
		load = (GET_MCU_CLOCK / freq);

		ti_lib_timer_load_set(GPT0_BASE, TIMER_A, load);
		ti_lib_timer_match_set(GPT0_BASE, TIMER_A, load / 2);

		/* Start */
		ti_lib_timer_enable(GPT0_BASE, TIMER_A);
	}
}

/*---------------------------------------------------------------------------*/
void pwm_stop()
{
	pwm_on = 0;

	/*
	 * Unregister the pwm module from LPM. This will effectively release our
	 * lock for the PERIPH PD allowing it to be powered down (unless some other
	 * module keeps it on)
	 */
	lpm_unregister_module(&pwm_module);

	/* Stop the timer */
	ti_lib_timer_disable(GPT0_BASE, TIMER_A);

	/*
	 * Stop the module clock:
	 *
	 * Currently GPT0 is in use by clock_delay_usec (GPT0/TB) and by this
	 * module here (GPT0/TA).
	 *
	 * clock_delay_usec
	 * - is definitely not running when we enter here and
	 * - handles the module clock internally
	 *
	 * Thus, we can safely change the state of module clocks here.
	 */
	ti_lib_prcm_peripheral_run_disable(PRCM_PERIPH_TIMER0);
	ti_lib_prcm_peripheral_sleep_disable(PRCM_PERIPH_TIMER0);
	ti_lib_prcm_peripheral_deep_sleep_disable(PRCM_PERIPH_TIMER0);
	ti_lib_prcm_load_set();
	while (!ti_lib_prcm_load_get()) ;

	/* Un-configure the pin */
	ti_lib_ioc_pin_type_gpio_input(BOARD_IOID_LCD_PWM);
	ti_lib_ioc_io_input_set(BOARD_IOID_LCD_PWM, IOC_INPUT_DISABLE);
}

/*---------------------------------------------------------------------------*/
/** @} */
