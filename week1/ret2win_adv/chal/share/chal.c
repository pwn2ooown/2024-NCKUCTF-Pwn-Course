#include <stdio.h>
#include <stdlib.h>
void call_me(){
  system("sh");
}

int main(){
  setvbuf(stdin, 0, _IONBF, 0);
  setvbuf(stdout, 0, _IONBF, 0);
  char buf[0x20];
  puts("Control the rip, control the world!");
  gets(buf);
}