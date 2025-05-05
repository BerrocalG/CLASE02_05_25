//ejercicio 1
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void){

DDRD|=0XFC; 
DDRB|=0X0F; 
ADMUX|=(1<<REFS0)|(1<<MUX1);
//ref referenciaa los 5v
//mux1 adc2 como analoga
ADCSRA|=(1<<ADEN)|(1<<ADPS2);
//aden habilita el adc
//desplaza bit a la posicion c2
char alow=0;
char ahigh=0;

while(1){
    ADCSRA|=(1<<ADSC);
    while (!(ADCSRA&(1<<ADIF))); 
    //adsc para iniciar conversion analogica
    //adif es la bandera
    alow=ADCL;//primero siempre el adcl par aque funcione bien
    //bit bajo 8 bits (0-7)  
    ahigh=ADCH;
    //bit alto 2 bits (8-9)

    //para terminar debo de valer a 0 la bandera
    ADCSRA|=(1<<ADIF);

    //PARA QUE EMPIECEN APAGADOS
    PORTB&=~0X0F;
    PORTD&=~0XFC;
    PORTD|=(alow<<2);
    PORTB|=((ahigh&0x03)<<2) |( (alow>>6)&0x03);
}
}

/*
//clase ADC
//EJERCICIO 2 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void) {
    DDRD|=0XFC; 
    DDRB|=0X0F; 
    ADMUX|=(1<<REFS0)|(1<<MUX1)|(1<<ADLAR);
    ADCSRA|=(1<<ADEN)|(1<<ADPS2);
    char alow=0;
    char ahigh=0;

    while(1){
        ADCSRA|=(1<<ADSC);
        while(!(ADCSRA&(1<<ADIF)));//conversion del adc
        alow=ADCL;//primero siempre el adcl par aque funcione bien
        ahigh=ADCH;

        //para terminar debo de valer a 0 la bandera
        ADCSRA|=(1<<ADIF);
        //PARA QUE EMPIECEN APAGADOS
       
        PORTD&=~0XFC;
        PORTB&=~0X0F;
        PORTB|=((ahigh>>4)&0x0F);
        PORTD|=((ahigh<<4) &(0xF0))|((alow>>4)&(0x0C));
    }
}


*/