#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stdlib.h>

typedef int Item;

struct queue;


/// Dynamically allocates memory for a queue
struct queue *create(size_t capacity);

/// Releases the queue's dynamically allocated memory
void destroy(struct queue *q);

/// Clears the queue
void clear(struct queue *q);

/// Tests whether the queue is empty
bool is_empty(struct queue *q);

/// Tests whether the queue is full
bool is_full(struct queue *q);

/// Returns the size of the queue
size_t size(struct queue *q);

/// Inserts an item at the end of the queue
bool enqueue(struct queue *q, Item i);

/// Removes an item from the beginning of the queue
Item *dequeue(struct queue *q);

/// Returns the first item in the queue
Item *head(struct queue *q);

/// Returns the last item in the queue
Item *tail(struct queue *q);


#endif // QUEUE_H
