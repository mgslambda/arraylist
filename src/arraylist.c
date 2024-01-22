#include <stdio.h>
#include <stdlib.h>
#include "../include/arraylist.h"
#include "../include/_arraylist.h"

/* Return the total capacity of ar */
static int _al_size(ArrayList *ar) {
    return sizeof(ar->list) / sizeof(*(ar->list));
}

/* Double the size of ar using realloc */
static void _al_resize(ArrayList *ar);

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

void al_add(ArrayList *ar, int index);

int al_remove(ArrayList *ar, int index);

void al_del(ArrayList *ar);
