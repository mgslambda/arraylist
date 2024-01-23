#include <stdio.h>
#include <stdlib.h>
#include "../include/arraylist.h"
#include "../include/_arraylist.h"

/* Return the total capacity of ar */
static int _al_size(ArrayList *ar) {
    return sizeof(ar->list) / sizeof(*(ar->list));
}

/* Doubles the size of ar->list */
static void _al_expand(ArrayList *ar) {
    size_t i;
    int ar_size = _al_size(ar);

    ar->list = realloc(ar->list, ar_size * 2);
    if (ar->list == NULL) {
        fprintf(stderr, "Failed to expand array\n");
        exit(EXIT_FAILURE);
    }
    for (i = ar->length; i < ar_size; i++) {
        *(ar->list + i) = 0;
    }
}

/* Halves the size of ar->list */
static void _al_shrink(ArrayList *ar) {
    ar->list = realloc(ar->list, ar->length / 2);
    if (ar->list == NULL) {
        fprintf(stderr, "Failed to shrink array\n");
        exit(EXIT_FAILURE);
    }
}

ArrayList *al_init(int size) {
    ArrayList *ar = malloc(sizeof(ArrayList));
    if (ar == NULL) {
        fprintf(stderr, "Could not allocate memory for ArrayList\n");
        exit(EXIT_FAILURE);
    }
    ar->list = calloc(sizeof(int), size);
    if (ar->list == NULL) {
        fprintf(stderr, "Could not allocate memory for ArrayList\n");
        exit(EXIT_FAILURE);
    }
    ar->length = 0;
    return ar;
}

int al_length(ArrayList *ar) {
    return ar->length;
}

int al_is_empty(ArrayList *ar) {
    return al_length(ar) == 0;
}

int al_get(ArrayList *ar, int index) {
    if (index > _al_size(ar)) {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    } else {
        return *(ar->list + index);
    }
}

void al_add(ArrayList *ar, int index) {}

int al_remove(ArrayList *ar, int index);

void al_del(ArrayList *ar);
