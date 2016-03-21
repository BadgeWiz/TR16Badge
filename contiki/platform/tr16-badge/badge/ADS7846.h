#ifndef ADS7846_h
#define ADS7846_h


#include <inttypes.h>
#include "GraphicsLib.h"

//#define ADS7846_delay_ms(i) (ti_lib_cpu_delay(8000 * (i)))

#define ADS7846_delay_ms(i) (ti_lib_cpu_delay(10 * (i)))

//#include "MI0283QT2.h"
//#include "MI0283QT9.h"


/*typedef struct
{
  uint_least32_t x;
  uint_least32_t y;
} CAL_POINT; //calibration points for touchpanel


typedef struct
{
  uint_least32_t a;
  uint_least32_t b;
  uint_least32_t c;
  uint_least32_t d;
  uint_least32_t e;
  uint_least32_t f;
  uint_least32_t div;
} CAL_MATRIX; //calibration matrix for touchpanel
*/

    uint_least16_t lcd_orientation;      //lcd_orientation
    uint_least16_t lcd_x, lcd_y;         //calibrated pos (screen)
    uint_least16_t tp_x, tp_y;           //raw pos (touch panel)
    uint_least16_t tp_last_x, tp_last_y; //last raw pos (touch panel)
    CAL_MATRIX tp_matrix;                //calibrate matrix
    uint_least8_t pressure;              //touch panel pressure

    void ADS7846_begin(void);
    void ADS7846_setOrientation(uint_least16_t o);
    void ADS7846_setRotation(uint_least16_t r);
    uint_least8_t ADS7846_setCalibration(CAL_POINT *lcd, CAL_POINT *tp);
    uint_least8_t ADS7846_writeCalibration(uint16_t eeprom_addr);
    uint_least8_t ADS7846_readCalibration(uint16_t eeprom_addr);
    //uint_least8_t doCalibration(MI0283QT2 *lcd, uint16_t eeprom_addr, uint_least8_t check_eeprom); //example touch panel calibration routine
    //uint_least8_t doCalibration(MI0283QT9 *lcd, uint16_t eeprom_addr, uint_least8_t check_eeprom); //example touch panel calibration routine
    void ADS7846_calibrate(void);
    uint_least16_t ADS7846_getX(void);
    uint_least16_t ADS7846_getY(void);
    uint_least16_t ADS7846_getXraw(void);
    uint_least16_t ADS7846_getYraw(void);
    uint_least8_t ADS7846_getPressure(void);
    void ADS7846_service(void);


    void ADS7846_rd_data(void);
    uint_least8_t ADS7846_rd_spi(void);
    void ADS7846_wr_spi(uint_least8_t data);


#endif //ADS7846_h
