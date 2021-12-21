#include <stdio.h>
#include <stdlib.h>

#define Max 20

typedef struct {
  int front, rear;
  char * array[Max];
}Queue;

void print(Queue dq) {
  if (dq.front == -1 && dq.rear == -1) {
    printf("\nThe queue is empty");
  } 
  else {
    printf("\n");
    for (int i = dq.front; i <= dq.rear; i++) {
      printf("%s\t", dq.array[i]);
    }
  }
}


void pushRight(Queue * dq, char * key) {
  if (dq -> rear == Max - 1) {
    printf("\nThe queue is full");
  } 
  else {
    if (dq -> front == -1 && dq -> rear == -1) {
      dq -> front++;
    }
    dq -> array[++dq -> rear] = key;
  }
}


void pushLeft(Queue * dq, char * key) {
  if (dq -> rear == Max - 1) {
    printf("\nThe queue is full, cannot push");
  } 
  else {
    if (dq -> front == -1 && dq -> rear == -1) {
      dq -> front++;
    }
    for (int i = dq -> rear; i >= dq -> front; i--) {
      dq -> array[i + 1] = dq -> array[i];
    }
    ++dq -> rear;
    dq -> array[dq -> front] = key;
  }
}


char * pop(Queue * dq) {
  char * temp = dq -> array[dq -> front];
  dq -> front++;
  if (dq -> front > dq -> rear) {
    dq -> front = -1;
    dq -> rear = -1;
  }
  return temp;
}


int main() {
    Queue dq;
    dq.front = -1;
    dq.rear = -1;
    int ch = 0;
    char * ele;
    while (1) {
      printf("\n1 : Display the Queue \n2 : Pop \n3 : Push element from Right\n4 : Push element from Left");
      printf("\nEnter the operation to be done: ");
      scanf("%d", & ch);
      switch (ch) {
      case 1:
        print(dq);
        break;
      case 2:
        if (dq.front == -1 && dq.rear == -1) {
           printf("\nThe queue is empty");
        } 
        else {
          ele = pop( & dq);
          printf("\nElement popped is %s", ele);
        }
        break;
      case 3:
        ele = (char * ) calloc(100, sizeof(char));
        printf("\nEnter the element : ");
        scanf(" %s", ele);
        pushRight( & dq, ele);
        break;
      case 4:
        ele = (char * ) calloc(100, sizeof(char));
        printf("\nEnter the element : ");
        scanf(" %s", ele);
        pushLeft( & dq, ele);
        break;
      }
      printf("\n");
    }
    return 0;
  }