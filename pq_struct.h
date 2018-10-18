// 
// pq_struct.h
// 
// Edit this to flesh out the pq structure as appropriate. You may
// also add the function prototypes for anything else, and implement
// them in pq.cpp.
//
// You will turn in this file and pq.cpp.
//
// Your Name: Lawson Kurtz

#include <vector>

#ifndef pq_struct_h
#define pq_struct_h

struct pq_item {
  float priority;
  std::string text;
};

struct pq {
  std::vector<pq_item*> items;
  int length;
};

#endif
