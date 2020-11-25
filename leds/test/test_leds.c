#include "unity.h"
#include "leds.h"


uint16_t ledsVirtuales;


void setUp()
{
    Leds_Create(&ledsVirtuales);
}

void test_LedsOffAfterCreate()
{
    uint16_t ledsVirtuales = 0xFFFF;
    Leds_Create(&ledsVirtuales);
    TEST_ASSERT_EQUAL_HEX16(0, ledsVirtuales);
}

void test_prender_led_individual(void)
{
    Leds_On(1);
    TEST_ASSERT_EQUAL_HEX16(1, ledsVirtuales);
}

void test_apagar_led_individual(void)
{
    Leds_On(1);
    Leds_Off(1);
    TEST_ASSERT_EQUAL_HEX16(0, ledsVirtuales);
}

void test_prender_apagar_multiples(void)
{
    Leds_On(3);
    Leds_On(4);
    Leds_Off(3);
    TEST_ASSERT_EQUAL_HEX16(1 << 3, ledsVirtuales);
}

void test_prender_todos(void)
{
    Leds_On_ALL();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, ledsVirtuales);
}

void test_apagar_todos(void)
{
    Leds_On_ALL();
    Leds_Off_ALL();
    TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuales);
}

void test_consultar_estado(void)
{
    Leds_On(3);
    TEST_ASSERT_EQUAL_HEX16(4, ledsVirtuales);
}
