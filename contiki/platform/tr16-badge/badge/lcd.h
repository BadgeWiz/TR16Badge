#include "GraphicsLib.h"

void wr_data16(uint16_t data);

void setArea(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);

void invertDisplay(uint8_t invert);
void wr_cmd(uint8_t cmd);
void wr_data(uint8_t *data, size_t len);
void wr_data_byte(uint8_t data);
void lcdInit(void);
void begin();
void led(int power);
void drawStart(void);
void draw(uint_least16_t color);
void drawStop(void);
void setOrientation(uint16_t o);


void showContent(uint16_t fgColor, uint16_t bgColor);

void vscrollInit();
void vscroll();

void displayText(int16_t x, int16_t y, const char* str);
void displayScrollingText(uint8_t idx, int16_t y, const char* str);
void disableScrollingText(uint8_t idx);
