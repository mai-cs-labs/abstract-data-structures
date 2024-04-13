#define TEST_IMPLEMENTATION
#include "test.h"

// Напишите функцию, выполняющую вспомогательную процедуру
// над Вашей структурой данных

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

        stack = stack_create_with(4);

        stack_push(stack, '1');
        stack_push(stack, '2');
        stack_push(stack, '3');

        TEST_ASSERT(stack_empty(stack) == false);
        TEST_ASSERT(stack_capacity(stack) == 4);

        stack_push(stack, '4');

        TEST_ASSERT(stack_size(stack) == 4);

        stack_push(stack, '5');

        TEST_ASSERT(stack_capacity(stack) > 4);

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
        TEST_ASSERT(*stack_top(stack) == (T)'1');

        TEST_ASSERT(stack_size(stack) == 1);

        stack_push(stack, '2');
        stack_push(stack, '3');

        TEST_ASSERT(*stack_top(stack) == (T)'3');

        stack_pop(stack);

        TEST_ASSERT(*stack_top(stack) == (T)'2');

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
        T prev_value;
        T* item = NULL;
        bool sorted = true;

        stack_sort(stack);

        stack = stack_create();

        stack_sort(stack);

        stack_push(stack, 'f');
        stack_push(stack, 'g');
        stack_push(stack, 'd');
        stack_push(stack, 'h');
        stack_push(stack, 'b');
        stack_push(stack, 'c');
        stack_push(stack, 'a');
        stack_push(stack, 'e');

        stack_sort(stack);

        prev_value = *stack_top(stack);
        stack_pop(stack);

        while (!stack_empty(stack)) {
            item = stack_top(stack);
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

    TEST(create_queue_with) {
        Queue* queue = NULL;

        queue = queue_create_with(7);

        TEST_ASSERT(queue_size(queue) == 0);
        TEST_ASSERT(queue_capacity(queue) == 7);

        queue_destroy(&queue);
    }

    TEST(create_queue) {
        Queue* queue = queue_create();

        TEST_ASSERT(queue_empty(queue) == true);
        TEST_ASSERT(queue_capacity(queue) > 0);

        queue_destroy(&queue);
    }

    TEST(destroy_queue) {
        Queue* queue = NULL;

        TEST_ASSERT(queue_empty(queue) == true);
        TEST_ASSERT(queue_capacity(queue) == 0);

        queue_destroy(&queue);

        TEST_ASSERT(queue_empty(queue) == true);
        TEST_ASSERT(queue_capacity(queue) == 0);
        TEST_ASSERT(queue == NULL);

        queue = queue_create();
        queue_destroy(&queue);

        TEST_ASSERT(queue_empty(queue) == true);
        TEST_ASSERT(queue_capacity(queue) == 0);
        TEST_ASSERT(queue == NULL);
    }

    TEST(push_to_queue) {
        Queue* queue = NULL;

        queue_push(queue, 'o');

        TEST_ASSERT(queue_empty(queue) == true);
        TEST_ASSERT(queue_capacity(queue) == 0);

        queue = queue_create_with(4);

        queue_push(queue, '1');
        queue_push(queue, '2');
        queue_push(queue, '3');

        TEST_ASSERT(queue_empty(queue) == false);
        TEST_ASSERT(queue_capacity(queue) == 4);

        queue_push(queue, '4');

        TEST_ASSERT(queue_size(queue) == 4);
        TEST_ASSERT(queue_capacity(queue) > 4);

        queue_push(queue, '5');
        queue_push(queue, '6');
        queue_push(queue, '7');

        TEST_ASSERT(queue_size(queue) == 7);
        TEST_ASSERT(queue_capacity(queue) > 4);

        queue_destroy(&queue);
    }

    TEST(pop_from_queue) {
        Queue* queue = NULL;

        queue_pop(queue);

        queue = queue_create_with(4);

        queue_pop(queue);

        TEST_ASSERT(queue_size(queue) == 0);
        TEST_ASSERT(queue_capacity(queue) == 4);

        queue_push(queue, '1');
        queue_push(queue, '2');

        queue_pop(queue);
        queue_pop(queue);

        TEST_ASSERT(queue_size(queue) == 0);
        TEST_ASSERT(queue_capacity(queue) == 4);

        for (int i = 0; i < 5; ++i)
            queue_push(queue, 'o');

        queue_pop(queue);

        TEST_ASSERT(queue_size(queue) == 4);
        TEST_ASSERT(queue_capacity(queue) > 4);

        queue_destroy(&queue);
    }

    TEST(front_of_queue) {
        Queue* queue = NULL;

        TEST_ASSERT(queue_front(queue) == NULL);

        queue = queue_create_with(2);

        TEST_ASSERT(queue_front(queue) == NULL);

        queue_push(queue, '1');
        TEST_ASSERT(*queue_front(queue) == (T)'1');

        TEST_ASSERT(queue_size(queue) == 1);

        queue_push(queue, '2');
        queue_push(queue, '3');

        TEST_ASSERT(*queue_front(queue) == (T)'1');

        queue_pop(queue);

        TEST_ASSERT(*queue_front(queue) == (T)'2');

        queue_destroy(&queue);
    }

    TEST(clear_queue) {
        Queue* queue = NULL;

        queue_clear(queue);

        queue = queue_create();
        queue_clear(queue);

        TEST_ASSERT(queue_capacity(queue) > 0);
        TEST_ASSERT(queue_size(queue) == 0);

        queue_push(queue, '1');
        queue_push(queue, '2');
        queue_push(queue, '3');

        queue_clear(queue);

        TEST_ASSERT(queue_capacity(queue) > 0);
        TEST_ASSERT(queue_size(queue) == 0);

        queue_destroy(&queue);
    }

    TEST(sorted_queue) {
        Queue* queue = NULL;
        T prev_value;
        T* item = NULL;
        bool sorted = true;

        queue_sort(queue);

        queue = queue_create();

        queue_sort(queue);

        queue_push(queue, 'f');
        queue_push(queue, 'g');
        queue_push(queue, 'd');
        queue_push(queue, 'h');
        queue_push(queue, 'b');
        queue_push(queue, 'c');
        queue_push(queue, 'a');
        queue_push(queue, 'e');

        queue_sort(queue);

        prev_value = *queue_front(queue);
        queue_pop(queue);

        while (!queue_empty(queue)) {
            item = queue_front(queue);
            queue_pop(queue);

            if (*item < prev_value) {
                sorted = false;
                break;
            }
        }

        TEST_ASSERT(sorted == true);

        queue_destroy(&queue);
    }

#elif defined(__DEQUE_H__)

    TEST(create_deque_with) {
        Deque* deque = NULL;

        deque = deque_create_with(7);

        TEST_ASSERT(deque_size(deque) == 0);
        TEST_ASSERT(deque_capacity(deque) == 7);

        deque_destroy(&deque);
    }

    TEST(create_deque) {
        Deque* deque = deque_create();

        TEST_ASSERT(deque_empty(deque) == true);
        TEST_ASSERT(deque_capacity(deque) > 0);

        deque_destroy(&deque);
    }

    TEST(destroy_deque) {
        Deque* deque = NULL;

        TEST_ASSERT(deque_empty(deque) == true);
        TEST_ASSERT(deque_capacity(deque) == 0);

        deque_destroy(&deque);

        TEST_ASSERT(deque_empty(deque) == true);
        TEST_ASSERT(deque_capacity(deque) == 0);
        TEST_ASSERT(deque == NULL);

        deque = deque_create();
        deque_destroy(&deque);

        TEST_ASSERT(deque_empty(deque) == true);
        TEST_ASSERT(deque_capacity(deque) == 0);
        TEST_ASSERT(deque == NULL);
    }

    TEST(push_to_deque_front) {
        Deque* deque = NULL;

        deque_push_front(deque, 'o');

        TEST_ASSERT(deque_empty(deque) == true);
        TEST_ASSERT(deque_capacity(deque) == 0);

        deque = deque_create_with(4);

        deque_push_front(deque, '1');
        deque_push_front(deque, '2');
        deque_push_front(deque, '3');

        TEST_ASSERT(deque_empty(deque) == false);
        TEST_ASSERT(deque_capacity(deque) == 4);

        deque_push_front(deque, '4');

        TEST_ASSERT(deque_size(deque) == 4);
        TEST_ASSERT(deque_capacity(deque) > 4);

        deque_push_front(deque, '5');
        deque_push_front(deque, '6');
        deque_push_front(deque, '7');

        TEST_ASSERT(deque_size(deque) == 7);
        TEST_ASSERT(deque_capacity(deque) > 4);

        deque_destroy(&deque);
    }

    TEST(push_to_deque_back) {
        Deque* deque = NULL;

        deque_push_back(deque, 'o');

        TEST_ASSERT(deque_empty(deque) == true);
        TEST_ASSERT(deque_capacity(deque) == 0);

        deque = deque_create_with(4);

        deque_push_back(deque, '1');
        deque_push_back(deque, '2');
        deque_push_back(deque, '3');

        TEST_ASSERT(deque_empty(deque) == false);
        TEST_ASSERT(deque_capacity(deque) == 4);

        deque_push_back(deque, '4');

        TEST_ASSERT(deque_size(deque) == 4);
        TEST_ASSERT(deque_capacity(deque) > 4);

        deque_push_back(deque, '5');
        deque_push_back(deque, '6');
        deque_push_back(deque, '7');

        TEST_ASSERT(deque_size(deque) == 7);
        TEST_ASSERT(deque_capacity(deque) > 4);

        deque_destroy(&deque);
    }

    TEST(pop_from_deque_front) {
        Deque* deque = NULL;

        deque_pop_front(deque);

        deque = deque_create_with(4);

        deque_pop_front(deque);

        TEST_ASSERT(deque_size(deque) == 0);
        TEST_ASSERT(deque_capacity(deque) == 4);

        deque_push_front(deque, '1');
        deque_push_back(deque, '2');

        deque_pop_front(deque);
        deque_pop_front(deque);

        TEST_ASSERT(deque_size(deque) == 0);
        TEST_ASSERT(deque_capacity(deque) == 4);

        for (int i = 0; i < 5; ++i)
            deque_push_front(deque, 'o');

        deque_pop_front(deque);

        TEST_ASSERT(deque_size(deque) == 4);
        TEST_ASSERT(deque_capacity(deque) > 4);

        deque_destroy(&deque);
    }

    TEST(pop_from_deque_back) {
        Deque* deque = NULL;

        deque_pop_back(deque);

        deque = deque_create_with(4);

        deque_pop_back(deque);

        TEST_ASSERT(deque_size(deque) == 0);
        TEST_ASSERT(deque_capacity(deque) == 4);

        deque_push_front(deque, '1');
        deque_push_back(deque, '2');

        deque_pop_back(deque);
        deque_pop_back(deque);

        TEST_ASSERT(deque_size(deque) == 0);
        TEST_ASSERT(deque_capacity(deque) == 4);

        for (int i = 0; i < 5; ++i)
            deque_push_back(deque, 'o');

        deque_pop_back(deque);

        TEST_ASSERT(deque_size(deque) == 4);
        TEST_ASSERT(deque_capacity(deque) > 4);

        deque_destroy(&deque);
    }

    TEST(front_of_deque) {
        Deque* deque = NULL;

        TEST_ASSERT(deque_front(deque) == NULL);

        deque = deque_create_with(2);

        TEST_ASSERT(deque_front(deque) == NULL);

        deque_push_front(deque, '1');
        TEST_ASSERT(*deque_front(deque) == (T)'1');

        TEST_ASSERT(deque_size(deque) == 1);

        deque_push_back(deque, '2');
        deque_push_front(deque, '3');

        TEST_ASSERT(*deque_front(deque) == (T)'3');

        deque_pop_front(deque);

        TEST_ASSERT(*deque_front(deque) == (T)'1');

        deque_destroy(&deque);
    }

    TEST(back_of_deque) {
        Deque* deque = NULL;

        TEST_ASSERT(deque_front(deque) == NULL);

        deque = deque_create_with(2);

        TEST_ASSERT(deque_front(deque) == NULL);

        deque_push_back(deque, '1');
        TEST_ASSERT(*deque_back(deque) == (T)'1');

        TEST_ASSERT(deque_size(deque) == 1);

        deque_push_front(deque, '2');
        deque_push_back(deque, '3');

        TEST_ASSERT(*deque_back(deque) == (T)'3');

        deque_pop_back(deque);

        TEST_ASSERT(*deque_back(deque) == (T)'1');

        deque_destroy(&deque);
    }

    TEST(clear_deque) {
        Deque* deque = NULL;

        deque_clear(deque);

        deque = deque_create();
        deque_clear(deque);

        TEST_ASSERT(deque_capacity(deque) > 0);
        TEST_ASSERT(deque_size(deque) == 0);

        deque_push_front(deque, '1');
        deque_push_back(deque, '2');
        deque_push_front(deque, '3');
        deque_push_back(deque, '4');

        deque_clear(deque);

        TEST_ASSERT(deque_capacity(deque) > 0);
        TEST_ASSERT(deque_size(deque) == 0);

        deque_destroy(&deque);
    }

    TEST(sorted_deque) {
        Deque* deque = NULL;
        T prev_value = '\0';
        T* item = NULL;
        bool sorted = true;

        deque_sort(deque);

        deque = deque_create();

        deque_sort(deque);

        deque_push_front(deque, 'f');
        deque_push_back(deque, 'g');
        deque_push_front(deque, 'd');
        deque_push_back(deque, 'h');
        deque_push_front(deque, 'b');
        deque_push_back(deque, 'c');
        deque_push_front(deque, 'a');
        deque_push_back(deque, 'e');

        deque_sort(deque);

        prev_value = *deque_back(deque);
        deque_pop_back(deque);

        while (!deque_empty(deque)) {
            item = deque_back(deque);
            deque_pop_back(deque);

            if (*item > prev_value) {
                sorted = false;
                break;
            }
        }

        TEST_ASSERT(sorted == true);

        deque_destroy(&deque);
    }

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
        create_queue_with,
        create_queue,
        destroy_queue,
        push_to_queue,
        pop_from_queue,
        front_of_queue,
        clear_queue,
        sorted_queue,
#elif defined(__DEQUE_H__)
        create_deque_with,
        create_deque,
        destroy_deque,
        push_to_deque_front,
        push_to_deque_back,
        pop_from_deque_front,
        pop_from_deque_back,
        front_of_deque,
        back_of_deque,
        clear_deque,
        sorted_deque,
#endif
        action,
        NULL,
    });
}
