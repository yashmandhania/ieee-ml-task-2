#include <stdio.h>
#define SIZE 100
int ar[SIZE];
int top1 = -1;
int top2 = SIZE;
void push_stack1(int data)
{
    if (top1 < top2 - 1)
    {
        ar[++top1] = data;
    }
    else
    {
        printf("Stack Full! Cannot Push\n");
    }
}
void push_stack2(int data)
{
    if (top1 < top2 - 1)
    {
        ar[--top2] = data;
    }
    else
    {
        printf("Stack Full! Cannot Push\n");
    }
}
void pop_stack1()
{
    if (top1 >= 0)
    {
        int popped_value = ar[top1--];
        printf("%d is being popped from Stack 1\n", popped_value);
    }
    else
    {
        printf("Stack Empty! Cannot Pop\n");
    }
}
void pop_stack2()
{
    if (top2 < SIZE)
    {
        int popped_value = ar[top2++];
        printf("%d is being popped from Stack 2\n", popped_value);
    }
    else
    {
        printf("Stack Empty! Cannot Pop\n");
    }
}
void print_stack1()
{
    int i;
    for (i = top1; i >= 0; --i)
    {
        printf("%d ", ar[i]);
    }
    printf("\n");
}
void print_stack2()
{
    int i;
    for (i = top2; i < SIZE; ++i)
    {
        printf("%d ", ar[i]);
    }
    printf("\n");
}
int main()
{
    int ar[SIZE];
    int n,m,k,v;
    int num_of_ele;
    printf("enter the size of stack 1:");
    scanf("%d",&n);
    printf("We can push a total of %d values\n",n);
    for (int i = 0; i < n; ++i){
        int v=0;
        printf("enter value to be pushed:");
        scanf("%d",&v);
        push_stack1(v);
    }
    printf("\n");
    printf("enter size of stack 2:");
    scanf("%d",&m);
    for (int i = 0; i < m ; ++i){
        int k=0;
        printf("enter value to be pushed:");
        scanf("%d",&k);
        push_stack2(k);
    }
    //Print Both Stacks
    print_stack1();
    print_stack2();
    printf("\n");
    //Popping All Elements From Stack 1
    num_of_ele = top1 + 1;
    while (num_of_ele)
    {
        pop_stack1();
        --num_of_ele;
    }
    printf("\n");
    //Trying to Pop From Empty Stack
    pop_stack1();
    return 0;
}