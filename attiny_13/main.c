#include <avr/io.h>
#include <util/delay.h>
#define LED PB3
#define BUTTON PB4

void blink(uint8_t b); // blink sequence function

int main(void){
	DDRB |= 1<<LED; // led pin as output
	PORTB |= 1<<BUTTON; // button pin input pullup
	TCCR0B |= 1<<CS00;
	int repeatCount = 0;

	while(1){
if( TCNT0>251){ // if button pushed call blink function
//	TCNT0 = 0;
	repeatCount++;

	if(repeatCount>8000){
		PORTB ^= 1<<LED;
		repeatCount = 0;
		}

		}
	}
}


