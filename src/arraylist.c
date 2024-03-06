#include <stdio.h>
#include <stdlib.h>
#include "../include/arraylist.h"
#include "../include/_arraylist.h"

#define AL_INIT_CAPACITY 10

static Position *_pos_init() {
    Position *e = malloc(sizeof(Position));
    if (e == NULL) {
        fprintf(stderr, "Could not allocate memory for Element\n");
        exit(EXIT_FAILURE);
    }
    e->val = 0;
    e->is_empty = 1;
    return e;
}

/* Doubles the size of al->list */
static void _al_expand(ArrayList *al) {
    size_t i;

    al->list = realloc(al->list, al->_capacity * 2);
    if (al->list == NULL) {
        fprintf(stderr, "Failed to expand array\n");
        exit(EXIT_FAILURE);
    }
    al->_capacity *= 2;
    for (i = al->size; i < al->_capacity; i++) {
        *(al->list + i) = _pos_init();
    }
}

/* Halves the size of al->list */
static void _al_shrink(ArrayList *al) {
    al->list = realloc(al->list, al->_capacity / 2);
    if (al->list == NULL) {
        fprintf(stderr, "Failed to shrink array\n");
        exit(EXIT_FAILURE);
    }
    al->_capacity /= 2;
}

ArrayList *al_init() {
    int i;
    ArrayList *al = malloc(sizeof(ArrayList));
    if (al == NULL) {
        fprintf(stderr, "Could not allocate memory for ArrayList\n");
        exit(EXIT_FAILURE);
    }
    al->list = malloc(sizeof(Position) * AL_INIT_CAPACITY);
    if (al->list == NULL) {
        fprintf(stderr, "Could not allocate memory for ArrayList\n");
        exit(EXIT_FAILURE);
    }
    for (i = 0; i < AL_INIT_CAPACITY; i++) {
        *(al->list + i) = _pos_init();
    }
    al->size = 0;
    al->_capacity = AL_INIT_CAPACITY;
    return al;
}

int al_size(ArrayList *al) {
    return al->size;
}

int al_is_empty(ArrayList *al) {
    return al_size(al) == 0;
}

int al_get(ArrayList *al, int index) {
    if (index >= al->_capacity) {
        fprintf(stderr, "Index out of bounds: %i\n", al->_capacity);
        exit(EXIT_FAILURE);
    } else {
        return (*(al->list + index))->val;
    }
}

void al_add(ArrayList *al, int index) {
    /*
     * Add an element to an empty index
     * Add an element to a non-empty index, having to shift all elements >index to the right
       * There is enough space in the list to shift the elements
       * Shifting the elements would cause the list to overflow, so it needs to be expanded
     */
}

int al_remove(ArrayList *al, int index);

void al_del(ArrayList *al);
