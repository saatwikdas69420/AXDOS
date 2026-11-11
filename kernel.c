volatile unsigned short* video_memory = (volatile unsigned short*)0xb8000;

void print(char *word) {
    for (int i = 0; word[i] != 0; i++) {
        *video_memory = 0x0f00 + word[i];
        video_memory++;
    }
}

void main(void) {
        print("AXDOS Pre-Alpha 1.0");
}
