#ifndef MAX6675_H
#define	MAX6675_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>

void max6675_power_on(void);
void max6675_power_off(void);
uint16_t max6675_get_temp(void);


#endif	/* XC_HEADER_TEMPLATE_H */