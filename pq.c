#include <stdio.h>
#include <stdlib.h>

#define Max 50

typedef struct
{
    int front;
    int rear;
    int list[Max];
} Queue;

void initialise(Queue apq)
{
    apq.front = -1;
    apq.rear = -1;
}

void display(Queue apq)
{
    if (apq.front == -1 && apq.rear == -1)
    {
        printf("\n\nThe queue is empty.");
    }
    else
    {
        printf("\n");
        for (int i = apq.front; i <= apq.rear; i++)
        {
            printf("%3d", apq.list[i]);
        }
    }
}

void pqinsert(Queue *apq, int num)
{
    if (apq->rear == Max - 1)
    {
        printf("queue is full");
    }

    else
    {
        if (apq->rear == -1 && apq->front == -1)
        {
            apq->front++;
        }
        int val;
        for (int i = apq->front; i <= apq->rear; i++)
        {
            if (apq->list[i] <= num)
            {
                val = i + 1;
            }
        }
        for (int i = apq->rear; i >= val; i--)
        {
            apq->list[i + 1] = apq->list[i];
        }
        apq->rear++;
        apq->list[val] = num;
    }
}

int pqdel(Queue *apq){
        int pop = apq->list[apq->front];
        apq->front++;
        if (apq->front > apq->rear)
        {
            apq->front = -1;
            apq->rear = -1;
        }
        return pop;

}

int main()
{
    Queue q;
    q.front=-1;
    q.rear=-1;
    int choice = 0, ele;
    while (1)
    {
        printf("\n1: Display the Queue \n2 : Pop \n3: Push an element");
        printf("\nEnter the operation to be done: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display(q);
            break;
        case 2:
            if (q.rear == -1 && q.front == -1){
                printf("\nqueue is empty");
                }
            else{
            	ele = pqdel(&q);
            	printf("\nElement poppped is %d", ele);
            }
            break;
        case 3:
            printf("\nEnter the element to be pushed : ");
            scanf("%d", &ele);
            pqinsert(&q, ele);
            break;
        }
        printf("\n");
    }
    return 0;
}
