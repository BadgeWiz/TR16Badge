/*
  ADS7846/TSC2046 Touch-Controller Lib for Arduino
  by Watterott electronic (www.watterott.com)
	AND HACKED BY JEFFMAKES HUURGH!!!!1!
 */

#include "ADS7846.h"
#include <inttypes.h>
#include "ti-lib.h"
#include "board-spi.h"
#include "board.h"
#include <stdio.h>		/* For printf() */
#include "contiki.h"

#define SOFTWARE_SPI 1		//use software SPI on pins MOSI:11, MISO:12, SCK:13

#define HIGH (1)
#define LOW (0)

//#define USE_EEPROM

#if defined(SOFTWARE_SPI)
//# define BUSY_PIN       5
//# define IRQ_PIN        3
#define CS_PIN         BOARD_TOUCH_CS
#define MOSI_PIN       BOARD_SPI_MOSI
#define MISO_PIN       BOARD_SPI_MISO
#define SCK_PIN        BOARD_SPI_SCK
#else
//# define BUSY_PIN       5
//# define IRQ_PIN        3
//# define CS_PIN         (6) //SPI_HW_SS_PIN
//# define MOSI_PIN       SPI_HW_MOSI_PIN
//# define MISO_PIN       SPI_HW_MISO_PIN
//# define SCK_PIN        SPI_HW_SCK_PIN
#endif

#define CS_DISABLE()    ti_lib_gpio_pin_write(CS_PIN, HIGH)
#define CS_ENABLE()     ti_lib_gpio_pin_write(CS_PIN, LOW)

#define MOSI_HIGH()     ti_lib_gpio_pin_write(MOSI_PIN, HIGH)
#define MOSI_LOW()      ti_lib_gpio_pin_write(MOSI_PIN, LOW)

#define MISO_READ()     ti_lib_gpio_pin_read(MISO_PIN)

#define SCK_HIGH()      ti_lib_gpio_pin_write(SCK_PIN, HIGH)
#define SCK_LOW()       ti_lib_gpio_pin_write(SCK_PIN, LOW)

//#define BUSY_READ()     ti_lib_gpio_pin_read(BUSY_PIN)

//#define IRQ_READ()      ti_lib_gpio_pin_read(IRQ_PIN)

#define MIN_PRESSURE    5	//minimum pressure 1...254

#ifndef LCD_WIDTH
#define LCD_WIDTH      320
#define LCD_HEIGHT     240
#endif

#ifndef CAL_POINT_X1
#define CAL_POINT_X1   20
#define CAL_POINT_Y1   20
#define CAL_POINT1     {CAL_POINT_X1,CAL_POINT_Y1}
#define CAL_POINT_X2   LCD_WIDTH-20	//300
#define CAL_POINT_Y2   LCD_HEIGHT/2	//120
#define CAL_POINT2     {CAL_POINT_X2,CAL_POINT_Y2}
#define CAL_POINT_X3   LCD_WIDTH/2	//160
#define CAL_POINT_Y3   LCD_HEIGHT-20	//220
#define CAL_POINT3     {CAL_POINT_X3,CAL_POINT_Y3}
#endif

#define CMD_START       0x80
#define CMD_12BIT       0x00
#define CMD_8BIT        0x08
#define CMD_DIFF        0x00
#define CMD_SINGLE      0x04
#define CMD_X_POS       0x10
#define CMD_Z1_POS      0x30
#define CMD_Z2_POS      0x40
#define CMD_Y_POS       0x50
#define CMD_PWD         0x00
#define CMD_ALWAYSON    0x03

//-------------------- Public --------------------

void ADS7846_begin(void)
{
	ti_lib_ioc_pin_type_gpio_output(BOARD_IOID_TOUCH_CS);
	ti_lib_ioc_pin_type_gpio_output(BOARD_IOID_SPI_MOSI);
	ti_lib_ioc_pin_type_gpio_output(BOARD_IOID_SPI_SCK);
	ti_lib_ioc_pin_type_gpio_input(BOARD_IOID_SPI_MISO);

	CS_DISABLE();

#ifdef IRQ_PIN
	pinMode(IRQ_PIN, INPUT);
	digitalWrite(IRQ_PIN, HIGH);	//pull-up
#endif
#ifdef BUSY_PIN
	pinMode(BUSY_PIN, INPUT);
	digitalWrite(BUSY_PIN, HIGH);	//pull-up
#endif

#if !defined(SOFTWARE_SPI)
	SPI.setDataMode(SPI_MODE0);
	SPI.begin();
#endif

	//set vars
	tp_matrix.div = 0;
	tp_x = 0;
	tp_y = 0;
	tp_last_x = 0;
	tp_last_y = 0;
	lcd_x = 0;
	lcd_y = 0;
	pressure = 0;
	ADS7846_setOrientation(0);

	return;
}

