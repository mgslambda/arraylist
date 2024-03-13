#include <assert.h>
#include <stdio.h>
#include "../include/arraylist.h"

int main() {
    ArrayList *al = al_init();
    al_add(al, 5, 198);
    int t1 = al_get(al, 5);
    assert(t1 == 198);
    puts("Passed test 1");

    al_del(al);

    puts("All tests passed");
}
