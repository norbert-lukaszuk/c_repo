#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define LED1 PB3
#define LED2 PB1
#define BUTTON PB4

uint8_t led_count_1;
uint8_t led_count_2;
void toggle_led(void);
int main(void){

	DDRB |= 1<<LED1 | 1<<LED2; // LED1 pin as output
	PORTB |= 1<<BUTTON | 1<<LED1| 1<<LED2; // button pin input pull up
	TCCR0B |= 1<<CS00 | 1<<CS02 ; //set timer prescaler for 1024
	TCCR0A |= 1<<WGM01;// set timer compare match
	OCR0A = 250;
	OCR0B = 125;
	TIMSK0 |= 1<<OCIE0A; // enable compare interrupts with values OCR0A & OCR0B
	TIMSK0 |= 1<<OCIE0B;
	GIMSK |= 1<<PCIE; // turn interrupts on
	PCMSK |= 1<<PCINT4; // enable pin PCINT4 to make interrupts

	sei();
	while(1){
//if( TCNT0>250){ // if button pushed call blink function
//	TCNT0 = 0;
//	led_count_1++;
//
//
//	if(led_count_1>38){
//		PORTB ^= 1<<LED1;
//		led_count_1 = 0;
//		}
//
//		}
	}
}
void toggle_led(void){
	led_count_1++;

		if(led_count_1>38){
				PORTB ^= 1<<LED1;
				led_count_1 = 0;
				}

}
ISR(TIM0_COMPA_vect){
		 toggle_led();
}
ISR(TIM0_COMPB_vect){
	led_count_2++;
	if(led_count_2>19){
				PORTB ^= 1<<LED2;
				led_count_2=0;
			}
}
ISR(PCINT0_vect){

	for(uint8_t i=0; i<30;i++){
		PORTB ^= 1<<LED1;
			_delay_ms(60);

	}

}
