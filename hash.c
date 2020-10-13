#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

unsigned int hash_func(int key, int table_size) {
  return key % table_size; // key modulo size
}

ht * hash_init(int size) {
  ht * table = malloc(sizeof(ht)); // empty table
  table -> size = size;
  table -> slot_array = (ls ** ) malloc(table -> size * sizeof(ls * )); // pointer to a struct pointer
  /* slot_array will contain the chain of the slots of each index
each slot_array[i] will have linked lists pointing to each other */
  int i;
  for (i = 0; i < table -> size; ++i)
    table -> slot_array[i] = NULL; // empty chain
  return table;
}

int val_search(ht * table, int value) {
  ls * slot;
  int index = hash_func(value, table -> size); // find index of that value
  slot = table -> slot_array[index]; // the chain containing the value
  while (slot && slot -> value != value) // search all the slots until found
    slot = slot -> next;
  return !(slot == NULL); // 1 (true) if found 0 (false) if not
}

// search by index to find (FIRST) value in the index chain
int search_by_index(ht * table, int ind) {
  int i = 0;
  ls * slot;
  int index = hash_func(ind, table -> size);
  slot = table -> slot_array[index];
  if (slot) { // not NULL
    return slot -> value; // found
  } else
    return -1; // not found
}

// insert new value into the table
void insert(ht * table, int value) {
  int index = hash_func(value, table -> size); // create index for given value
  ls * temp = malloc(sizeof(ls)); // construct a slot
  temp -> value = value; // insert the value in the slot
  temp -> next = table -> slot_array[index]; // the slot will point to the index
  table -> slot_array[index] = temp; // insert the slot struct into the table's array
}

// delete value i.e. empty the index in the table
int delete_val(ht * table, int value) {
  ls * current_slot, * next_slot;
  int index = hash_func(value, table -> size); // get index of given value
  current_slot = table -> slot_array[index]; // index's slot

  if (current_slot && current_slot -> value == value) { // if found in current slot
    table -> slot_array[index] = current_slot -> next; // replace current slot in the index with its next
    free(current_slot); // delete current slot
    return 1; // deleted (true)
  }
  while (current_slot) { // search the chain
    next_slot = current_slot -> next; // go right to the next slot
    if (next_slot && next_slot -> value == value) { // next slot is not NULL and value found
      current_slot -> next = next_slot -> next; // point to its next
      free(next_slot); // delete
      return 1; // (true)
    } else {
      current_slot = next_slot; // go to the next one (not found yet)
    }
  }
  return 0; // not found (false) to be deleted
}

void print_hash(ht * table, int size) {
  int i;
  for (i = 0; i < table -> size; ++i) {
    printf("\nindex(%d): ", i);
    ls * val = table -> slot_array[i];
    while (val) {
      printf(" %d ", val -> value);
      val = val -> next;
    }
  }
  puts("");
}

int main() {
  ht * table = hash_init(TABLE_SIZE);
  int i;
  int arr[7] = {
    13,
    11,
    19,
    91,
    22,
    12,
    94
  };
  for (i = 0; i < 7; ++i)
    insert(table, arr[i]);
  puts("table now is not empty:");
  print_hash(table, TABLE_SIZE);
  puts("");
  puts("try now to search for and delete some values: (0 means False while 1 is True)");
  printf("search for value 13 --> %d \n", val_search(table, 13));
  printf("search for value 11 --> %d \n", val_search(table, 11));
  printf("search by index 1 --> value %d found\n", search_by_index(table, 1));
  printf("remove value 13 --> %d \n", delete_val(table, 13));
  printf("search again for value 13 --> %d \n", val_search(table, 13));
  printf("try again to remove value 13 --> %d \n", delete_val(table, 13));
  puts("\nprint the table after the deletion");
  print_hash(table, TABLE_SIZE);
  puts("\ninsert value 4");
  insert(table, 4);
  print_hash(table, TABLE_SIZE);
  printf("\nsearch by index 4 --> value %d is found \n\n", search_by_index(table, 4));
  printf("remove value 91 --> %d \n", delete_val(table, 91));
  puts("\ntable is now looking like:");
  print_hash(table, TABLE_SIZE);
}