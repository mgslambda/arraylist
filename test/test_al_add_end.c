#include "../include/arraylist.h"
#include <assert.h>
#include <stdio.h>

int main() {
    ArrayList *al = al_init();

    /* Add to an empty list */
    al_add_end(al, 12);
    int t1 = al_get(al, 0);
    assert(t1 == 12);
    puts("Passed Test 1");

    /* Multiple adds */
    al_add_end(al, 15);
    al_add_end(al, 42);
    al_add_end(al, 787);
    int t2 = al_get(al, 3);
    assert(t2 == 787);
    puts("Passed Test 2");

    /* Add to a non-empty sparse list */
    al_add(al, 8, 16);
    al_add_end(al, 79);
    int t3 = al_get(al, 9);
    assert(t3 == 79);
    puts("Passed Test 3");

    puts("Passed All Tests");
}

