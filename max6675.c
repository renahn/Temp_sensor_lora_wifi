/*
 * File:   max6675.c
 * Author: renah
 *
 * Created on January 15, 2019, 7:56 PM
 */


#include <xc.h>
#include "max6675.h"
#include "mcc_generated_files/spi1.h"

#define POWER_ON    LATD1
#define CS          LATD0

void max6675_power_on(void)
{
    CS       = 1;
    POWER_ON = 1;
}


void max6675_power_off(void)
{
    CS       = 0;
    POWER_ON = 0;
}


uint16_t max6675_get_temp(void)
{
    uint8_t data, data1;
    uint16_t adc;
    float temp;
    
    CS = 0;
    data1 = SPI1_Exchange8bit(0x00);
    data = SPI1_Exchange8bit(0x00);
    CS = 1;

    adc = data1;
    adc <<= 5;
    adc |= (data>>3);

    temp = adc;
    temp *= 1023.75;
    temp /= 4095;
    
    return (uint16_t)temp;
}