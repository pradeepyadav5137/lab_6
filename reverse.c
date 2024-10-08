#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
struct stack
{
    int top;
    int size;
    char *arr;
};

struct stack *creatStack(int size)
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = size;
    s->arr = (char *)malloc(s->size * sizeof(char));
    return s;
}

int is_full(struct stack *s)
{
    struct stack *ptr = s;
    if (ptr->top == s->size - 1)
    {
	return 1;
    }
    return 0;
}

int is_empty(struct stack *s)
{
    struct stack *ptr = s;
    if (ptr->top == -1)
    {
	return 1;
    }
    return 0;
}

void push(struct stack *s, char a)
{
    if (is_full(s))
    {
	printf("stack overflow can't insert %d character in stack:", a);
    }
    else
    {
	s->top++;
	s->arr[s->top] = a;
    }
}

int pop(struct stack *s)
{
    if (is_empty(s))
    {
	return '\0';
    }
    else
    {
	return s->arr[s->top--];
    }
}

void reverseString(char str[])
{
    int n, i;
    struct stack *s = creatStack(strlen(str));
    n = strlen(str);
   // struct stack *s = creatStack(n);

    //   push to the stack
    for (i = 0; i < n; i++)
    {
	push(s, str[i]);
    }

    // pull form the stack
    for (i = 0; i < n; i++)
    {
	str[i] = pop(s);
    }

    //
}

int main()
{

    // char str[] = "Self-love is the appreciation of oneself";

    char str[1000];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);


    printf("Original String: %s\n", str);

    reverseString(str);

    printf("Reversed String: %s\n", str);
    getch();
    // clrscr();
    return 0;
}