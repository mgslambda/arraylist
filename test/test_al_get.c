#include <assert.h>
#include <stdio.h>
#include "../include/arraylist.h"

int main() {
    ArrayList *ar = al_init(4);
    int val = al_get(ar, 2);
    assert(val == 0);

    al_get(ar, 5); /* should throw an "Index out of bounds" error */
}
