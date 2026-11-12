#include <stdbool.h>

volatile unsigned short* video_memory = (volatile unsigned short*)0xb8000;
short text_color = 0x0f00;
short background_color = 0x0000;

void set_text_color(char *color);

void print(char *word);

bool strcmp(char *str1, char *str2);

void putchar(char ch);

void main(void) {
	print("Welcome to ");
	set_text_color("red");
    print("A");
	set_text_color("cyan");
    print("X");
	set_text_color("red");
    print("D");
	set_text_color("cyan");
    print("O");
	set_text_color("red");
    print("S");
	set_text_color("white");
    print(" Pre-Alpha 1.0!");
}

void putchar(char ch) {
	*video_memory = background_color + text_color + ch;
	video_memory++;
}

void print(char *word) {
    for (int i = 0; word[i] != 0; i++) {
        *video_memory = background_color + text_color + word[i];
        video_memory++;
    }
}

void set_text_color(char *color){
	if(strcmp(color, "black")){
		text_color = 0x0000;
	} else if(strcmp(color, "blue")){
		text_color = 0x0100;
	} else if(strcmp(color, "green")){
		text_color = 0x0200;
	} else if(strcmp(color, "cyan")){
		text_color = 0x0300;
	} else if(strcmp(color, "red")){
		text_color = 0x0400;
	} else if(strcmp(color, "magenta")){
		text_color = 0x0500;
	} else if(strcmp(color, "brown")){
		text_color = 0x0600;
	} else if(strcmp(color, "light gray")){
		text_color = 0x0700;
	} else if(strcmp(color, "dark gray")){
		text_color = 0x0800;
	} else if(strcmp(color, "light blue")){
		text_color = 0x0900;
	} else if(strcmp(color, "light green")){
		text_color = 0x0a00;
	} else if(strcmp(color, "light cyan")){
		text_color = 0x0b00;
	} else if(strcmp(color, "light red")){
		text_color = 0x0c00;
	} else if(strcmp(color, "pink")){
		text_color = 0x0d00;
	} else if(strcmp(color, "yellow")){
		text_color = 0x0e00;
	} else if(strcmp(color, "white")){
		text_color = 0x0f00;
	} else{
		print("Invalid Argument: Undefined Color");
	}
}

bool strcmp(char *str1, char *str2){
	for (int i = 0; str1[i] != 0 && str2[i] != 0; i++){
		if (str1[i] != str2[i]){
			return false;
		}
	}
	return str1[i] == str2[i];
}
