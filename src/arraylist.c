#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/arraylist.h"
#include "../include/_arraylist.h"

#define AL_INIT_CAPACITY 10
#define GROWTH_FACTOR 1.5

static Position *_pos_init() {
    Position *p = malloc(sizeof *p);
    if (p == NULL) {
        fprintf(stderr, "Could not allocate memory for Position\n");
        exit(EXIT_FAILURE);
    }
    p->val = 0;
    p->is_empty = 1;
    return p;
}

/* Doubles the size of al->list */
static void _al_expand(ArrayList *al) {
    al->list = realloc(al->list, sizeof *al->list * floor(al->_capacity * GROWTH_FACTOR));
    if (al->list == NULL) {
        fprintf(stderr, "Failed to expand ArrayList\n");
        exit(EXIT_FAILURE);
    }
    for (size_t i = al->_capacity; i < floor(al->_capacity * GROWTH_FACTOR); i++) {
        *(al->list + i) = _pos_init();
    }
    al->_capacity = floor(al->_capacity * GROWTH_FACTOR);
}

/* Halves the size of al->list */
static void _al_shrink(ArrayList *al) {
    al->list = realloc(al->list, sizeof *al->list * ceil(al->_capacity / GROWTH_FACTOR));
    if (al->list == NULL) {
        fprintf(stderr, "Failed to shrink ArrayList\n");
        exit(EXIT_FAILURE);
    }
    al->_capacity = ceil(al->_capacity / GROWTH_FACTOR);
}

/* Return the rightmost non-empty index or zero if ArrayList is empty */
static int _al_get_last_idx(ArrayList *al) {
    int idx = 0;
    for (int i = al->_capacity - 1; i >= 0; i--) {
        if (!(*(al->list + i))->is_empty) {
            idx = i;
            break;
        }
    }
    return idx;
}

/* Move the value of each non-empty position 1 position to the right
   start at idx, the index of the rightmost non-empty position, and work back */
static void _al_shift_right(ArrayList *al, int stop_idx) {
    int start_index = _al_get_last_idx(al);
    for (int i = start_index; i >= stop_idx; i--) {
        if (!(*(al->list + i))->is_empty) {
            (*(al->list + i + 1))->val = (*(al->list + i))->val;
            (*(al->list + i + 1))->is_empty = 0;
            (*(al->list + i))->is_empty = 1;
        }
    }
}

ArrayList *al_init() {
    ArrayList *al = malloc(sizeof *al);
    if (al == NULL) {
        fprintf(stderr, "Could not allocate memory for ArrayList\n");
        exit(EXIT_FAILURE);
    }
    al->list = malloc(sizeof *al->list * AL_INIT_CAPACITY);
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
    if ((*(al->list + index))->is_empty) {
        fprintf(stderr, "Cannot get from an empty position\n");
        exit(EXIT_FAILURE);
    }
    return (*(al->list + index))->val;
}

void al_add(ArrayList *al, int index, int val) {
    if (index >= al->_capacity) {
        fprintf(stderr, "Index %d out of bounds\n", al->_capacity);
        exit(EXIT_FAILURE);
    }
    if (!(*(al->list + index))->is_empty) {
        // if the last position in the list is occupied, resize
        if (!(*(al->list + al->_capacity - 1))->is_empty) {
            _al_expand(al);
        }
        _al_shift_right(al, index);
    }
    (*(al->list + index))->val = val;
    (*(al->list + index))->is_empty = 0;
    al->size++;
}

int al_remove(ArrayList *al, int index) {
    if (index < 0 || index > al->_capacity) {
        fprintf(stderr, "Cannot remove from beyond the bounds of the ArrayList\n");
        exit(EXIT_FAILURE);
    }
    if ((*(al->list + index))->is_empty) {
        fprintf(stderr, "Cannot remove from an empty position\n");
        exit(EXIT_FAILURE);
    }
    int res = (*(al->list + index))->val;
    (*(al->list + index))->is_empty = 1;
    al->size--;
    if (al_size(al) < 0.3 * al->_capacity && al->_capacity > 10) {
        int can_shrink = 1;
        for (int i = ceil(al->_capacity / 2.0); i < al->_capacity; i++) {
            if (!(*(al->list + i))->is_empty) {
                can_shrink = 0;
                break;
            }
        }
        if (can_shrink) {
            _al_shrink(al);
        }
    }
    return res;
}

void al_del(ArrayList *al) {
    for (size_t i = 0; i < al->_capacity; i++) {
        free(*(al->list + i));
    }
    free(al->list);
    free(al);
    al = NULL;
}

void al_add_end(ArrayList *al, int val) {
    int last_idx = _al_get_last_idx(al);
    al_add(al, last_idx == 0 ? last_idx : last_idx + 1, val);
}

