// gcc -fno-stack-protector -no-pie chal.c -o chal

#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>

char username[0x20];

int main() {
    setvbuf(stdin, 0, _IONBF, 0);
    setvbuf(stdout, 0, _IONBF, 0);
    unsigned long addr = (unsigned long)&username & ~0xfff;
    mprotect((void *)addr, 0x1000, PROT_EXEC | PROT_READ | PROT_WRITE);
    char password[40];
    printf("Username: ");
    read(0, username, 0x20);
    printf("Password: ");
    read(0, password, 0x40);
    puts("Wrong username/password! Please try again.");
    return 0;
}