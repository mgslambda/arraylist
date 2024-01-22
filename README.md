# Array List Data Structure

Resizable array for holding integers.

## Public Interface

- init: Allocate memory for the arraylist and return a pointer to it. The initial size of the list is passed as an argument here. 
- length: Return the number of elements currently held in the list.
- isEmpty: Return true if length == 0, false otherwise.
- get: Return an element at a specified index
- add: Add an element to a specified index of the arraylist, resizing if needed.
- remove: Remove an element at a specified index, resizing if `length` falls below half the arraylist's capacity
- del: Deallocate the arraylist

## Resizing Factor

The arraylist doubles in size each time it reaches capacity

