#include <stdio.h>

int main(){
    char buf[0x40];
    setvbuf(stdin,0,_IONBF,0);
	setvbuf(stdout,0,_IONBF,0);
    printf("Give me your overflow: ");
    read(0,buf,0x400); // oops!
    return 0;
}
// 0x0000000000452475