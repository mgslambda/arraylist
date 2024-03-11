#ifndef ARRAYLIST_H
#define ARRAYLIST_H

typedef struct arraylist ArrayList;

extern ArrayList *al_init();
extern int al_size(ArrayList *al);
extern int al_is_empty(ArrayList *al);
extern int al_get(ArrayList *al, int index);
extern void al_add(ArrayList *al, int index, int val);
extern int al_remove(ArrayList *al, int index);
extern void al_del(ArrayList *al);

#endif
