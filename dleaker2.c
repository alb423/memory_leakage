#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mcheck.h>

int main(int argc, char **argv)
{
	void *p1, *p2;

    mtrace();

    p1 = malloc(10);
    p2 = malloc(20);

    printf("p1=%p is leakage\n", p1);
    printf("p2=%p is leakage\n", p2);
        
    free(p1);

    muntrace();

    return 1;
}
