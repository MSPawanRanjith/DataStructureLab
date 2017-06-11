#include<stdio.h>
#include <string.h>
#include<math.h>
int size=20;
double op(char symbol, double op1, double op2)
{
	switch(symbol)
	{
		case '+':
			return op1 + op2;

		case '-':
			return op1 - op2;

		case '*':
			return op1 * op2;

		case '/':
			return op1 / op2;

		case '$':
		case '^':
			return pow(op1,op2);
	}
}
void push(double item, double s[],int *top)
{
	(*top)++;
	s[*top] = item;
}
double pop( double s[],int *top)
{
	double item_deleted;

	item_deleted = s[*top];
	(*top)--;

	return item_deleted;
}
int isDigit(char symbol)
{
	return (symbol >= '0' && symbol <= '9');
}
int main(){
  double s[size],op1,op2,res;
  int top,i=0;
  char postfix[size],symbol;
  top=-1;
  printf("Enter the \n" );
  scanf("%s",postfix );
  for (i= 0; i< strlen(postfix); i++) {
    symbol=postfix[i];
    if(isDigit(symbol)){
      push(symbol - '0',s,&top);
    }
    else{
      op2=pop(s,&top);
      op1=pop(s,&top);
      res=op(symbol,op1,op2);
      push(res,s,&top);
    }

  }
  res=pop(s,&top);
  printf("The result :  %lf ",res);
  return 0;
}
