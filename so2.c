#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mcheck.h>

void make_leak(void)
{
    malloc(32);
}
