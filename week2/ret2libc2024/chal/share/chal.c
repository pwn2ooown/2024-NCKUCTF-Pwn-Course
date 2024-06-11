#include <stdio.h>

int main(){
    setvbuf(stdin,0,_IONBF,0);
	setvbuf(stdout,0,_IONBF,0);
    char buf[32];
    printf("Can you exploit buffer overflow in 2024?");
    gets(buf);
}