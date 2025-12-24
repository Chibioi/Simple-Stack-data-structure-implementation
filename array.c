#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int top;
    int capacity;
    int *arr;
} Stack;

Stack *CreateStack(int capacity) {
  Stack *var = (Stack *)malloc(sizeof(Stack));
  if (var == NULL) {
    printf("Failed to allocate memory to stack structure");
    free(var);
    exit(EXIT_FAILURE);
  }

  var->capacity = capacity;
  var->top = -1;

  var->arr = (int *)malloc(var->capacity * sizeof(int));
  if (var->arr == NULL) {
    printf("Failed to allocate memory to stack array");
    free(var->arr);
    exit(EXIT_FAILURE);
  }
  return var;
}


bool isEmpty(Stack *stk) {
  return stk->top == -1;
}

bool isFull(Stack *stk) {
  return stk->top == stk->capacity -1;
}

int Push(Stack *stk, int val) {
  if (isFull(stk)) {
      printf("Error: Stack is full!!\n");
    exit(EXIT_FAILURE);
  };
  return stk->arr[++stk->top] = val;
}

int Pop(Stack *stk) {
    if(isEmpty(stk)) {
        printf("Error: Stack is empty!!\n");
        exit(EXIT_FAILURE);
    };

    int poppedValue = stk->arr[stk->top];
    stk->top--;
    return poppedValue;
}

int Peek(Stack *stk) {
    if (isEmpty(stk)) {
        return -1;
    }
    return stk->arr[stk->top];
}

void DestroyStack(Stack *stk) {
    if (stk != NULL) {
        free(stk->arr);
        free(stk);
    }
}

