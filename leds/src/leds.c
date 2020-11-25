#include "leds.h"

static uint16_t * direccion;

uint16_t LedToMask(uint8_t led)
{
    if(led > 16)
    {
        return 0;
    }
    return (1 << (led-1));
}

void Leds_Create(uint16_t *puerto)
{
    direccion = puerto;
    *direccion = LEDS_ALL_OFF;
}

void Leds_On(uint8_t led)
{
    *direccion |= LedToMask(led);
}

void Leds_Off(uint8_t led)
{
    *direccion &= ~LedToMask(led);
}

void Leds_On_ALL(void)
{
    *direccion = LEDS_ALL_ON;
}

void Leds_Off_ALL(void)
{
    *direccion = LEDS_ALL_OFF;
}

uint8_t estado_led(uint8_t led)
{
    return (*direccion>>(led - 1)) & 1;   
}