void ADS7846_setOrientation(uint_least16_t o)
{
	switch (o) {
	default:
	case 0:
		lcd_orientation = 0;
		break;
	case 9:
	case 90:
		lcd_orientation = 90;
		break;
	case 18:
	case 180:
		lcd_orientation = 180;
		break;
	case 27:
	case 14:		//270&0xFF
	case 270:
		lcd_orientation = 270;
		break;
	}

	return;
}

void ADS7846_setRotation(uint_least16_t r)
{
	return ADS7846_setOrientation(r);
}

uint_least8_t ADS7846_setCalibration(CAL_POINT * lcd, CAL_POINT * tp)
{
	tp_matrix.div = ((tp[0].x - tp[2].x) * (tp[1].y - tp[2].y)) -
	    ((tp[1].x - tp[2].x) * (tp[0].y - tp[2].y));

	if (tp_matrix.div == 0) {
		return 0;
	}

	tp_matrix.a = ((lcd[0].x - lcd[2].x) * (tp[1].y - tp[2].y)) -
	    ((lcd[1].x - lcd[2].x) * (tp[0].y - tp[2].y));

	tp_matrix.b = ((tp[0].x - tp[2].x) * (lcd[1].x - lcd[2].x)) -
	    ((lcd[0].x - lcd[2].x) * (tp[1].x - tp[2].x));

	tp_matrix.c = (tp[2].x * lcd[1].x - tp[1].x * lcd[2].x) * tp[0].y +
	    (tp[0].x * lcd[2].x - tp[2].x * lcd[0].x) * tp[1].y +
	    (tp[1].x * lcd[0].x - tp[0].x * lcd[1].x) * tp[2].y;

	tp_matrix.d = ((lcd[0].y - lcd[2].y) * (tp[1].y - tp[2].y)) -
	    ((lcd[1].y - lcd[2].y) * (tp[0].y - tp[2].y));

	tp_matrix.e = ((tp[0].x - tp[2].x) * (lcd[1].y - lcd[2].y)) -
	    ((lcd[0].y - lcd[2].y) * (tp[1].x - tp[2].x));

	tp_matrix.f = (tp[2].x * lcd[1].y - tp[1].x * lcd[2].y) * tp[0].y +
	    (tp[0].x * lcd[2].y - tp[2].x * lcd[0].y) * tp[1].y +
	    (tp[1].x * lcd[0].y - tp[0].x * lcd[1].y) * tp[2].y;

	return 1;
}

#ifdef USE_EEPROM
uint_least8_t ADS7846_writeCalibration(uint16_t eeprom_addr)
{
	if (tp_matrix.div != 0) {
		eeprom_write_byte((uint8_t *) eeprom_addr++, 0x55);
		eeprom_write_block((void *)&tp_matrix, (void *)eeprom_addr,
				   sizeof(CAL_MATRIX));
		return 1;
	}

	return 0;
}

uint_least8_t ADS7846_readCalibration(uint16_t eeprom_addr)
{
	uint_least8_t c;

	c = eeprom_read_byte((uint8_t *) eeprom_addr++);
	if (c == 0x55) {
		eeprom_read_block((void *)&tp_matrix, (void *)eeprom_addr,
				  sizeof(CAL_MATRIX));
		return 1;
	}

	return 0;
}
#endif

