#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
void never_use() {
  char key[] = "FFVF413";
  char cipher[] = {/* Redacted */};
  for (int i = 0; i < sizeof(cipher); i++) {
    printf("%c", cipher[i] ^ key[i % sizeof(key)]);
  }
}

void magic(int a) {
  if (a == 0xdeadbeef) {
    char key[] = "A5A_5A_A555OO";
    char cipher[] = {/* Redacted */};
    printf("You found key 2!\n");
    for (int i = 0; i < sizeof(cipher); i++) {
      printf("%c", cipher[i] ^ key[i % sizeof(key)]);
    }
    puts("Hint: There's a secret function in this binary.");
  } else {
    puts("You found key 1!");
    char key[] = "1a_1a_a555oo";
    char cipher[] = {/* Redacted */};
    for (int i = 0; i < sizeof(cipher); i++) {
      printf("%c", cipher[i] ^ key[i % sizeof(key)]);
    }
  }
}

int main() {
  setvbuf(stdin, NULL, _IONBF, 0);
  setvbuf(stdout, NULL, _IONBF, 0);
  setvbuf(stderr, NULL, _IONBF, 0);
  alarm(10);
  int fd = open("/dev/urandom", O_RDONLY);
  char buf[4];
  printf("Give me a magic number: ");
  read(fd, buf, 4);
  int magic_num = *((int *)buf);
  char num[4];
  read(0, num, 4);
  if (magic_num == atoi(num)) {
    magic(0x1337);
  } else {
    puts("No you should find my magic number.");
  }
  return 0;
}