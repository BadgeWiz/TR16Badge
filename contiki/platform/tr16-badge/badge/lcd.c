#include "contiki.h"
#include "ti-lib.h"
#include "board-spi.h"
#include "spi.h"
#include "lcd.h"
#include "pwm.h"
#include <string.h>

#include "ti-lib.h"

#include "GraphicsLib.h"

#include <stdio.h>

#include "sys/clock.h"
#include "sys/rtimer.h"

#define delay_ms(i) (ti_lib_cpu_delay(8000 * (i)))	//check value of 8000 as this is stolen from the sensortag, maybe we're too low here

#define CS_DISABLE()	  ti_lib_gpio_pin_write(BOARD_LCD_CS, 1)
#define CS_ENABLE()	    ti_lib_gpio_pin_write(BOARD_LCD_CS, 0)
#define MOSI_HIGH()	    ti_lib_gpio_pin_write(BOARD_SPI_MOSI, 1)
#define MOSI_LOW()	    ti_lib_gpio_pin_write(BOARD_SPI_MOSI, 0)
#define SCK_HIGH()	    ti_lib_gpio_pin_write(BOARD_SPI_SCK, 1)
#define SCK_LOW()	      ti_lib_gpio_pin_write(BOARD_SPI_SCK, 0)
#define LED_ENABLE()	  ti_lib_gpio_pin_write(BOARD_LCD_BL, 0)
#define LED_DISABLE()	  ti_lib_gpio_pin_write(BOARD_LCD_BL, 1)
#define LCD_PWRON()	    ti_lib_gpio_pin_write(BOARD_LCD_BL_PWR_ON, 1)
#define LCD_PWROFF()    ti_lib_gpio_pin_write(BOARD_LCD_BL_PWR_ON, 0)
#define DC_LOW()	  ti_lib_gpio_pin_write(BOARD_TOUCH_BUSY, 0)
#define DC_HIGH()	  ti_lib_gpio_pin_write(BOARD_TOUCH_BUSY, 1)

#define LCD_WIDTH	320
#define LCD_HEIGHT	240

//LCD commands
#define LCD_CMD_NOP                    0x00
#define LCD_CMD_RESET                  0x01
#define LCD_CMD_SLEEPIN                0x10
#define LCD_CMD_SLEEPOUT               0x11
#define LCD_CMD_PARTIAL_MODE           0x12
#define LCD_CMD_NORMAL_MODE            0x13
#define LCD_CMD_INV_OFF                0x20
#define LCD_CMD_INV_ON                 0x21
#define LCD_CMD_GAMMA                  0x26
#define LCD_CMD_DISPLAY_OFF            0x28
#define LCD_CMD_DISPLAY_ON             0x29
#define LCD_CMD_COLUMN                 0x2A
#define LCD_CMD_PAGE                   0x2B
#define LCD_CMD_WRITE                  0x2C
#define LCD_CMD_READ                   0x2E
#define LCD_CMD_PARTIAL_AREA           0x30
#define LCD_CMD_VSCROLL_DEF            0x33
#define LCD_CMD_TEARING_OFF            0x34
#define LCD_CMD_TEARING_ON             0x35
#define LCD_CMD_MEMACCESS_CTRL         0x36
#define LCD_CMD_VSCROLL_START          0x36
#define LCD_CMD_IDLE_OFF               0x38
#define LCD_CMD_IDLE_ON                0x39
#define LCD_CMD_PIXEL_FORMAT           0x3A
#define LCD_CMD_WRITE_CNT              0x3C
#define LCD_CMD_READ_CNT               0x3E
#define LCD_CMD_BRIGHTNESS             0x51
#define LCD_CMD_BRIGHTNESS_CTRL        0x53
#define LCD_CMD_RGB_CTRL               0xB0
#define LCD_CMD_FRAME_CTRL             0xB1	//normal mode
#define LCD_CMD_FRAME_CTRL_IDLE        0xB2	//idle mode
#define LCD_CMD_FRAME_CTRL_PART        0xB3	//partial mode
#define LCD_CMD_INV_CTRL               0xB4
#define LCD_CMD_DISPLAY_CTRL           0xB6
#define LCD_CMD_ENTRY_MODE             0xB7
#define LCD_CMD_POWER_CTRL1            0xC0
#define LCD_CMD_POWER_CTRL2            0xC1
#define LCD_CMD_VCOM_CTRL1             0xC5
#define LCD_CMD_VCOM_CTRL2             0xC7
#define LCD_CMD_POWER_CTRLA            0xCB
#define LCD_CMD_POWER_CTRLB            0xCF
#define LCD_CMD_POS_GAMMA              0xE0
#define LCD_CMD_NEG_GAMMA              0xE1
#define LCD_CMD_DRV_TIMING_CTRLA       0xE8
#define LCD_CMD_DRV_TIMING_CTRLB       0xEA
#define LCD_CMD_POWERON_SEQ_CTRL       0xED
#define LCD_CMD_ENABLE_3G              0xF2
#define LCD_CMD_INTERF_CTRL            0xF6
#define LCD_CMD_PUMP_RATIO_CTRL        0xF7

