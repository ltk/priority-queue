//
// pq_test.cpp
//

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <string>
#include <iostream>
#include <vector>
#include "pq.h"

using namespace std;

// Forward declarations for helper functions. They are defined after
// the test cases.

// Test cases

TEST_CASE("Priority Queue: Sanity Check", "[sanity]") {
  REQUIRE(true);
}

TEST_CASE("Priority Queue: Initialize", "[init]") {
  pq* queue = init_priority_queue();
  REQUIRE(queue != NULL);
}

TEST_CASE("Priority Queue: Peek", "[peek]") {
  pq* queue = init_priority_queue();
  REQUIRE(queue != NULL);
  REQUIRE(peek(queue) == ""); // should return empty string for empty list
  
}

TEST_CASE("Priority Queue: Insert", "[insert]") {
  pq* queue = init_priority_queue();
  REQUIRE(queue != NULL);

  string origCat = string("Cat Video");
  insert(queue, origCat, 3);
  string front = peek(queue);
  REQUIRE(front == origCat);

  string origGame = "Game Packet";
  insert(queue, origGame, 5);
  front = peek(queue);
  REQUIRE(front == origGame);

  string origMed = "Medical Packet";
  insert(queue, origMed, 10.5);
  front = peek(queue);
  REQUIRE(front == origMed);

  // now insert things less important
  string origCat2 = "Another Cat Video";
  insert(queue, origCat2, 3.1);
  front = peek(queue);
  REQUIRE(front == origMed); // med packet should win

  string origGame2 = "Another Game Packet";
  insert(queue, origGame2, 1.5);
  front = peek(queue);
  REQUIRE(front == origMed);
  
}

TEST_CASE("Priority Queue: Remove", "[remove]") {
  pq* queue = init_priority_queue();
  REQUIRE(queue != NULL);
  insert(queue, "Camel", 5.0); // C
  insert(queue, "Aardvark", 10); // C A
  insert(queue, "Firefly", 2); // F C A
  insert(queue, "Doggie", 7); // F C D A
  insert(queue, "Gorilla", 5); // F G C D A
  insert(queue, "Elephant", 11); // F G C D A E
  insert(queue, "Bobcat", 2); // B F G C D A E

  string popped;
  popped = remove(queue); // B F G C D A
  REQUIRE(popped == "Elephant");

  popped = remove(queue); // B F G C D
  REQUIRE(popped == "Aardvark");

  popped = remove(queue); // B F G C
  REQUIRE(popped == "Doggie");

  popped = remove(queue); // B F G
  REQUIRE(popped == "Camel");

  popped = remove(queue); // B F
  REQUIRE(popped == "Gorilla");

  popped = remove(queue); // B
  REQUIRE(popped == "Firefly");

  popped = remove(queue); // empty
  REQUIRE(popped == "Bobcat");
}



