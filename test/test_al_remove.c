#include <assert.h>
#include <stdio.h>
#include "../include/arraylist.h"

int main() {
    ArrayList *al = al_init();

    /* Remove an element */
    al_add(al, 0, 42);
    int t1 = al_remove(al, 0);
    assert(t1 == 42);
    assert(al_size(al) == 0);
    puts("Passed test 1");

    /* Remove the element(s) from the expanded portion of the list (should trigger a shrink) */
    al_add(al, 9, 24);
    al_add(al, 9, 55); // causes expansion; `24` moves to index 10
    int t2 = al_remove(al, 10); // should cause a shrink
    assert(t2 == 24);
    puts("Passed test 2");

    /* Remove multiple elements */
    al_add(al, 0, 76);
    al_add(al, 4, 40);
    int t3a = al_remove(al, 0);
    int t3b = al_remove(al, 9);
    assert(t3a == 76);
    assert(t3b == 55);
    assert(al_size(al) == 1);

    puts("All tests passed");
}

