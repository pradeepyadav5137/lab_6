#include <stdio.h>
#include <stdlib.h>

#define MAX_SCROLL_POSITIONS 5  // Define maximum number of stored scroll positions

// Stack to store scroll positions
typedef struct Stack {
    int top;
    int capacity;
    int *positions;
} Stack;

// Function to create a stack of given capacity
Stack* createStack(int capacity) {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->positions = (int*)malloc(capacity * sizeof(int));
    return stack;
}

// Check if stack is full
int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Check if stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Push a scroll position onto the stack
void push(Stack* stack, int position) {
    if (isFull(stack)) {
        printf("Scroll history is full. Removing oldest entry.\n");
        // Shift all positions down to make space for the new one
        for (int i = 0; i < stack->top; i++) {
            stack->positions[i] = stack->positions[i + 1];
        }
        stack->positions[stack->top] = position; // Add the new position at the top
    } else {
        stack->positions[++stack->top] = position;
    }
    printf("Scrolled to position: %d\n", position);
}

// Pop the last scroll position from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("No previous scroll positions available.\n");
        return -1;
    }
    return stack->positions[stack->top--];
}

// Function to simulate scrolling and using the back feature
void scrollSimulation(Stack* scrollHistory) {
    push(scrollHistory, 100); // Simulating scroll positions
    push(scrollHistory, 200);
    push(scrollHistory, 300);
    push(scrollHistory, 400);
    push(scrollHistory, 500); // Stack is now full

    // Go back to previous scroll position
    int position = pop(scrollHistory);
    if (position != -1) {
        printf("Returning to previous scroll position: %d\n", position);
    }

    // Adding a new scroll position, which will cause the oldest to be removed
    push(scrollHistory, 600);
    position = pop(scrollHistory); // Going back again
    if (position != -1) {
        printf("Returning to previous scroll position: %d\n", position);
    }
}

int main() {
    Stack* scrollHistory = createStack(MAX_SCROLL_POSITIONS);

    scrollSimulation(scrollHistory);

    // Free allocated memory
    free(scrollHistory->positions);
    free(scrollHistory);

    return 0;
}
