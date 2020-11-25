#include <stdint.h>

#define LEDS_ALL_ON 0xFFFF
#define LEDS_ALL_OFF 0x0000

void Leds_Create(uint16_t *puerto);
void Leds_On(uint8_t led);
void Leds_Off(uint8_t led);
void Leds_On_ALL(void);
void Leds_Off_ALL(void);
uint8_t estado_led(uint8_t led);
