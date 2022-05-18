#include <avr/io.h>
#include <util/delay.h>
void blink(uint8_t b);
int main(void){
	DDRB |= 1<<PB3;
	PORTB |= 1<<PB4;
uint8_t i = 15;
	while(1){
		if(!(PINB & 1<<PB4) ){
			blink(i);
			_delay_ms(300);
		}
		else{PORTB &=~(1<<PB3);}

	}

}
void blink(uint8_t b){
	for(uint8_t x=b; x>=0; x--){
					PORTB ^= 1<<PB3;
					_delay_ms(150);
				};
}

