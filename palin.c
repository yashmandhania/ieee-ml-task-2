#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Max 100

typedef struct{
	int front;
	int rear;
	char list[Max];
}Queue;

void pushRight(Queue *dq,char key){
	if(dq->rear == Max - 1){
		printf("Queue id full");
		}
	else{
		if(dq->rear == -1 && dq->front == -1){
			dq->front++;
		}
		dq->list[++dq->rear] = key;
	}
}

char popleft(Queue *dq){
	char temp = dq->list[dq->front];
    dq->front++;

    if (dq->front > dq->rear){
		dq->front = -1;
		dq->rear = -1;
	}
	return temp;
}

char popright(Queue *dq){
	char temp = dq -> list[dq->rear];
	dq->rear--;

	if (dq->front > dq->rear){
		dq->front = -1;
		dq->rear = -1;
	}
	return temp;
}

int main(){
	Queue q;
	q.front=-1;
	q.rear=-1;
	char ele[100];
	printf("enter string to check for pallindrome:");
	scanf("%s",ele);

	int n = strlen(ele);
	for(int i = 0; i<n; i++){
		pushRight(&q, ele[i]);
	}

	n = n/2;
	int p = 1;
	while(n--){

		if(popleft(&q)!=popright(&q)){
		p = 0;
		break;

		}
	}
	if (p==1){
		printf("Sting is pallindrome");
		printf("\n");
	}

	else{
		printf("Not a pallindrome!!!!!");
		printf("\n");
	}
    return  0 ;
}
