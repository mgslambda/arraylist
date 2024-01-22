#ifndef ARRAYLIST_H
#define ARRAYLIST_H

typedef struct arraylist ArrayList;

extern ArrayList *al_init(int size);
extern int al_length(ArrayList *ar);
extern int al_is_empty(ArrayList *ar);
extern int al_get(ArrayList *ar, int index);
extern void al_add(ArrayList *ar, int index);
extern int al_remove(ArrayList *ar, int index);
extern void al_del(ArrayList *ar);

#endif