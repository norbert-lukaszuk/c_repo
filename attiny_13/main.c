#include <avr/io.h>
#include <util/delay.h>
#define LED PB3
#define BUTTON PB4

void blink(uint8_t b); // blink sequence function

int main(void){
	DDRB |= 1<<LED; // led pin as output
	PORTB |= 1<<BUTTON; // button pin input pullup
uint8_t i = 20; // blinks in sequence
	while(1){
if(!(PINB & 1<<BUTTON)){ // if button pushed call blink function
	blink(i);
	}



			}

}
void blink(uint8_t b){
	for(uint8_t x=0; x<b; x++){
					PORTB ^= 1<<LED;
					_delay_ms(60);
				};
	PORTB &=~(1<<LED);
}

