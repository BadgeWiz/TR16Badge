#ifndef GraphicsLib_h
#define GraphicsLib_h


#include "fonts.h"

#ifndef RGB
#define RGB(r,g,b) (((r&0xF8)<<8)|((g&0xFC)<<3)|((b&0xF8)>>3)) //RGB565: 5 red | 6 green | 5 blue
#endif

#ifndef DEC
# define DEC (10)
#endif
#ifndef HEX
# define HEX (16)
#endif
#ifndef OCT
# define OCT (8)
#endif
#ifndef BIN
# define BIN (2)
#endif


typedef struct
{
  uint32_t x;
  uint32_t y;
} CAL_POINT; //calibration points for touchpanel


typedef struct
{
  uint32_t a;
  uint32_t b;
  uint32_t c;
  uint32_t d;
  uint32_t e;
  uint32_t f;
  uint32_t div;
} CAL_MATRIX; //calibration matrix for touchpanel


    uint16_t lcd_orientation;      //display orientation/rotation
    uint16_t lcd_width, lcd_height; //screen size
    uint16_t lcd_x, lcd_y, lcd_z;   //calibrated pos (screen)
    uint16_t tp_x, tp_y;            //raw pos (touch panel)
    uint16_t tp_last_x, tp_last_y;  //last raw pos (touch panel)
    CAL_MATRIX tp_matrix;                //calibration matrix
    //GraphicsLib();
    //GraphicsLib(uint16_t w, uint16_t h);

    uint16_t getWidth(void);
    uint16_t getHeight(void);
    uint16_t width(void);
    uint16_t height(void);
    void setRotation(uint16_t r);
    uint16_t getRotation(void);
    uint16_t getOrientation(void);
    void invertDisplay(uint8_t invert);

    void setOrientation(uint16_t o);
    void setArea(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1);
    void drawStart(void);
    void draw(uint16_t color);
    void drawStop(void);

    void fillScreen(uint16_t color);
    void drawPixel(int16_t x0, int16_t y0, uint16_t color);
    void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
    void drawRect(int16_t x0, int16_t y0, int16_t w, int16_t h, uint16_t color);
    void fillRect(int16_t x0, int16_t y0, int16_t w, int16_t h, uint16_t color);
    /*
    void drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
    void fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
    void drawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t r, uint16_t color);
    void fillRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t r, uint16_t color);
    void drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
    void fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
    void drawEllipse(int16_t x0, int16_t y0, int16_t r_x, int16_t r_y, uint16_t color);
    void fillEllipse(int16_t x0, int16_t y0, int16_t r_x, int16_t r_y, uint16_t color);
*/
    int16_t drawChar(int16_t x, int16_t y, char c, uint16_t color, uint16_t bg, uint8_t size);
    int16_t drawUChar(int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg, uint8_t size);
    int16_t drawText(int16_t x, int16_t y, const char *s, uint16_t color, uint16_t bg, uint8_t size);
    //int16_t drawTextString(int16_t x, int16_t y, String &s, uint16_t color, uint16_t bg, uint8_t size);
//#if (defined(__AVR__) || defined(ARDUINO_ARCH_AVR))
//    int16_t drawTextPGM(int16_t x, int16_t y, PGM_P s, uint16_t color, uint16_t bg, uint8_t size);
//#endif
/*
    int16_t drawInteger(int16_t x, int16_t y, char val, uint8_t base, uint16_t color, uint16_t bg, uint8_t size);
    int16_t drawInteger(int16_t x, int16_t y, unsigned char val, uint8_t base, uint16_t color, uint16_t bg, uint8_t size);
    int16_t drawInteger(int16_t x, int16_t y, int val, uint8_t base, uint16_t color, uint16_t bg, uint8_t size);
    int16_t drawInteger(int16_t x, int16_t y, unsigned int val, uint8_t base, uint16_t color, uint16_t bg, uint8_t size);
    int16_t drawInteger(int16_t x, int16_t y, long val, uint8_t base, uint16_t color, uint16_t bg, uint8_t size);
    int16_t drawInteger(int16_t x, int16_t y, unsigned long val, uint8_t base, uint16_t color, uint16_t bg, uint8_t size);
*/
    //print functions
    void setCursor(int16_t x, int16_t y);
    //void setTextColor(uint16_t color);
    void setTextColor(uint16_t color, uint16_t bg);
    void setTextSize(uint8_t size);
    void setTextWrap(uint8_t wrap);
//#if ARDUINO >= 100
//    size_t write(uint8_t c);
//#else
    void write(uint8_t c);
//#endif
    //using Print::write; //pull in write(str) and write(buf, size) from Print
/*
    //touch panel funcions
    uint8_t touchRead(void);
    void touchStartCal(void);
    uint8_t touchSetCal(CAL_POINT *lcd, CAL_POINT *tp);
    void touchCal(void);
    int16_t touchX(void);
    int16_t touchY(void);
    int16_t touchZ(void);
*/

    uint8_t text_size, text_wrap;
    uint16_t text_fg, text_bg;
    int16_t text_x, text_y, start_x;



#endif //GraphicsLib_h