//TEST CS
#define READ_DISPLAY_PIXEL_FORMAT   0x0C
#define SLEEP_OUT                   0x11
#define INVERSIONOFF_REG            0x20
#define INVERSIONON_REG             0x21
#define GAMMA_SET                   0x26
#define DISPLAY_OFF                 0x28
#define DISPLAY_ON                  0x29
#define SET_COLUMN_ADDRESS          0x2A
#define SET_PAGE_ADDRESS            0x2B
#define WRITE_MEMORY                0x2C
#define READ_MEMORY                 0x2E
#define MEMORY_ACCESS_CONTROL       0x36
#define WRITE_MEMORY_CONTINUE       0x3C
#define READ_MEMORY_CONTINUE        0x3E
#define PIXEL_FORMAT_SET            0x3A
#define FRAME_RATE_CONTROL          0xB1
#define DISPLAY_FUNCTION_CONTROL    0xB6
#define POWER_CONTROL_1             0xC0
#define POWER_CONTROL_2             0xC1
#define VCOM_CONTROL_1              0xC5
#define VCOM_CONTROL_2              0xC7
#define POWER_CONTROL_A             0xCB
#define POWER_CONTROL_B             0xCF
#define POSITIVE_GAMMA_CORRECTION   0xE0
#define NEGATIVE_GAMMA_CORRECTION   0xE1
#define DRIVER_TIMING_CONTROL_A     0xE8
#define DRIVER_TIMING_CONTROL_B     0xEA
#define POWER_ON_SEQUENCE_CONTROL   0xED
#define UNDOCUMENTED_0xEF           0xEF
#define ENABLE_3G                   0xF2
#define INTERFACE_CONTROL           0xF6

//initialize pins
void begin()
{
	//printf("initializing pins...\n");

	ti_lib_ioc_pin_type_gpio_output(BOARD_IOID_LCD_CS);
	ti_lib_ioc_pin_type_gpio_output(BOARD_IOID_SPI_MOSI);
	ti_lib_ioc_pin_type_gpio_output(BOARD_IOID_SPI_SCK);
	ti_lib_ioc_pin_type_gpio_output(BOARD_IOID_LCD_BL);
	ti_lib_ioc_pin_type_gpio_output(BOARD_IOID_LCD_BL_PWR_ON);

	ti_lib_ioc_pin_type_gpio_output(BOARD_IOID_TOUCH_BUSY);

	LCD_PWROFF();

	LED_DISABLE();

	CS_DISABLE();

	return;
}

//backlight control
void led(int power)
{
	//LCD_PWRON();
	//LED_ENABLE();

	if (power == 0)		//off
	{
		LED_DISABLE();
		LCD_PWROFF();
		pwm_stop();
	} else if (power >= 100)	//100%
	{
		LED_ENABLE();
		LCD_PWRON();
	} else			//1...99%
	{
		LCD_PWRON();
		pwm_start(power);
	}

	return;
}