/*uint_least8_t ADS7846_doCalibration(MI0283QT2 *lcd, uint16_t eeprom_addr, uint_least8_t check_eeprom) //example touch panel calibration routine
{
  uint_least8_t i;
  CAL_POINT lcd_points[3] = {CAL_POINT1, CAL_POINT2, CAL_POINT3}; //calibration point postions
  CAL_POINT tp_points[3];

  //calibration data in EEPROM?
  if(readCalibration(eeprom_addr) && check_eeprom)
  {
    return 0;
  }

  //clear screen and wait for touch release
  lcd->fillScreen(RGB(255,255,255));
#if (defined(__AVR__) || defined(ARDUINO_ARCH_AVR))
  lcd->drawTextPGM((lcd->getWidth()/2)-50, (lcd->getHeight()/2)-10, PSTR("Calibration"), RGB(0,0,0), RGB(255,255,255), 1);
#else
  lcd->drawText((lcd->getWidth()/2)-50, (lcd->getHeight()/2)-10, "Calibration", RGB(0,0,0), RGB(255,255,255), 1);
#endif
  while(getPressure() > MIN_PRESSURE){ service(); };

  //show calibration points
  for(i=0; i<3; )
  {
    //draw points
    lcd->drawCircle(lcd_points[i].x, lcd_points[i].y,  2, RGB(  0,  0,  0));
    lcd->drawCircle(lcd_points[i].x, lcd_points[i].y,  5, RGB(  0,  0,  0));
    lcd->drawCircle(lcd_points[i].x, lcd_points[i].y, 10, RGB(255,  0,  0));

    //run service routine
    service();

    //press dectected? -> save point
    if(getPressure() > MIN_PRESSURE)
    {
      lcd->fillCircle(lcd_points[i].x, lcd_points[i].y, 2, RGB(255,0,0));
      tp_points[i].x = getXraw();
      tp_points[i].y = getYraw();
      i++;

      //wait and redraw screen
      delay(100);
      lcd->fillScreen(RGB(255,255,255));
#if (defined(__AVR__) || defined(ARDUINO_ARCH_AVR))
      lcd->drawTextPGM((lcd->getWidth()/2)-50, (lcd->getHeight()/2)-10, PSTR("Calibration"), RGB(0,0,0), RGB(255,255,255), 1);
#else
      lcd->drawText((lcd->getWidth()/2)-50, (lcd->getHeight()/2)-10, "Calibration", RGB(0,0,0), RGB(255,255,255), 1);
#endif
    }
  }

  //calulate calibration matrix
  setCalibration(lcd_points, tp_points);

  //save calibration matrix
  writeCalibration(eeprom_addr);

  //wait for touch release
  while(getPressure() > MIN_PRESSURE){ service(); };

  return 1;
}*/

/*uint_least8_t ADS7846_doCalibration(MI0283QT9 *lcd, uint16_t eeprom_addr, uint_least8_t check_eeprom) //example touch panel calibration routine
{
  uint_least8_t i;
  CAL_POINT lcd_points[3] = {CAL_POINT1, CAL_POINT2, CAL_POINT3}; //calibration point postions
  CAL_POINT tp_points[3];

  //calibration data in EEPROM?
  if(readCalibration(eeprom_addr) && check_eeprom)
  {
    return 0;
  }

  //clear screen and wait for touch release
  lcd->fillScreen(RGB(255,255,255));
#if (defined(__AVR__) || defined(ARDUINO_ARCH_AVR))
  lcd->drawTextPGM((lcd->getWidth()/2)-50, (lcd->getHeight()/2)-10, PSTR("Calibration"), RGB(0,0,0), RGB(255,255,255), 1);
#else
  lcd->drawText((lcd->getWidth()/2)-50, (lcd->getHeight()/2)-10, "Calibration", RGB(0,0,0), RGB(255,255,255), 1);
#endif
  while(getPressure() > MIN_PRESSURE){ service(); };

  //show calibration points
  for(i=0; i<3; )
  {
    //draw points
    lcd->drawCircle(lcd_points[i].x, lcd_points[i].y,  2, RGB(  0,  0,  0));
    lcd->drawCircle(lcd_points[i].x, lcd_points[i].y,  5, RGB(  0,  0,  0));
    lcd->drawCircle(lcd_points[i].x, lcd_points[i].y, 10, RGB(255,  0,  0));

    //run service routine
    service();

    //press dectected? -> save point
    if(getPressure() > MIN_PRESSURE)
    {
      lcd->fillCircle(lcd_points[i].x, lcd_points[i].y, 2, RGB(255,0,0));
      tp_points[i].x = getXraw();
      tp_points[i].y = getYraw();
      i++;

      //wait and redraw screen
      delay(100);
      lcd->fillScreen(RGB(255,255,255));
#if (defined(__AVR__) || defined(ARDUINO_ARCH_AVR))
      lcd->drawTextPGM((lcd->getWidth()/2)-50, (lcd->getHeight()/2)-10, PSTR("Calibration"), RGB(0,0,0), RGB(255,255,255), 1);
#else
      lcd->drawText((lcd->getWidth()/2)-50, (lcd->getHeight()/2)-10, "Calibration", RGB(0,0,0), RGB(255,255,255), 1);
#endif
    }
  }

  //calulate calibration matrix
  setCalibration(lcd_points, tp_points);

  //save calibration matrix
  writeCalibration(eeprom_addr);

  //wait for touch release
  while(getPressure() > MIN_PRESSURE){ service(); };

  return 1;
}*/

void ADS7846_calibrate(void)
{
	uint_least32_t x, y;

	//calc x pos
	if (tp_x != tp_last_x) {
		tp_last_x = tp_x;
		x = tp_x;
		y = tp_y;
		x = ((tp_matrix.a * x) + (tp_matrix.b * y) +
		     tp_matrix.c) / tp_matrix.div;
		if (x < 0) {
			x = 0;
		} else if (x >= LCD_WIDTH) {
			x = LCD_WIDTH - 1;
		}
		lcd_x = x;
	}
	//calc y pos
	if (tp_y != tp_last_y) {
		tp_last_y = tp_y;
		x = tp_x;
		y = tp_y;
		y = ((tp_matrix.d * x) + (tp_matrix.e * y) +
		     tp_matrix.f) / tp_matrix.div;
		if (y < 0) {
			y = 0;
		} else if (y >= LCD_HEIGHT) {
			y = LCD_HEIGHT - 1;
		}
		lcd_y = y;
	}

	return;
}

