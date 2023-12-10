// list/list.c
// 
// Implementation for linked list.
//
// <RBattick>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

list_t *list_alloc() { 
  list_t* mylist = (list_t *) malloc(sizeof(list_t)); 
  mylist->head = NULL;
  return mylist;
}

void list_free(list_t *l) {
  node_t *current = l->head;
  node_t *next;
  
  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }

  free(l);
}

void list_print(list_t *l) {
  node_t *current = l->head;
  while (current != NULL) {
    printf("%d -> ", current->value);
    current = current->next;
  }
  printf("NULL\n");
}

int list_length(list_t *l) {
  int length = 0;
  node_t *current = l->head;
  while (current != NULL) {
    length++;
    current = current->next;
  }
  return length;
}

void list_add_to_back(list_t *l, elem value) {
  node_t *new_node = (node_t *) malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = NULL;

  if (l->head == NULL) {
    l->head = new_node;
  } else {
    node_t *current = l->head;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_node;
  }
}

void list_add_to_front(list_t *l, elem value) {
  node_t *new_node = (node_t *) malloc(sizeof(node_t));
  new_node->value = value;
  new_node->next = l->head;
  l->head = new_node;
}

void list_add_at_index(list_t *l, elem value, int index) {

  int i;

  if (index <= 0) {
    list_add_to_front(l, value);
    return;
  }

  node_t *new_node = (node_t *) malloc(sizeof(node_t));
  new_node->value = value;

  node_t *current = l->head;
  for (i = 0; current != NULL && i < index - 1; i++) {
    current = current->next;
  }

  if (current == NULL) {
    free(new_node);
    return; // index is out of bounds
  }

  new_node->next = current->next;
  current->next = new_node;
}

elem list_remove_from_back(list_t *l) {
  if (l->head == NULL) {
    return -1; // list is empty
  }

  node_t *current = l->head;
  node_t *prev = NULL;

  while (current->next != NULL) {
    prev = current;
    current = current->next;
  }

  elem value = current->value;
  free(current);

  if (prev == NULL) {
    l->head = NULL;
  } else {
    prev->next = NULL;
  }

  return value;
}

elem list_remove_from_front(list_t *l) {
  if (l->head == NULL) {
    return -1; // list is empty
  }

  node_t *next_node = l->head->next;
  elem value = l->head->value;
  free(l->head);
  l->head = next_node;
  return value;
}

elem list_remove_at_index(list_t *l, int index) {

  int i;

  if (index <= 0 || l->head == NULL) {
    return list_remove_from_front(l);
  }

  node_t *current = l->head;
  node_t *prev = NULL;

  for (i = 0; current != NULL && i < index; i++) {
    prev = current;
    current = current->next;
  }

  if (current == NULL) {
    return -1; // index is out of bounds
  }

  prev->next = current->next;
  elem value = current->value;
  free(current);

  return value;
}

bool list_is_in(list_t *l, elem value) {
  node_t *current = l->head;
  while (current != NULL) {
    if (current->value == value) {
      return true;
    }
    current = current->next;
  }
  return false;
}

elem list_get_elem_at(list_t *l, int index) {
  if (index < 0) {
    return -1;
  }
}
