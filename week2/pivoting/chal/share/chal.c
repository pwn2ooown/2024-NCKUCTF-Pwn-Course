#include <stdio.h>

char name[0x100];

int main() {
  setvbuf(stdin, 0, 2, 0);
  setvbuf(stdout, 0, 2, 0);
  puts("What's your name?");
  read(0, name, 0x100);
  printf("Hello, %s :D", name);
  char buf[0x20];
  puts("Try your best: ");
  read(0, buf, 48);
  return 0;
}