uint_least16_t ADS7846_getX(void)
{
	ADS7846_calibrate();

	switch (lcd_orientation) {
	case 0:
		return lcd_x;
	case 90:
		return lcd_y;
	case 180:
		return LCD_WIDTH - lcd_x;
	case 270:
		return LCD_HEIGHT - lcd_y;
	}

	return 0;
}

uint_least16_t ADS7846_getY(void)
{
	ADS7846_calibrate();

	switch (lcd_orientation) {
	case 0:
		return lcd_y;
	case 90:
		return LCD_WIDTH - lcd_x;
	case 180:
		return LCD_HEIGHT - lcd_y;
	case 270:
		return lcd_x;
	}

	return 0;
}

uint_least16_t ADS7846_getXraw(void)
{
	return tp_x;
}

uint_least16_t ADS7846_getYraw(void)
{
	return tp_y;
}

uint_least8_t ADS7846_getPressure(void)
{
	return pressure;
}

void ADS7846_service(void)
{
	ADS7846_rd_data();

	return;
}

//-------------------- Private --------------------

void ADS7846_rd_data(void)
{
	uint_least8_t p, a1, a2, b1, b2;
	uint_least16_t x, y;

	//SPI speed-down
#if !defined(SOFTWARE_SPI) && (defined(__AVR__) || defined(ARDUINO_ARCH_AVR))
	uint_least8_t spcr, spsr;
	spcr = SPCR;
	spsr = SPSR;
#if F_CPU >= 8000000UL
	SPI.setClockDivider(SPI_CLOCK_DIV4);
#else	/* if F_CPU >= 4000000UL */
	SPI.setClockDivider(SPI_CLOCK_DIV2);
#endif
#endif

	//get pressure
	CS_ENABLE();
	ADS7846_wr_spi(CMD_START | CMD_8BIT | CMD_Z1_POS);
	p = ADS7846_rd_spi() & 0x7F;
	CS_DISABLE();
	ADS7846_delay_ms(1);

	if (p > MIN_PRESSURE) {
		pressure = p;
		//get X data
		CS_ENABLE();
		ADS7846_wr_spi(CMD_START | CMD_8BIT | CMD_X_POS);
		tp_x = ADS7846_rd_spi();
		CS_DISABLE();
		ADS7846_delay_ms(1);
		// get y
		CS_ENABLE();
		ADS7846_wr_spi(CMD_START | CMD_8BIT | CMD_Y_POS);
		tp_y = ADS7846_rd_spi();
		CS_DISABLE();
		ADS7846_delay_ms(1);

	} else {
		pressure = 0;
	}

	//restore SPI settings
#if !defined(SOFTWARE_SPI) && (defined(__AVR__) || defined(ARDUINO_ARCH_AVR))
	SPCR = spcr;
	SPSR = spsr;
#endif

	return;
}

uint_least8_t ADS7846_rd_spi(void)
{
#if defined(SOFTWARE_SPI)
	ti_lib_ioc_pin_type_gpio_input(BOARD_IOID_SPI_MOSI);

	uint_least8_t data = 0;
	MOSI_LOW();
	for (uint_least8_t bit = 8; bit != 0; bit--) {
		ADS7846_delay_ms(1);
		SCK_HIGH();
		ADS7846_delay_ms(1);

		data <<= 1;
		if (MISO_READ()) {
			data |= 1;
		} else {
			//data |= 0;
		}
		SCK_LOW();
	}
	return data;
#else
	return SPI.transfer(0x00);
#endif
}

void ADS7846_wr_spi(uint_least8_t data)
{
#if defined(SOFTWARE_SPI)
	ti_lib_ioc_pin_type_gpio_output(BOARD_IOID_SPI_MOSI);

	for (uint_least8_t mask = 0x80; mask != 0; mask >>= 1) {
		SCK_LOW();
		if (mask & data) {
			MOSI_HIGH();
		} else {
			MOSI_LOW();
		}
		ADS7846_delay_ms(1);
		SCK_HIGH();
		ADS7846_delay_ms(1);
	}
	SCK_LOW();
	ADS7846_delay_ms(1);
	SCK_HIGH();
	ADS7846_delay_ms(1);
	SCK_LOW();
#else
	SPI.transfer(data);
#endif
	return;
}
