#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b)))) 


//SETUP https://wokwi.com/projects/363071204090063873

// B (digital pin 8 to 13)
// C (analog input pins)
// D (digital pins 0 to 7)
#define LED_PIN 2

int main(void)
{
    BIT_SET(DDRB, LED_PIN);
    while(1){
        BIT_SET(PORTB, LED_PIN);
		_delay_ms(3000);
        BIT_CLEAR(PORTB, LED_PIN);
		_delay_ms(3000);
    }
	return 0;
}