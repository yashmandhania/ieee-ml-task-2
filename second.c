#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define STACK_SIZE 50
#define EXPR_SIZE 50
typedef enum {lparan,rparan,plus,minus,times,divide,mod,eos,operand}PRECEDENCE;

int stack[STACK_SIZE];
char expr[EXPR_SIZE];

void push(int * top, int item) {
  stack[++( * top)] = item;
}

int pop(int * top) {
  return stack[( * top) --];
}


PRECEDENCE get_token(char * symbol, int * n) {
  * symbol = expr[( * n) ++];
  switch ( * symbol) {
  case '+':
    return plus;
  case '-':
    return minus;
  case '*':
    return times;
  case '/':
    return divide;
  case '%':
    return mod;
  case '(':
    return lparan;
  case ')':
    return rparan;
  case '\0':
    return eos;
  default:
    return operand;
  }
}
int eval() {
  PRECEDENCE token;
  char symbol;
  int n = 0, c;
  int op1, op2;
  int top = -1;
  token = get_token( & symbol, & n);
  while (token != eos) {
    if (token == operand) {
      c = symbol - '0';
      push( & top, c);
    } else {
      op2 = pop( & top);
      op1 = pop( & top);
      if (token == plus) {
        push( & top, op2 + op1);
      } else if (token == minus) {
        push( & top, op2 - op1);
      } else if (token == times) {
        push( & top, op2 * op1);
      } else if (token == divide) {
        push( & top, op2 / op1);
      } else if (token == mod) {
        push( & top, op2 % op1);
      }
    }
    token = get_token( & symbol, & n);
    //printf("%d\n",stack[top]);
  }
  return pop( & top);
}
int main() {
  char ex[50];
  int i, j = 0;
  printf("ENTER PREFIX EXPRESSION -\n");
  scanf("%s", ex);
  for (i = strlen(ex) - 1; i >= 0; i--) {
    expr[j] = ex[i];
    j++;
  }
  expr[j] = '\0';
  printf("Reverse is %s\n", expr);
  printf("\nAnswer: %d\n", eval());
  return 0;
}