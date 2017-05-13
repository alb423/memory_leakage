/*
	Test with libmemleak
	Usage:
	$ export LIBMEMLEAK_SOCKNAME=./memleak_sock

	$ LD_PRELOAD='/usr/local/lib/libmemleak.so' ./dleaker3
	or
	$ LD_PRELOAD='/usr/local/lib/libmemleak.so /usr/lib/x86_64-linux-gnu/libdl.so /usr/lib/x86_64-linux-gnu/libbfd.so' ./dleaker3

	$ memleak_control
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    void *p1, *p2;

    p1 = malloc(10);
    p2 = malloc(20);

    printf("p1=%p is leakage\n", p1);
    printf("p2=%p is leakage\n", p2);

    free(p1);

    while(1);

    return 1;
}
