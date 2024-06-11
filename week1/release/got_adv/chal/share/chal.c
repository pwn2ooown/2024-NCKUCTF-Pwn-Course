#include <stdio.h>
#include <stdlib.h>

int main(){
  setvbuf(stdin, 0, _IONBF, 0);
  setvbuf(stdout, 0, _IONBF, 0);
  puts("GOT Hijacking Challenge");
  printf("Here's a leak: %p\n", puts);
  char buf[0x20];
  int addr = 0, value = 0;
  puts("Give me the address: ");
  scanf("%d", &addr);
  getchar();
  puts("Give me the value: ");
  scanf("%d", &value);
  getchar();
  int *ptr = (int *)addr;
  *ptr = value;
  gets(buf);
}
