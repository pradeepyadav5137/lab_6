#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
    int size;
    int top;
    char **arr;   
    int *action;
};

struct stack *creatStack() {
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = 10;
    s->arr = (char **)malloc(s->size * sizeof(char *));
    s->action = (int *)malloc(s->size * sizeof(int)); 
    return s;
}

int is_full(struct stack *s) {
    return s->top == s->size - 1;
}

int is_empty(struct stack *s) {
    return s->top == -1;
}

void push(struct stack *s, char product[], int actionType) {
    if (is_full(s)) {
        printf("Stack overflow, can't insert %s into stack.\n", product);
    } else {
        s->top++;
        s->arr[s->top] = strdup(product);  // Store product name
        s->action[s->top] = actionType;    // Store action type: 1 for add, 0 for remove
    }
}

char *pop(struct stack *s, int *actionType) {
    if (is_empty(s)) {
        return NULL;
    } else {
        *actionType = s->action[s->top];  // Retrieve action type
        char *product = s->arr[s->top];
        s->top--;
        return product;
    }
}

void insert(char *arr[], int *n, char product[]) {
    if (*n < 10) {
        arr[*n] = strdup(product);  // Allocate memory for product in cart
        (*n)++;
        printf("Product added to the cart.\n");
    } else {
        printf("Cart is full.\n");
    }
}

void delete(char *arr[], int *n, int index) {
    if (index < 0 || index >= *n) {
        printf("Invalid index!\n");
        return;
    }
    free(arr[index]);  // Free memory of the deleted product
    for (int i = index; i < *n - 1; i++) {
        arr[i] = arr[i + 1];  // Shift items left
    }
    (*n)--;
}

void undo(char *arr[], int *n, struct stack *s) {
    int actionType;
    char *product = pop(s, &actionType);
    if (product == NULL) {
        printf("Nothing to undo.\n");
        return;
    }

    if (actionType == 1) {
        // Undo an addition
        for (int i = 0; i < *n; i++) {
            if (strcmp(arr[i], product) == 0) {
                delete(arr, n, i);
                printf("Undo successful: removed %s from cart.\n", product);
                break;
            }
        }
    } else if (actionType == 0) {
        // Undo a deletion
        if (*n < 10) {
            insert(arr, n, product);
            printf("Undo successful: re-added %s to cart.\n", product);
        } else {
            printf("Cannot undo; cart is full.\n");
        }
    }
    free(product);  // Free the product string after undo operation
}

void showcart(char *arr[], int *n) {
    for (int i = 0; i < *n; i++) {
        printf("%d - %s\t", i, arr[i]);
    }
    printf("\n");
}

int main() {
    int n = 5, opt, index;
    char product[20];
    struct stack *s = creatStack();
    char *arr[10] = {"laptop", "mouse", "laptop_stand", "mobile_stand", "keyboard"};

    while (1) {
        printf("\nPlease select an option:\n");
        printf("1 - Add product\n");
        printf("2 - Remove product\n");
        printf("3 - Undo\n");
        printf("4 - Show cart\n");
        printf("5 - Exit\n");
        scanf("%d", &opt);

        switch (opt) {
        case 1:
            printf("Enter the product to add to the cart: ");
            scanf("%s", product);
            insert(arr, &n, product);
            push(s, product, 1);  // Store the addition action for undo
            break;

        case 2:
            showcart(arr, &n);
            printf("Choose the option to delete: ");
            scanf("%d", &index);
            if (index >= 0 && index < n) {
                push(s, arr[index], 0);  // Save deleted item and action type
                delete(arr, &n, index);
            }
            break;

        case 3:
            undo(arr, &n, s);
            break;

        case 4:
            printf("Your cart is:\n");
            showcart(arr, &n);
            break;

        case 5:
            printf("Exiting...\n");
            exit(0);
        }
    }
    return 0;
}
