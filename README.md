# Priority Queues

This homework is all about implementing (fully) an abstract data
type. The ADT you're implementing is a priority queue, which has the
following operations:

- insert element with some numeric priority
- remove the highest priority element
- peek at the highest priority element

## Implementation is your call

You'll implement this however you like. This causes some problems for
unit testing (see below).

The linked list assignment is a reasonable starting point. You'll have
to modify the node structure so it includes a priority value.

Another choice is to implement a heap. There's a lecture on this.

## How it is tested

Since our testing framework has no knowledge about how your
implementation is structured, it can only interact with your code via
the priority queue interface. This is defined in `pq.h`.

As a result, it is not possible to test your functions independently.

Testing `insert`, `peek` and `remove` all require `init_priority_queue`
to work. There are other dependencies. Take a look at the unit tests.

I recommend you implement your functions in this order:

1. `init_priority_queue`
2. `peek`
3. `insert`
4. `remove`
