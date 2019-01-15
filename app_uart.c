#include <xc.h>
#include "app_uart.h"
#include "mcc_generated_files/eusart1.h"


void printf(uint8_t string[30], uint8_t new_line)
{
    uint8_t i;

    for(i=0;i<30;i++)
    {
        if((string[i] == '/') && (string[i+1] == 'n')) break;
        EUSART1_Write(string[i]);     
    }
    
    if(new_line == 1)
    {
        EUSART1_Write(13);
        EUSART1_Write(10); 
    }         
}

void printf_num(uint16_t dado)
{
    char unidade = 0, dezena = 0, centena = 0, milhar = 0;
    
    while(dado >= 1000)
    {
        dado -= 1000;
        milhar++;
    }    
    while(dado >= 100)
    {
        dado -= 100;
        centena++;
    }    
    while(dado >= 10)
    {
        dado -= 10;
        dezena++;
    }    
    while(dado > 0)
    {
        dado -= 1;
        unidade++;
    }    
      
    EUSART1_Write(milhar + '0');
    EUSART1_Write(centena + '0');
    EUSART1_Write(dezena + '0');
    EUSART1_Write(unidade + '0');
}