void invertDisplay(uint8_t invert)
{
	if (invert == 0) {
		wr_cmd(LCD_CMD_INV_OFF);
	} else {
		wr_cmd(LCD_CMD_INV_ON);
	}

	return;
}

void setOrientation(uint16_t o)
{
	uint8_t p;
	uint16_t lcd_width;
	uint16_t lcd_height;
	uint16_t lcd_orientation;

#define MEM_Y   (7)		//MY row address order
#define MEM_X   (6)		//MX column address order
#define MEM_V   (5)		//MV row / column exchange
#define MEM_L   (4)		//ML vertical refresh order
#define MEM_H   (2)		//MH horizontal refresh order
#define MEM_BGR (3)		//RGB-BGR Order

	if ((o == 9) || (o == 90)) {
		lcd_orientation = 90;
		lcd_width = LCD_HEIGHT;
		lcd_height = LCD_WIDTH;
		p = (1 << MEM_BGR) | (1 << MEM_X);
	}

	else if ((o == 18) || (o == 180)) {
		lcd_orientation = 180;
		lcd_width = LCD_WIDTH;
		lcd_height = LCD_HEIGHT;
		p = (1 << MEM_BGR) | (1 << MEM_L) | (1 << MEM_V);
	}

	else if ((o == 27) || (o == 14) || (o == 270)) {
		lcd_orientation = 270;
		lcd_width = LCD_HEIGHT;
		lcd_height = LCD_WIDTH;
		p = (1 << MEM_BGR) | (1 << MEM_Y);
	}

	else {
		lcd_orientation = 0;
		lcd_width = LCD_WIDTH;
		lcd_height = LCD_HEIGHT;
		p = (1 << MEM_BGR) | (1 << MEM_X) | (1 << MEM_Y) | (1 << MEM_V);
	}

	wr_cmd(LCD_CMD_MEMACCESS_CTRL);
	wr_data_byte(p);

	setArea(0, 0, lcd_width - 1, lcd_height - 1);

	return;
}

void drawStart(void)
{
	wr_cmd(LCD_CMD_WRITE);
	CS_ENABLE();

	return;
}

void draw(uint16_t color)
{
	uint8_t _16bitData[] = { (color >> 8), (color & 0xff) };
	DC_HIGH();
	board_spi_write(_16bitData, sizeof(_16bitData));

	return;
}

void wr_data16(uint16_t data)
{
	uint8_t _16bitData[] = { (data >> 8), (data & 0xff) };
	DC_HIGH();
	board_spi_write(_16bitData, sizeof(_16bitData));

	return;
}

void wr_data16b(uint8_t a, uint8_t b)
{
	uint8_t _16bitData[] = { a, b };
	CS_ENABLE();
	DC_HIGH();
	board_spi_write(_16bitData, 2);
	CS_DISABLE();

	return;
}

void drawStop(void)
{
	CS_DISABLE();

	return;
}

