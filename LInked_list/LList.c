#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Node{
  int data;
  struct Node* prev;
  struct Node* next;
} Node;

typedef struct Stack {
  int currentSize;
  int maxSize;
  Node* top; // Global pointer for the top of the stack
  Node* node;
}Stack;

Stack* createStack(int capacity) {
  Stack* temp = (Stack *)malloc(sizeof(Stack));

  if (temp == NULL) {
    printf("Failed to allocate memory for the stack\n");
    exit(EXIT_FAILURE);
  }

  temp->maxSize = capacity;
  temp->currentSize = 0;
  temp->top = NULL;
  temp->node = NULL;

  return temp;
}

Node* createNode(int nodeValue) {
  Node* newNode = (Node*)malloc(sizeof(Node));
  if (newNode == NULL) {
    printf("Failed to allocate memory for new node\n");
    exit(EXIT_FAILURE);
  }

  newNode->data = nodeValue;
  newNode->prev = NULL;
  newNode->next = NULL;
  return newNode;
}

bool isEmpty(Stack* stack) {
  return stack->top == NULL;
}

bool isFull(Stack* stack) {
  if (stack->currentSize >= stack->maxSize) {
    return 1;
  }
  return 0;
}

void Push(Stack* stack, int value) {
  if (isFull(stack)) {
    printf("Stack is full!!\n");
    return;
  }

  Node* newNode = createNode(value);

  if (!isEmpty(stack)) {
    newNode->next = stack->top;
    stack->top->prev = newNode;
  }

  stack->top = newNode;
  stack->currentSize++;
  printf("Push value %d unto the stack\n", value);
}

int Pop(Stack* stack) {
  if (isEmpty(stack)) {
    printf("Stack is empty!!\n");
    return -1;
  }

  Node* temp = stack->top;
  int poppedValue = temp->data;
  stack->top = stack->top->next;

  if (stack->top != NULL) {
    stack->top->prev = NULL;
  }

  free(temp);
  stack->currentSize--;
  return poppedValue;
}

int Peek(Stack* stack) {
  if(stack->top == NULL) {
    printf("Stack is empty!!\n");
    return -1;
  }
  return stack->top->data;
}

void destroyStack(Stack* stack) {
  while (!isEmpty(stack)) {
    Pop(stack);
  }
  free(stack);
  printf("Stack memory cleared successfully.\n");
}
