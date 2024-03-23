#ifndef __DEQUE_H__
#define __DEQUE_H__

#include <stddef.h>
#include <stdbool.h>

typedef struct deque Deque;

// NOTE: Change void to char, int32_t or float, according to a variant;
//       This is the only part of API that you can change.
typedef void T;

Deque* deque_create_with(const size_t capacity);
Deque* deque_create(void);
void deque_destroy(Deque** const deque);

void deque_push_front(Deque* const deque, T value);
void deque_push_back(Deque* const deque, T value);

void deque_pop_front(Deque* const deque);
void deque_pop_back(Deque* const deque);

T* deque_front(const Deque* const deque);
T* deque_back(const Deque* const deque);

void deque_sort(Deque* const deque);
void deque_clear(Deque* const deque);

size_t deque_size(const Deque* const deque);
size_t deque_capacity(const Deque* const deque);
bool deque_empty(const Deque* const deque);

void deque_print(const Deque* const deque);

#endif // __DEQUE_H__
