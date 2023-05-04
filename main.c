#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "lcd.h"

#define BIT_SET(a, b) ((a) |= (1ULL << (b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b)))) 

// B (digital pin 8 to 13)
// C (analog input pins)
// D (digital pins 0 to 7)
// https://wokwi.com/projects/363070419462614017

#define RED 2
#define YELLOW 1
#define GREEN 0

int main(void)
{

  lcd_init();
  lcd_enable_blinking();
  lcd_enable_cursor();
  lcd_puts("Hej");

  	// https://forum.arduino.cc/t/using-avr-internal-pull-up-for-push-button-controlling/327729/4
	// https://www.hackster.io/Hack-star-Arduino/push-buttons-and-arduino-a-simple-guide-wokwi-simulator-c2281f


    while(1) {
     
   }
	return 0;
}