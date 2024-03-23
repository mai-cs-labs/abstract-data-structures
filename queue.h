#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stddef.h>
#include <stdbool.h>

typedef struct queue Queue;

// NOTE: Change void to char, int32_t or float, according to a variant;
//       This is the only part of API that you can change.
typedef void T;

Queue* queue_create_with(const size_t capacity);
Queue* queue_create(void);
void queue_destroy(Queue** const queue);

void queue_push(Queue* const queue, T value);
void queue_pop(Queue* const queue);

T* queue_front(const Queue* const queue);

void queue_sort(Queue* const queue);
void queue_clear(Queue* const queue);

size_t queue_size(const Queue* const queue);
size_t queue_capacity(const Queue* const queue);
bool queue_empty(const Queue* const queue);

void queue_print(const Queue* const queue);

#endif // __QUEUE_H__
