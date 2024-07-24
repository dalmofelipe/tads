#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAXBUFF 128


void clear_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}