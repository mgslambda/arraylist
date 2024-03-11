#include <stdio.h>
#include <stdlib.h>
#include "../include/arraylist.h"
#include "../include/_arraylist.h"

#define AL_INIT_CAPACITY 10

static Position *_pos_init() {
    Position *e = malloc(sizeof(Position));
    if (e == NULL) {
        fprintf(stderr, "Could not allocate memory for Position\n");
        exit(EXIT_FAILURE);
    }
    e->val = 0;
    e->is_empty = 1;
    return e;
}

/* Doubles the size of al->list */
static void _al_expand(ArrayList *al) {
    al->list = realloc(al->list, sizeof *al->list * al->_capacity * 2);
    if (al->list == NULL) {
        fprintf(stderr, "Failed to expand ArrayList\n");
        exit(EXIT_FAILURE);
    }
    for (size_t i = al->_capacity; i < al->_capacity * 2; i++) {
        *(al->list + i) = _pos_init();
    }
    al->_capacity *= 2;
}

/* Halves the size of al->list */
static void _al_shrink(ArrayList *al) {
    al->list = realloc(al->list, sizeof *al->list * al->_capacity / 2);
    if (al->list == NULL) {
        fprintf(stderr, "Failed to shrink ArrayList\n");
        exit(EXIT_FAILURE);
    }
    al->_capacity /= 2;
}

/* Move the value of each non-empty position 1 position to the right
   start at idx, the index of the rightmost non-empty position, and work back */
static void _al_shift_right(ArrayList *al) {
    int idx = al->_capacity - 1;

    for (int i = al->_capacity - 1; i >= 0; i--) {
        if (!(*(al->list + i))->is_empty) {
            idx = i;
            break;
        }
    }

    for (int i = idx; i >= 0; i--) {
        if (!(*(al->list + i))->is_empty) {
            (*(al->list + i + 1))->val = (*(al->list + i))->val;
            (*(al->list + i + 1))->is_empty = 0;
            (*(al->list + i))->is_empty = 1;
        }
    }
}

ArrayList *al_init() {
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
    for (size_t i = 0; i < AL_INIT_CAPACITY; i++) {
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
        fprintf(stderr, "Index %d out of bounds\n", al->_capacity);
        exit(EXIT_FAILURE);
    }
    return (*(al->list + index))->val;
}

void al_add(ArrayList *al, int index, int val) {
    if (index >= al->_capacity) {
        fprintf(stderr, "Index %d out of bounds\n", al->_capacity);
        exit(EXIT_FAILURE);
    }
    // if position at index is occupied, shift all occupied positions greater than index to the right
    if (!(*(al->list + index))->is_empty) {
        // if the last position in the list is occupied, resize
        if (!(*(al->list + al->_capacity - 1))->is_empty) {
            _al_expand(al);
        }
        // then shift each occupied position to the right
        _al_shift_right(al);
    }
    (*(al->list + index))->val = val;
    (*(al->list + index))->is_empty = 0;
    al->size++;
}

int al_remove(ArrayList *al, int index);

void al_del(ArrayList *al);
