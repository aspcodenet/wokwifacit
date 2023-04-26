#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b)))) 

// B (digital pin 8 to 13)
// C (analog input pins)
// D (digital pins 0 to 7)


//if (PIND & (1<<PD2)) 
//Blinka #13 = interna lampan på Uno
//Dvs pin 5 på port B
//https://www.arduino.cc/en/Reference/PortManipulation
//
void internalLed()
{
	DDRB |= (1 << 0) | (1 << 1) | (1 << 2);
	BIT_CLEAR(DDRD, 6);
	BIT_SET(PORTD, 6); //This means INPUT_PULLUP
	// https://forum.arduino.cc/t/using-avr-internal-pull-up-for-push-button-controlling/327729/4
	// https://www.hackster.io/Hack-star-Arduino/push-buttons-and-arduino-a-simple-guide-wokwi-simulator-c2281f

	while (1)
	{
		if(BIT_CHECK(PIND,6))
		{
			BIT_SET(PORTB, 2);
			BIT_CLEAR(PORTB, 1);
			BIT_CLEAR(PORTB, 0);
		}
		else {
		BIT_CLEAR(PORTB, 2);
		BIT_SET(PORTB, 1);
		BIT_CLEAR(PORTB, 0);

		}
		_delay_ms(100);
	}

}



//Blinka pin 7 (PORT D)
int main(void)
{
	internalLed();
	return 0;
}