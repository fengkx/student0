#include <stdio.h>
#include <stdlib.h>

/* A staticly allocated variable */
int foo;

/* A recursive function */
int recur(int i) {
    /* A stack allocated variable within a recursive function */
    int j = i;

    printf("recur call %d: stack@ %p\n", i, &j);

    if (i > 0) {
        return recur(i - 1);
    }

    return 0;
}

/* A statically allocarted, pre-initialized variable */
int stuff = 7;

int main(int argc, char *argv[]) {
    /* A stack allocated variable */
    int i;

    /* Dynamically allocate some stuff */
    char *buf1 = malloc(100);
    /* ... and some more stuff */
    char *buf2 = malloc(100);

    printf("_main  @ %p\n", main);
    printf("recur @ %p\n", recur);

    printf("_main stack: %p\n", &i);

    printf("static data: %p\n", &stuff);

    printf("Heap: malloc 1: %p\n", buf1);
    printf("Heap: malloc 2: %p\n", buf2);
    recur(3);
    return 0;
}
