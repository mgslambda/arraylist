#ifndef _ARRAYLIST_H
#define _ARRAYLIST_H

typedef struct position {
    int val;
    int is_empty;
} Position;

struct arraylist {
    Position **list;
    int size;
    int _capacity;
};

#endif
