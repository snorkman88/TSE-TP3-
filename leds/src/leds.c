#include "leds.h"

#define LEDS_ALL_ON 0xFFFF
#define LEDS_ALL_OFF 0x0000
#define LED_OFFSET 1
#define MAX_LED_NUMBER 16
#define LedToMask(led) (1 << (led-LED_OFFSET))


static uint16_t * direccion;

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
    return (*direccion>>(led - LED_OFFSET)) & 1;

}
