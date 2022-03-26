/*
 * many_agrs.c
 *
 *  Created on: 07.04.2014
 *      Author: AKILLLL
 */

#include <stdio.h>
#include <stdarg.h>
int sum(int count, ...) {
    va_list args;
    int total = 0;
    va_start(args, count);
    while (count--)
        total += va_arg(args, int);
    va_end(args);
    return total;
}

int main() {
    printf("%d\n", sum(1, 33));
    printf("%d\n", sum(5, 1, 2, 3, 4));
    return 0;
}
