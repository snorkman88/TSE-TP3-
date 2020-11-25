#include "build/temp/_test_leds.c"
#include "src/leds.h"
#include "/var/lib/gems/2.4.0/gems/ceedling-0.30.0/vendor/unity/src/unity.h"




uint16_t ledsVirtuales;





void setUp()

{

    Leds_Create(&ledsVirtuales);

}



void test_LedsOffAfterCreate()

{

    uint16_t ledsVirtuales = 0xFFFF;

    Leds_Create(&ledsVirtuales);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(17), UNITY_DISPLAY_STYLE_HEX16);

}



void test_prender_led_individual(void)

{

    Leds_On(1);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(23), UNITY_DISPLAY_STYLE_HEX16);

}



void test_apagar_led_individual(void)

{

    Leds_On(1);

    Leds_Off(1);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(30), UNITY_DISPLAY_STYLE_HEX16);

}



void test_prender_apagar_multiples(void)

{

    Leds_On(3);

    Leds_On(4);

    Leds_Off(3);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << 3)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(38), UNITY_DISPLAY_STYLE_HEX16);

}



void test_prender_todos(void)

{

    Leds_On_ALL();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFFFF)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(44), UNITY_DISPLAY_STYLE_HEX16);

}



void test_apagar_todos(void)

{

    Leds_On_ALL();

    Leds_Off_ALL();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(51), UNITY_DISPLAY_STYLE_HEX16);

}



void test_consultar_estado(void)

{

    Leds_On(3);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((4)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(57), UNITY_DISPLAY_STYLE_HEX16);

}
