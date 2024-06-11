#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void A() { puts("I'm function A"); }

void B() { puts("I'm function B"); }

struct ooo {
  long long a;
  void (*func)();
};

int main() {
  struct ooo *p = malloc(sizeof(struct ooo));
  p->a = 0x66666666DEADBEEF;
  p->func = (void *)A;
  printf("p->a = 0x%llx\n", p->a);
  p->func();
  free(p);
  // Alloc back the chunk
  char *c = malloc(16);
  strcpy(c, "AAAABBBB");
  long long *q = (long long *)(c + 8);
  *q = (long long)B;
  // UAF!
  printf("p->a = 0x%llx\n", p->a);
  p->func();
  return 0;
}
