#include <avr/io.h>
#include <util/delay.h>
#define LED PB3
#define BUTTON PB4

uint8_t repeatCount;
void toggle_led(void);
int main(void){
	sei();
	DDRB |= 1<<LED; // led pin as output
	PORTB |= 1<<BUTTON; // button pin input pull up
	TCCR0B |= 1<<CS00 | 1<<CS02 ; //set timer prescaler for 1024
	TCCR0A |= 1<<WGM01;
	OCR0A = 250;
	TIMSK0 |= 1<<OCIE0A;



	while(1){
//if( TCNT0>250){ // if button pushed call blink function
//	TCNT0 = 0;
//	repeatCount++;
//
//
//	if(repeatCount>38){
//		PORTB ^= 1<<LED;
//		repeatCount = 0;
//		}
//
//		}
	}
}
void toggle_led(void){
	repeatCount++;
		if(repeatCount>38){
				PORTB ^= 1<<LED;
				repeatCount = 0;
				}
}
ISR(TIM0_COMPA_vect){
//	PORTB ^= 1<<LED;
}

