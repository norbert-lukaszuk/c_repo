#include <avr/io.h>
#include <util/delay.h>
#define LED PB3
#define BUTTON PB4

int main(void){
	DDRB |= 1<<LED; // led pin as output
	PORTB |= 1<<BUTTON; // button pin input pullup
	TCCR0B |= 1<<CS00;
	TCCR0B |= 1<<CS02;

	int repeatCount = 0;

	while(1){
if( TCNT0>250){ // if button pushed call blink function
	TCNT0 = 0;
	repeatCount++;
//	PORTB ^= 1<<LED;

	if(repeatCount>32){
		PORTB ^= 1<<LED;
		repeatCount = 0;
		}

		}
	}
}


