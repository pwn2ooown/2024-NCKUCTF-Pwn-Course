#include <stdio.h>

int main() {
  char a[16] = "Hello NCKUCTF!";
  char b[10] = "";
  printf("a = %s\n", a);
  gets(b);
  printf("a = %s\n", a);
  return 0;
}
