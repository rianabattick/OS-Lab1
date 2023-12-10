#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main() {
  printf("Starting Linked List Tests...\n");
  
  // Test list creation
  list_t *mylist = list_alloc();
  if (mylist == NULL) {
    printf("List creation: FAILED\n");
    return 1;
  } else {
    printf("List creation: PASSED\n");
  }

  // Test adding elements to the front
  list_add_to_front(mylist, 10);
  list_add_to_front(mylist, 20);
  list_add_to_front(mylist, 30);
  printf("After adding to front: ");
  list_print(mylist); // Should print 30 -> 20 -> 10 -> NULL

  // Test adding elements to the back
  list_add_to_back(mylist, 40);
  list_add_to_back(mylist, 50);
  printf("After adding to back: ");
  list_print(mylist); // Should print 30 -> 20 -> 10 -> 40 -> 50 -> NULL

  // Test removing from front
  int removed_elem = list_remove_from_front(mylist);
  printf("Removed from front: %d\n", removed_elem);
  printf("After removing from front: ");
  list_print(mylist); // Should print 20 -> 10 -> 40 -> 50 -> NULL

  // Test removing from back
  removed_elem = list_remove_from_back(mylist);
  printf("Removed from back: %d\n", removed_elem);
  printf("After removing from back: ");
  list_print(mylist); // Should print 20 -> 10 -> 40 -> NULL

  // Test checking for element
  int is_in = list_is_in(mylist, 20);
  printf("Is 20 in the list?: %s\n", is_in ? "Yes" : "No");

  is_in = list_is_in(mylist, 100);
  printf("Is 100 in the list?: %s\n", is_in ? "Yes" : "No");

  // Test getting element at index
  int index = 1;
  int elem_at_index = list_get_elem_at(mylist, index);
  printf("Element at index %d: %d\n", index, elem_at_index);

  index = 3;
  elem_at_index = list_get_elem_at(mylist, index);
  printf("Element at index %d: %d\n", index, elem_at_index); // Should return -1 for invalid index

  // Test list length
  int length = list_length(mylist);
  printf("List length: %d\n", length); // Should match the number of elements

  // Clean up
  list_free(mylist);

  printf("Linked List Tests Complete.\n");

  return 0;
}
