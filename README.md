# 2024-NCKUCTF-Pwn-Course

⭐⭐ **If you find this repository helpful, please give us a star!** ⭐⭐

程式安全課程 @ 2024 NCKUCTF Club 成大資安社社課

Binary exploitation (pwn) course for 2024 NCKUCTF Club.

Online labs are available at our [CTFd](https://class.nckuctf.org/)

## Environment

Ubuntu 22.04 LTS with glibc version 2.35. (No heap exploitation so that the glibc version doesn't affect that much I think)

## Table of Contents

`exploit scripts` folder contains the solution for lab challenges.

### Week 1 - Binary Exploitation 101

- [Video](https://www.youtube.com/watch?v=DX5rzI5OlJk)
- [Slides](/week1/Binary_Exploit_101%20@%20NCKUCTF.pdf)

| Lab                                                    |  Description               |
| ------------------------------------------------------------ | ---------------------- |
| got  |    Global Offset Table Hijacking          |
| got_adv  |    Overwrite Global Offset Table of  stack_chk_fail   to bypass canary       |
| magicgdb |   Use gdb to dynamically control the program and get the flag|
| ret2sc |   Return to shellcode|
| ret2sc_adv |   Use shellcode to open, read and write|
| ret2win |   Return to win|
| ret2win_adv |   Return to win, beware of movaps issue|

### Week 2 - ROP

- [Video](https://www.youtube.com/watch?v=gQMS-eNU9Ho)
- [Slides](/week2/ROP%20@%20NCKUCTF.pdf)

| Lab                                                    |  Description               |
| ------------------------------------------------------------ | ---------------------- |
| ezrop  |   Static linked binary ROP          |
| pivoting |   Forge rbp and rsp to achieve stack pivoting|
| ret2libc |   Leak libc address left in array and return to libc|
| ret2libc_adv |   Leak libc address by yourself and return to libc|
| ret2libc2024 |   New trick to solve return to libc **without** csu_init gadgets |

### Week 3 - Brief Introduction To IoT Security

- [Video](https://www.youtube.com/watch?v=Q7C9g9Kw6s0)
- [Slides](/week3/Brief%20Introduction%20To%20IoT%20Security%20@%20NCKUCTF.pdf)
- [Extra](https://hackmd.io/@pwn2ooown/HJK40Xpca)

| Lab                                                    |  Description               |
| ------------------------------------------------------------ | ---------------------- |
| httpd_patched  |    Reproduce CVE-2023-37144 on Tenda AC10 Firmware V15.03.06.23 using qemu         |

## License

The content of this repository is licensed under the [CC-BY-4.0](https://choosealicense.com/licenses/cc-by-sa-4.0/).
