//
// pq.cpp
//
// Decide how you want to implement this: linked list? heap? array?
// magic pixie dust? The choice is yours.
//
// NOTE: You will need to edit pq_struct.h as appropriate, depending
// on your implementation strategy. You will turn in this file (your
// implementation of everything) and pq_struct.h (your definition of
// the pq structure and any helper functions you might create).

// Your Name: Lawson Kurtz

#include <string>
#include <iostream>
#include "pq.h"

pq_item* init_pq_item(float priority, string text) {
  pq_item* item = new pq_item;
  item->priority = priority;
  item->text = text;
  return item;
}

pq* init_priority_queue() {
  pq* queue = new pq;
  queue->length = 0;
  return queue;
}

int parent_of(int cursor) {
  // 0 => NULL
  // 1,2 => 0
  // 3,4 => 1
  // 5,6 => 2
  // 7,8 => 3

  if (cursor == 0) {
    return -1;
  }

  if (cursor % 2 == 1) {
    return cursor / 2;
  }

  return (cursor / 2) - 1;
}

int first_child_of(int cursor) {
  return (cursor * 2) + 1;
}

bool in_bounds(int cursor, pq* queue) {
  return cursor <= (queue->length - 1);
}

void insert(pq* &queue, string text, float priority) {
  pq_item* item = init_pq_item(priority, text);

  // Insert into first empty slot.
  queue->items.push_back(item);

  // Swap with parent until invariant satisfied.
  int cursor_index = queue->length;
  int parent_index = parent_of(cursor_index);
  while (parent_index > -1 && queue->items[cursor_index]->priority > queue->items[parent_index]->priority) {
    // Swap values
    pq_item* cursor = queue->items[cursor_index];
    pq_item* parent = queue->items[parent_index];
    queue->items[cursor_index] = parent;
    queue->items[parent_index] = cursor;

    // Reset loop vars
    cursor_index = parent_index;
    parent_index = parent_of(cursor_index);
  }
  
  // Increment the length of the heap.
  queue->length++;
}

void fix_from_top(pq* queue, int cursor_index) {
  int child_index = first_child_of(cursor_index);

  // Choose the bigger of the children to compare with.
  if (!in_bounds(child_index, queue) && !in_bounds(child_index + 1, queue)) {
    // There are no children. We're done.
    return;
  } else if (in_bounds(child_index + 1, queue)) {
    // There are two children, choose the biggest to compare with.
    if (queue->items[child_index]->priority < queue->items[child_index + 1]->priority) {
      child_index++;
    }
  }

  // if the priority of the child is higher, swap with the root. Then recurse.
  if (queue->items[child_index]->priority > queue->items[cursor_index]->priority) {
    pq_item* cursor = queue->items[cursor_index];
    pq_item* child = queue->items[child_index];
    queue->items[cursor_index] = child;
    queue->items[child_index] = cursor;
    return fix_from_top(queue, child_index);
  } 


  // if there is a first child, and the priority of that child is higher,
  // swap with the root. Then recurse.
  // if (in_bounds(first_child_index, queue) && queue->items[first_child_index]->priority > queue->items[cursor_index]->priority) {
  //   pq_item* cursor = queue->items[cursor_index];
  //   pq_item* child = queue->items[first_child_index];
  //   queue->items[cursor_index] = child;
  //   queue->items[first_child_index] = cursor;
  //   return fix_from_top(queue, first_child_index);
  // }

  // If there is a second child, and the priority of that child is higher,
  // swap with the root. Then recurse.
  // if (in_bounds(first_child_index + 1, queue) && queue->items[first_child_index + 1]->priority > queue->items[cursor_index]->priority) {
  //   pq_item* cursor = queue->items[cursor_index];
  //   pq_item* child = queue->items[first_child_index + 1];
  //   queue->items[cursor_index] = child;
  //   queue->items[first_child_index + 1] = cursor;
  //   return fix_from_top(queue, first_child_index + 1);
  // }
}

string remove(pq* &queue) {
  // DEBUG
  for (int i = 0; i < queue->length; i ++) {
    cout << queue->items[i]->text << "(" << queue->items[i]->priority << ")" << endl;
  }

  cout << endl;
  cout << endl;
  // END DEBUG

  if (queue->length > 0) {
    string text = queue->items[0]->text;

    // Move last item in heap to root.
    pq_item* last_item = queue->items[queue->length - 1];
    queue->items[0] = last_item;

    // Decrement the length of the heap.
    queue->length--;

    // Swap root with children until invariant satisfied.
    fix_from_top(queue, 0);

    // If the new top has the same priority as a child, swap the nodes
    // to preserve the first in, first out subordering.
    if (queue->length > 1 && queue->items[0]->priority == queue->items[1]->priority) {
      pq_item* root = queue->items[0];
      pq_item* child = queue->items[1];
      queue->items[0] = child;
      queue->items[1] = root;
    }

    if (queue->length > 2 && queue->items[0]->priority == queue->items[2]->priority) {
      pq_item* root = queue->items[0];
      pq_item* child = queue->items[2];
      queue->items[0] = child;
      queue->items[2] = root;
    }

    // // DEBUG
    // for (int i = 0; i < queue->length; i ++) {
    //   cout << endl;
    //   cout << queue->items[i]->text << ", ";
    // }
    // // END DEBUG

    // queue->items.pop();
    return text;
  }

  return "";
}


string peek(pq* &queue) {
  if (queue->length > 0) {
    return queue->items[0]->text;
  }

  return "";
}
