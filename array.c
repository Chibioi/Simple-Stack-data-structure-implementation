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
    exit(EXIT_FAILURE);
    free(var);
  }

  var->capacity = capacity;
  var->top = -1;

  var->arr = (int *)malloc(var->capacity * sizeof(int));
  if (var->arr == NULL) {
    printf("Failed to allocate memory to stack array");
    exit(EXIT_FAILURE);
    free(var->arr);
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
    return EXIT_FAILURE;
  };
  stk->top++;
  return stk->arr[++stk->top] = val;
  // return stk->arr[stk->top++];
}

int Pop(Stack *stk) {
    if(isEmpty(stk)) {
        printf("Error: Stack is empty!!\n");
        return EXIT_FAILURE;
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
        free(stk);
        free(stk->arr);
    }
}

int main() {
    Stack *mystack = CreateStack(100);
    // Push(mystack, 2);
    // Push(mystack, 4);
    // Push(mystack, 6);
    Pop(mystack);
    // Push(mystack, 8);
    // Pop(mystack);
    // Push(mystack, 10);
    // Pop(mystack);
    // Push(mystack, 11);
    // Pop(mystack);
    int debug = Peek(mystack); 
    printf("%d\n", debug);
   
    return 0;
}
