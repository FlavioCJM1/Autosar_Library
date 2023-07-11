#include "stm32g0b1re.h"

int main( void )
{
    /*enable GPIOA clock*/
    RCC->IOPENR |= 0x01;
    /*Set pin 5 from port A as output*/
    GPIOA->MODER &= ~(2 << (5 << 1));
    
    for( ; ; ) /*infinite loop*/
    {
        /*toggle pin 5 where the led is conected*/
        GPIOA->ODR ^= (1 << 5);
        /*Dirty delay*/
        for( int i=0 ; i<100000 ; i++ );
    }
    return 0;
}