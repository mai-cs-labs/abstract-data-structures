#ifndef __STACK_H__
#define __STACK_H__

#include <stddef.h>
#include <stdbool.h>

typedef struct stack Stack;

// NOTE: Change void to char, int32_t or float, according to a variant;
//       This is the only part of API that you can change.
typedef void T;

Stack* stack_create_with(const size_t capacity);
Stack* stack_create(void);
void stack_destroy(Stack** const stack);

void stack_push(Stack* const stack, T value);
void stack_pop(Stack* const stack);

T* stack_top(const Stack* const stack);

void stack_sort(Stack* const stack);
void stack_clear(Stack* const stack);

size_t stack_size(const Stack* const stack);
size_t stack_capacity(const Stack* const stack);
bool stack_empty(const Stack* const stack);

void stack_print(const Stack* const stack);

#endif // __STACK_H__
