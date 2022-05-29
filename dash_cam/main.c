#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define LED1 PB3
#define LED2 PB1
#define BUTTON PB4

uint8_t input_count;
uint8_t led_count;
void checkInput(void);
int main(void){

	DDRB |= 1<<LED1 | 1<<LED2; // LED1 pin as output
	PORTB |= 1<<BUTTON | 1<<LED1| 1<<LED2; // button pin input pull up
	TCCR0B |= 1<<CS00 | 1<<CS02 ; //set timer prescaler for 1024
	TCCR0A |= 1<<WGM01;// set timer compare match
	OCR0A = 255;
	OCR0B = 125;
	TIMSK0 |= 1<<OCIE0A | 1<<OCIE0B; // enable compare interrupts with values OCR0A & OCR0B



	sei();
	while(1){

	}
}
void checkInput(void){
	if(!(PINB & 1<<BUTTON)){
	input_count++;
	if(input_count > 150){
		PORTB ^= 1<<LED1;
		input_count = 0;
	}
	}
	else {
		input_count = 0;
		PORTB |=1<<LED1;
	}
}
ISR(TIM0_COMPB_vect){

		checkInput();

}
ISR(TIM0_COMPA_vect){
led_count++;
if(led_count>150){
	PORTB ^=1<<LED2;
	PORTB &= 1<<BUTTON;
	led_count=0;
}


}
