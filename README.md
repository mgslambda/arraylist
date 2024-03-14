# ArrayList Data Structure

Dynamic array for holding integers. 

## Public Interface

- al_init: Allocate memory for the arraylist and return a pointer to it. The initial size of the list is 10.

- al_size: Return the number of user-added elements currently occupying the list.

- al_is_empty: Return true if length == 0, false otherwise.

- al_get: Return the element held at a specified index. Error if no element exists at the index.

- al_add: Add an element to a specified index, doubling the capacity of the list if `al_size` is about to exceed the list's capacity. If an element is added to an already occupied index, each element, starting with the occupying element, is shifted to the right, then the new element is added.

- al_remove: Remove an element at a specified index, halving the size of the list if all of the following hold true:
  - `al_size` falls below 30% of the list's capacity
  - the capacity of the list is greater than its default initial capacity (10)
  - there are no elements in the portion of the list that will be lost if the list is halved

- al_del: Deallocate the arraylist.

