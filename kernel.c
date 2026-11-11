void main(void){
	*(volatile unsigned short*)0xb8000 = 0xf51;
}
