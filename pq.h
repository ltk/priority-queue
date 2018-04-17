//                                                             
//                                                             
//  .--.                  .         .--.                       
//  |   )   o          o _|_       :    :                      
//  |--'.--..  .-. .--..  |  .  .  |    |.  . .-. .  . .-. .--.
//  |   |   | (   )|   |  |  |  |  :  ( ;|  |(.-' |  |(.-' `--.
//  '   ' -' `-`-' ' -' `-`-'`--|   `--`-`--`-`--'`--`-`--'`--'
//                              ;                              
//                           `-'

#ifndef pq_h
#define pq_h

#include <string>
#include "pq_struct.h"

using namespace std;

// init_priority_queue allocates memory for a pq structure (which you
// are responsble for defining in the pq_struct.h file. It is
// completely up to you how this should work.
pq* init_priority_queue();

// insert adds the given text to the queue, using the specified
// priority. If there is a tie, the given string should be placed at
// the back of the group that it ties with, so all other strings with
// this priority will be removed first.
void insert(pq*& queue, string text, float priority);

// remove will access the highest priority element in the queue,
// remove it from the queue, and return it. if the queue is empty it
// should return the empty string.
string remove(pq* &queue);

// ppek will access the highest priority element in the queue and
// return it without modifying the queue. if the queue is empty it
// should return the empty string.
string peek(pq* &queue);

#endif
