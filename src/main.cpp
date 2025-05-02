//clase ADC
//EJERCICIO 1 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>



int main(void) {
    DDRD|=0X0C; 
    DDRD|=0XF0; 
    DDRB|=0X0F; 

    while(1){
        PORTB|=0X0F;
        PORTD|=0XFC;
        _delay_ms(500);
        PORTB&=~0X0F;
        PORTD&=~0XFC;
        _delay_ms(500);
    }
}
