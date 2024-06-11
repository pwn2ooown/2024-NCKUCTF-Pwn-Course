// gcc -fno-stack-protector -no-pie chal.c -o chal

#include <stdio.h>
#include <sys/mman.h>
#include <unistd.h>

#include "seccomp-bpf.h"

#define username_len 0x400

char username[username_len];

void apply_seccomp() {
  struct sock_filter filter[] = {
      VALIDATE_ARCHITECTURE,
      EXAMINE_SYSCALL,
      ALLOW_SYSCALL(read),
      ALLOW_SYSCALL(write),
      ALLOW_SYSCALL(open),
      ALLOW_SYSCALL(close),
      ALLOW_SYSCALL(openat),
      ALLOW_SYSCALL(exit),
      ALLOW_SYSCALL(exit_group),
      ALLOW_SYSCALL(getdents),
      ALLOW_SYSCALL(getrandom),
      ALLOW_SYSCALL(brk),
      ALLOW_SYSCALL(readlink),
      ALLOW_SYSCALL(rt_sigreturn),
      KILL_PROCESS,
  };

  struct sock_fprog prog = {
      .len = (unsigned short)(sizeof(filter) / sizeof(struct sock_filter)),
      .filter = filter,
  };

  if (prctl(PR_SET_NO_NEW_PRIVS, 1, 0, 0, 0)) {
    perror("Seccomp Error");
    exit(1);
  };
  if (prctl(PR_SET_SECCOMP, SECCOMP_MODE_FILTER, &prog)) {
    perror("Seccomp Error");
    exit(1);
  };
}

int main() {
  setvbuf(stdin, 0, _IONBF, 0);
  setvbuf(stdout, 0, _IONBF, 0);
  unsigned long addr = (unsigned long)&username & ~0xfff;
  mprotect((void *)addr, 0x1000, PROT_EXEC | PROT_READ | PROT_WRITE);
  apply_seccomp();
  char password[40];
  printf("Username: ");
  read(0, username, username_len);
  printf("Password: ");
  read(0, password, 0x40);
  puts("Wrong username/password! Please try again.");
  return 0;
}