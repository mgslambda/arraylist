# ArrayList Data Structure

Resizable array for holding integers.

## Public Interface

- init: Allocate memory for the arraylist and return a pointer to it. The initial size of the list is passed as an argument here. 
- length: Return the number of elements currently held in the list.
- isEmpty: Return true if length == 0, false otherwise.
- get: Return an element at a specified index.
- add: Add an element to a specified index of the arraylist, doubling the size of the list if `length` is about to exceed the list's capacity.
- remove: Remove an element at a specified index, halving the size of the list if `length` falls below 30% of the list's capacity.
- del: Deallocate the arraylist.
