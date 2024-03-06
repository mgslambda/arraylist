#include <assert.h>
#include <stdio.h>
#include "../include/arraylist.h"

int main() {
    ArrayList *al = al_init();
    // int val = al_get(al, 10); // index out of bounds
    int val = al_get(al, 9);
    assert(val == 0);
}