void setArea(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
{
	wr_cmd(LCD_CMD_COLUMN);

	wr_data16b(x0 >> 8, x0 & 0xff);
	wr_data16b(x1 >> 8, x1 & 0xff);

	// wr_data16b(0, x1 >> 8);
	// wr_data16b(0, x1 & 0xff);
	// wr_data16b(0, x0 >> 8);
	// wr_data16b(0, x0 & 0xff);
	// wr_data_byte(0);
	// wr_data_byte((x0 >> 8) & 0xff);
	// wr_data_byte(0);
	// wr_data_byte(x0 & 0xff);
	// wr_data_byte(0);
	// wr_data_byte((x1 >> 8) & 0xff);
	// wr_data_byte(0);
	// wr_data_byte(x1 & 0xff);
	// wr_data16(y0 >> 8);
	// wr_data16(y0 & 0xff);
	// wr_data16(y1 >> 8);
	// wr_data16(y1 & 0xff);

	wr_cmd(LCD_CMD_PAGE);
	// wr_data16(x0);
	// wr_data16(x1);

	// wr_data_byte(0);
	// wr_data_byte((y0 >> 8) & 0xff);
	// wr_data_byte(0);
	// wr_data_byte(y0 & 0xff);
	// wr_data_byte(0);
	// wr_data_byte((y1 >> 8) & 0xff);
	// wr_data_byte(0);
	// wr_data_byte(y1 & 0xff);

	// wr_data16b(0, y1 >> 8);
	// wr_data16b(0, y1 & 0xff);
	// wr_data16b(0, y0 >> 8);
	// wr_data16b(0, y0 & 0xff);

	wr_data16b(y0 >> 8, y0 & 0xff);
	wr_data16b(y1 >> 8, y1 & 0xff);
	return;
}

void lcdInit(void)
{
	// TEST CS

	board_spi_open(10000000, BOARD_IOID_SPI_SCK);	//initialize SPI with bit rate and clock pin

	wr_cmd(LCD_CMD_RESET);	// sw reset
	clock_delay_usec(5000);
	wr_cmd(LCD_CMD_DISPLAY_OFF);	//display off

	wr_cmd(0xCB);
	wr_data_byte(0x39);
	wr_data_byte(0x2C);
	wr_data_byte(0x00);
	wr_data_byte(0x34);
	wr_data_byte(0x02);

	wr_cmd(0xCF);
	wr_data_byte(0x00);
	wr_data_byte(0XC1);
	wr_data_byte(0X30);

	wr_cmd(0xE8);
	wr_data_byte(0x85);
	wr_data_byte(0x00);
	wr_data_byte(0x78);

	wr_cmd(0xEA);
	wr_data_byte(0x00);
	wr_data_byte(0x00);

	wr_cmd(0xED);
	wr_data_byte(0x64);
	wr_data_byte(0x03);
	wr_data_byte(0X12);
	wr_data_byte(0X81);

	wr_cmd(0xF7);
	wr_data_byte(0x20);

	wr_cmd(0xC0);		//Power control
	wr_data_byte(0x23);	//VRH[5:0]

	wr_cmd(0xC1);		//Power control
	wr_data_byte(0x10);	//SAP[2:0];BT[3:0]

	wr_cmd(0xC5);		//VCM control
	wr_data_byte(0x3e);
	wr_data_byte(0x28);

	wr_cmd(0xC7);		//VCM control2
	wr_data_byte(0x86);

	wr_cmd(0x36);		// Memory Access Control
	wr_data_byte(0x48);	//C8

	wr_cmd(0x3A);
	wr_data_byte(0x55);

	wr_cmd(0xB1);
	wr_data_byte(0x00);
	wr_data_byte(0x18);

	wr_cmd(0xB6);		// Display Function Control
	wr_data_byte(0x08);
	wr_data_byte(0x82);
	wr_data_byte(0x27);

	wr_cmd(0xF2);		// 3Gamma Function Disable
	wr_data_byte(0x00);

	wr_cmd(0x26);		//Gamma curve selected
	wr_data_byte(0x01);

	wr_cmd(0xE0);		//Set Gamma
	wr_data_byte(0x0F);
	wr_data_byte(0x31);
	wr_data_byte(0x2B);
	wr_data_byte(0x0C);
	wr_data_byte(0x0E);
	wr_data_byte(0x08);
	wr_data_byte(0x4E);
	wr_data_byte(0xF1);
	wr_data_byte(0x37);
	wr_data_byte(0x07);
	wr_data_byte(0x10);
	wr_data_byte(0x03);
	wr_data_byte(0x0E);
	wr_data_byte(0x09);
	wr_data_byte(0x00);

	wr_cmd(0XE1);		//Set Gamma
	wr_data_byte(0x00);
	wr_data_byte(0x0E);
	wr_data_byte(0x14);
	wr_data_byte(0x03);
	wr_data_byte(0x11);
	wr_data_byte(0x07);
	wr_data_byte(0x31);
	wr_data_byte(0xC1);
	wr_data_byte(0x48);
	wr_data_byte(0x08);
	wr_data_byte(0x0F);
	wr_data_byte(0x0C);
	wr_data_byte(0x31);
	wr_data_byte(0x36);
	wr_data_byte(0x0F);

	wr_cmd(0x11);		//Exit Sleep
	clock_delay_usec(60000);

	wr_cmd(0x29);		//Display on
	wr_cmd(0x2c);
	setOrientation(0);
	CS_DISABLE();
}

/*
void lcdInit (void)
{
  //printf("starting init...\n");
  uint8_t data1[] = {0x00, 0x83, 0x30};
  uint8_t data2[] = {0x64, 0x03, 0x12, 0x81};
  uint8_t data3[] = {0x85, 0x01, 0x79};
  uint8_t data4[] = {0x39, 0x2C, 0x00, 0x34, 0x02};
  uint8_t data5[] = {0x20};
  uint8_t data6[] = {0x00, 0x00};
  uint8_t data7[] = {0x26};
  uint8_t data8[] = {0x11};
  uint8_t data9[] = {0x35, 0x3E};
  uint8_t data10[] = {0xBE};
  uint8_t data11[] = {0x00, 0x1B};
  uint8_t data12[] = {0x08};
  uint8_t data13[] = {0x01};
  uint8_t data14[] = {0x1F, 0x1A, 0x18, 0x0A, 0x0F, 0x06, 0x45, 0x87, 0x32, 0x0A, 0x07, 0x02, 0x07, 0x05, 0x00};
  uint8_t data15[] = {0x00, 0x25, 0x27, 0x05, 0x10, 0x09, 0x3A, 0x78, 0x4D, 0x05, 0x18, 0x0D, 0x38, 0x3A, 0x1F};
  uint8_t data16[] = {0x0A, 0x82, 0x27, 0x00};
  uint8_t data17[] = {0x07};
  uint8_t data18[] = {0x55};
  uint8_t data19[] = {(1<<MEM_BGR) | (1<<MEM_X) | (1<<MEM_Y) | (1<<MEM_V)};       //CHECK!!!
  uint8_t data20[] = {0x00, 0x00};
  //uint8_t data21[] = {((LCD_WIDTH-1)>>8)&0xFF, (LCD_WIDTH-1)&0xFF};
  uint8_t data21[] = {0x01, 0xEF};
  uint8_t data22[] = {0x00, 0x00};
  //uint8_t data23[] = {((LCD_HEIGHT-1)>>8)&0xFF, (LCD_HEIGHT-1)&0xFF};
  uint8_t data23[] = {0x00, 0xEF};

  //printf("spi open\n");

  board_spi_open(10000000, BOARD_IOID_SPI_SCK);		//initialize SPI with bit rate and clock pin

  //send init commands and data
  wr_cmd(LCD_CMD_RESET);  // sw reset
  clock_delay_usec(5000);
  wr_cmd(LCD_CMD_DISPLAY_OFF);  //display off

  clock_delay_usec(20000);;  //wait 20ms => CS why? not in spec
  wr_cmd(LCD_CMD_POWER_CTRLB);
  wr_data(data1, sizeof(data1));
  wr_cmd(LCD_CMD_POWERON_SEQ_CTRL);
  wr_data(data2, sizeof(data2));
  wr_cmd(LCD_CMD_DRV_TIMING_CTRLA);
  wr_data(data3, sizeof(data3));
  wr_cmd(LCD_CMD_POWER_CTRLA);
  wr_data(data4, sizeof(data4));
  wr_cmd(LCD_CMD_PUMP_RATIO_CTRL);
  wr_data(data5, sizeof(data5));
  wr_cmd(LCD_CMD_DRV_TIMING_CTRLB);
  wr_data(data6, sizeof(data6));
  wr_cmd(LCD_CMD_POWER_CTRL1);
  wr_data(data7, sizeof(data7));
  wr_cmd(LCD_CMD_POWER_CTRL2);
  wr_data(data8, sizeof(data8));
  wr_cmd(LCD_CMD_VCOM_CTRL1);
  wr_data(data9, sizeof(data9));
  wr_cmd(LCD_CMD_VCOM_CTRL2);
  wr_data(data10, sizeof(data10));
  wr_cmd(LCD_CMD_FRAME_CTRL);
  wr_data(data11, sizeof(data11));
  wr_cmd(LCD_CMD_ENABLE_3G);
  wr_data(data12, sizeof(data12));
  wr_cmd(LCD_CMD_GAMMA);
  wr_data(data13, sizeof(data13));
  wr_cmd(LCD_CMD_POS_GAMMA);
  wr_data(data14, sizeof(data14));
  wr_cmd(LCD_CMD_NEG_GAMMA);
  wr_data(data15, sizeof(data15));
  wr_cmd(LCD_CMD_DISPLAY_CTRL);
  wr_data(data16, sizeof(data16));
  wr_cmd(LCD_CMD_ENTRY_MODE);
  wr_data(data17, sizeof(data17));
  wr_cmd(LCD_CMD_PIXEL_FORMAT);
  wr_data(data18, sizeof(data18));
  wr_cmd(LCD_CMD_MEMACCESS_CTRL);       //CHECK!!!
  wr_data(data19, sizeof(data19));      //CHECK!!!
  wr_cmd(LCD_CMD_COLUMN);
  wr_data(data20, sizeof(data20));
  wr_data(data21, sizeof(data21));
  wr_cmd(LCD_CMD_PAGE);
  wr_data(data22, sizeof(data22));
  wr_data(data23, sizeof(data23));
  wr_cmd(LCD_CMD_SLEEPOUT);
  clock_delay_usec(60000);
  clock_delay_usec(60000);
  wr_cmd(LCD_CMD_DISPLAY_ON);
  clock_delay_usec(20000);;

  setOrientation(0);
}
*/

void wr_cmd(uint8_t cmd)
{
	CS_ENABLE();
	DC_LOW();
	board_spi_write_byte(cmd);

	CS_DISABLE();
	return;
}

void wr_data(uint8_t * data, size_t len)
{
	CS_ENABLE();
	DC_HIGH();
	board_spi_write(data, len);

	CS_DISABLE();
	return;
}

void wr_data_byte(uint8_t data)
{
	CS_ENABLE();
	DC_HIGH();
	board_spi_write_byte(data);
	CS_DISABLE();
	return;
}

void showContent(uint16_t fgColor, uint16_t bgColor)
{
	ti_lib_gpio_pin_toggle(BOARD_IOID_LCD_RST);
	setArea(0, 0, lcd_width - 1, lcd_height - 1);

	drawStart();
	for (uint32_t i = 0; i < 6400; i++) {
		draw(bgColor);
	}
	for (uint32_t i = 6401; i < 32001; i++) {
		draw(fgColor);
	}
	for (uint32_t i = 32001; i < 44801; i++) {
		draw(bgColor);
	}
	for (uint32_t i = 44801; i < 70401; i++) {
		draw(fgColor);
	}
	for (uint32_t i = 74001; i < 80419; i++) {
		draw(bgColor);
	}
	drawStop();

	return;
}

void vscroll()
{
	wr_cmd(LCD_CMD_VSCROLL_START);
	wr_data16b(0, 50);
}

void vscrollInit()
{
	wr_cmd(LCD_CMD_VSCROLL_DEF);
	// TFA
	wr_data16b(0, 0);

	// VSA
	wr_data16b(0, 400);

	// BFA
	wr_data16b(0, 0);
}

/**
 * displays a text at the specified position
 * if x or y contains a negative value, the horizontal/vertical position is centered
 */
void displayText(int16_t x, int16_t y, const char *str)
{
	uint8_t strLen = strlen(str);
	uint8_t cols = lcd_width / ((text_size & 0x7F) * FONT_WIDTH);
	uint8_t rows = lcd_height / ((text_size & 0x7F) * FONT_HEIGHT);

	// center horizontally
	if (x < 0) {
		x = 10;		// default offset
		if (strLen < cols) {
			x = (lcd_width - 20 -
			     strLen * ((text_size & 0x7F) * FONT_WIDTH)) / 2;
		}
	}
	// center vertically
	if (y < 0) {
		y = 10;		// default offset
		if (text_wrap) {
			if (strLen / cols < rows) {
				y = (lcd_height - 20 -
				     (strLen / cols) * ((text_size & 0x7F) *
							FONT_HEIGHT)) / 2;
			}
		} else {
			y = (lcd_height - 20 -
			     ((text_size & 0x7F) * FONT_HEIGHT)) / 2;
		}
	}

	setCursor(x, y);
	while (*str) {
		write(*str);
		str++;
	}
}

void printCentered(uint16_t y, const char *str, uint8_t size)
{
	uint8_t charCnt = lcd_width / ((size & 0x7F) * FONT_WIDTH);
	uint8_t strLen = strlen(str);
	uint8_t x = 10;
	if (strLen < charCnt) {
		x = (lcd_width - 20 -
		     strLen * ((size & 0x7F) * FONT_WIDTH)) / 2;
	}

	setCursor(x, y);
	setTextSize(size);
	while (*str) {
		write(*str);
		str++;
		if (text_y > y) {
			y = text_y;
			strLen -= charCnt;
			if (strLen < charCnt) {
				x = (lcd_width - 20 -
				     strLen * ((size & 0x7F) * FONT_WIDTH)) / 2;

				setCursor(x, y);
			}
		}
	}
}

const char *currentScrollingText[] = {
	0, 0, 0, 0, 0,
	0, 0, 0, 0
};

const char *currentScrollingTextPosition[] = {
	0, 0, 0, 0, 0,
	0, 0, 0, 0
};

int16_t currentScrollingTextLine[] = {
	0, 0, 0, 0, 0,
	0, 0, 0, 0
};

void displayScrollingText(uint8_t idx, int16_t y, const char *str)
{
	if (idx > 8)
		return;

	if (str) {
		// center vertically
		if (y < 0) {
			y = (lcd_height - 20 -
			     ((text_size & 0x7F) * FONT_HEIGHT)) / 2;
		}

		currentScrollingTextLine[idx] = y;
		currentScrollingText[idx] = str;
		currentScrollingTextPosition[idx] = str - 1;
	} else if (currentScrollingText[idx]) {
		uint8_t oldwrap = text_wrap;
		setTextWrap(0);
		// add offset on text start
		if (currentScrollingTextPosition[idx] <
		    currentScrollingText[idx]) {
			displayText(0, currentScrollingTextLine[idx],
				    currentScrollingText[idx]);
		} else {
			displayText(0, currentScrollingTextLine[idx],
				    currentScrollingTextPosition[idx]);
		}
		setTextWrap(oldwrap);
		currentScrollingTextPosition[idx]++;
		if (currentScrollingTextPosition[idx] >=
		    currentScrollingText[idx]) {
			if (!*currentScrollingTextPosition[idx]
			    || ((strlen(currentScrollingTextPosition[idx]) + 1)
				* ((text_size & 0x7F) * FONT_WIDTH)) <
			    lcd_width) {
				currentScrollingTextPosition[idx] =
				    currentScrollingText[idx] - 1;
			}
		}
	}
}

void disableScrollingText(uint8_t idx)
{
	currentScrollingText[idx] = 0;
	currentScrollingTextPosition[idx] = 0;
	currentScrollingTextLine[idx] = 0;
}
