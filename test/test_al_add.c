#include <assert.h>
#include <stdio.h>
#include "../include/arraylist.h"

int main() {
    ArrayList *al = al_init();

    /* Add to the beginning of the list */
    al_add(al, 0, 42);
    int t1 = al_get(al, 0);
    assert(t1 == 42);
    puts("Passed test 1");

    /* Add to an arbitrary position */
    al_add(al, 4, 24);
    int t2 = al_get(al, 4);
    assert(t2 == 24);
    puts("Passed test 2");

    /* Add to a non-empty position (this should cause a shift) */
    al_add(al, 4, 15);
    int t3a = al_get(al, 4);
    int t3b = al_get(al, 5);
    assert(t3a == 15);
    assert(t3b == 24);
    puts("Passed test 3");

    /* Add to the end of the list */
    al_add(al, 9, 101);
    int t4 = al_get(al, 9);
    assert(t4 == 101);
    puts("Passed test 4");

    /* Add to the end of the list again (this should cause an expansion and shift) */
    al_add(al, 9, 55);
    int t5a = al_get(al, 9);
    int t5b = al_get(al, 10);
    assert(t5a == 55);
    assert(t5b == 101);
    assert(al_size(al) == 5);
    puts("Passed test 5");

    puts("All tests passed");
}

