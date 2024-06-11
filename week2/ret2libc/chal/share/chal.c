#include <stdio.h>

int main() {
  setvbuf(stdin, 0, _IONBF, 0);
  setvbuf(stdout, 0, _IONBF, 0);
  char buf[0x20];
  long long nums[10];
  puts("My little database (Under construction)");
  while (1) {
    puts("1. Change number");
    puts("2. See the number");
    puts("3. Exit");
    int choice = 0;
    int idx = 0;

    scanf("%d", &choice);
    switch (choice) {
      case 1:
        puts("Enter the index (0-9):");
        scanf("%d", &idx);
        if (idx >= 0 && idx < 10) {
          puts("Enter the number:");
          scanf("%lld", &nums[idx]);
        } else {
          puts("Invalid index!");
        }
        break;
      case 2:
        puts("Enter the index (0-9):");
        scanf("%d", &idx);
        printf("The number is %lld\n", nums[idx]);
        break;
      case 3:
        puts("Bye!");
        goto end;
      default:
        puts("Invalid choice!");
        break;
    }
  }
end:
  puts(
      "Since it's under development, please leave your feedback before you "
      "go!");
  getchar();
  gets(buf);
  return 0;
}