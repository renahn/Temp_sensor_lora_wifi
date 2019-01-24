#include "mcc_generated_files/mcc.h"
#include "app_uart.h"
#include "max6675.h"
#include "lora.h"

#define led LATD0

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();

    uint32_t i;
    uint8_t data;
    
    
    
    while (1)
    {
        for(i=0;i<40000;i++);
        for(i=0;i<40000;i++);
        
        //lora_begin(30);    
        
        led ^= 1;
        
        if(EUSART1_is_rx_ready())
        {
            data = EUSART1_Read();
            EUSART1_Write(data);
            EUSART1_Write('H');
        } 
    }
}


