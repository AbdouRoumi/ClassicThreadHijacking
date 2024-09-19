#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <tlhelp32.h>

#define okay(msg, ...) printf("[+]" msg "\n", __VA_ARGS__)
#define info(msg, ...) printf("[+]" msg "\n", __VA_ARGS__)
#define warning(msg, ...) printf("[-]" msg "\n", __VA_ARGS__)
