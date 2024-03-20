#define TEST_IMPLEMENTATION
#include "test.h"

// Напишите функцию, выполняющую вспомогательную процедуру
// над Вашей структурой данных. Список аргументов и возвращаемый
// тип можно изменять как Вам удобно по заданию
static void custom_action(...) {

}

// Напишите тест для вспомогательной процедуры внутри
TEST(action) {
    TEST_ASSERT(false);
}

// Общие юнит-тесты

#if defined(__STACK_H__)
    TEST(create_stack_with) {
        Stack* stack = NULL;

        stack = stack_create_with(7);

        TEST_ASSERT(stack_size(stack) == 0);
        TEST_ASSERT(stack_capacity(stack) == 7);

        stack_destroy(&stack);
    }

    TEST(create_stack) {
        Stack* stack = stack_create();

        TEST_ASSERT(stack_empty(stack) == true);
        TEST_ASSERT(stack_capacity(stack) > 0);

        stack_destroy(&stack);
    }

    TEST(destroy_stack) {
        Stack* stack = NULL;

        TEST_ASSERT(stack_empty(stack) == true);
        TEST_ASSERT(stack_capacity(stack) == 0);

        stack_destroy(&stack);

        TEST_ASSERT(stack_empty(stack) == true);
        TEST_ASSERT(stack_capacity(stack) == 0);
        TEST_ASSERT(stack == NULL);

        stack = stack_create();
        stack_destroy(&stack);

        TEST_ASSERT(stack_empty(stack) == true);
        TEST_ASSERT(stack_capacity(stack) == 0);
        TEST_ASSERT(stack == NULL);
    }

    TEST(push_to_stack) {
        Stack* stack = NULL;

        stack_push(stack, 'o');

        TEST_ASSERT(stack_empty(stack) == true);
        TEST_ASSERT(stack_capacity(stack) == 0);
        TEST_ASSERT(stack == NULL);

        stack = stack_create_with(4);

        stack_push(stack, '1');
        stack_push(stack, '2');
        stack_push(stack, '3');

        TEST_ASSERT(stack_empty(stack) == false);
        TEST_ASSERT(stack_capacity(stack) == 4);

        stack_push(stack, '4');

        TEST_ASSERT(stack_size(stack) == 4);
        TEST_ASSERT(stack_capacity(stack) > 4);

        stack_push(stack, '5');
        stack_push(stack, '6');
        stack_push(stack, '7');

        TEST_ASSERT(stack_size(stack) == 7);
        TEST_ASSERT(stack_capacity(stack) > 4);

        stack_destroy(&stack);
    }

    TEST(pop_from_stack) {
        Stack* stack = NULL;

        stack_pop(stack);

        stack = stack_create_with(4);

        stack_pop(stack);

        TEST_ASSERT(stack_size(stack) == 0);
        TEST_ASSERT(stack_capacity(stack) == 4);

        stack_push(stack, '1');
        stack_push(stack, '2');

        stack_pop(stack);
        stack_pop(stack);

        TEST_ASSERT(stack_size(stack) == 0);
        TEST_ASSERT(stack_capacity(stack) == 4);

        for (int i = 0; i < 5; ++i)
            stack_push(stack, 'o');

        stack_pop(stack);

        TEST_ASSERT(stack_size(stack) == 4);
        TEST_ASSERT(stack_capacity(stack) > 4);

        stack_destroy(&stack);
    }

    TEST(top_of_stack) {
        Stack* stack = NULL;

        TEST_ASSERT(stack_top(stack) == NULL);

        stack = stack_create_with(2);

        TEST_ASSERT(stack_top(stack) == NULL);

        stack_push(stack, '1');
        TEST_ASSERT(*(char*)stack_top(stack) == '1');

        TEST_ASSERT(stack_size(stack) == 1);

        stack_push(stack, '2');
        stack_push(stack, '3');

        TEST_ASSERT(*(char*)stack_top(stack) == '3');

        stack_pop(stack);

        TEST_ASSERT(*(char*)stack_top(stack) == '2');

        stack_destroy(&stack);
    }

    TEST(clear_stack) {
        Stack* stack = NULL;

        stack_clear(stack);

        stack = stack_create();
        stack_clear(stack);

        TEST_ASSERT(stack_capacity(stack) > 0);
        TEST_ASSERT(stack_size(stack) == 0);

        stack_push(stack, '1');
        stack_push(stack, '2');
        stack_push(stack, '3');

        stack_clear(stack);

        TEST_ASSERT(stack_capacity(stack) > 0);
        TEST_ASSERT(stack_size(stack) == 0);

        stack_destroy(&stack);
    }

    TEST(sorted_stack) {
        Stack* stack = NULL;
        char prev_value = '\0';
        char* item = NULL;
        bool sorted = true;

        stack_sort(stack);

        stack = stack_create();

        stack_sort(stack);

    #if 1
        stack_push(stack, 'f');
        stack_push(stack, 'g');
        stack_push(stack, 'd');
        stack_push(stack, 'h');
        stack_push(stack, 'b');
        stack_push(stack, 'c');
        stack_push(stack, 'a');
        stack_push(stack, 'e');
    #else
        stack_push(stack, 'a');
        stack_push(stack, 'b');
        stack_push(stack, 'c');
        stack_push(stack, 'd');
        stack_push(stack, 'e');
        stack_push(stack, 'f');
        stack_push(stack, 'g');
        stack_push(stack, 'h');
    #endif

        stack_sort(stack);

        prev_value = *(char*)stack_top(stack);
        stack_pop(stack);

        while (!stack_empty(stack)) {
            item = (char*)stack_top(stack);
            stack_pop(stack);

            if (*item > prev_value) {
                sorted = false;
                break;
            }
        }

        TEST_ASSERT(sorted == true);

        stack_destroy(&stack);
    }
#elif defined(__QUEUE_H__)


#elif defined(__DEQUE_H__)

#else
#error "You must include one of stack.h, queue.h or deque.h"
#endif

int main(void) {
    return test_run((const test_fn[]){
#if defined(__STACK_H__)
        create_stack_with,
        create_stack,
        destroy_stack,
        push_to_stack,
        pop_from_stack,
        top_of_stack,
        clear_stack,
        sorted_stack,
#elif defined(__QUEUE_H__)
#elif defined(__DEQUE_H__)
#endif
        action,
        NULL,
    });
}
