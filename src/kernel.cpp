#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

uint8_t x = 0;
uint8_t y = 0;

void clear_scr(void){
	uint16_t* video = (uint16_t *)0xB8000;

	for(int i = 0; i <= 80; ++i)
		for(int j = 0; j <= 25; ++j){
			video[80*j+i] &= 0xFF00;
		}
	x = 0;
	y = 0;
}

void print(uint8_t* text){
	
	static uint16_t* video = (uint16_t *)0xB8000;

	for (int i = 0; text[i] != '\0'; ++i){
		switch(text[i]){
			case '\n':
				++y;
				x=0;
				break;
			default:
				video[80*y+x] = (video[80*y+x] & 0xFF00) | text[i];
				++x;
				break;
		}
		if (x >= 80){
			++y;
			x = 0;
		}
	}
}

extern "C"
void kmain(void) {
	print("Noob");
	clear_scr();
	print("Hello from karnal");
}
