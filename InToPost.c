#include<stdio.h>
#include <string.h>

int size=20;

void push(int item,char s[],int *top){
  if(*top==size-1){
    printf("Overflow \n" );
    return;
  }
  s[++(*top)]=item;
}
char pop(char s[],int* top){
  if(*top==-1){
    printf("Underflow \n");
    return 0;
  }
  int item_del=s[(*top)--];
  return item_del;
}
int f(char symbol){
  switch (symbol) {
    case '+':
    case '-': return 2;
    case '*':
    case '/':return 4;
    case '^':return 5;
    case '(':return 0;
    case '#':return -1;
    default : return 8;
  }
}
int g(char symbol){
  switch (symbol) {
    case '+':
    case '-': return 1;
    case '*':
    case '/':return 3;
    case '^':return 6;
    case '(':return 9;
    case ')':return 0;
    default : return 7;
  }
}
void in_post(char infix[],char postfix[]){
  char s[size],symbol;
  int top,i,j=0;
  top=-1;
  push('#',s,&top);
  for(i=0;i<strlen(infix);i++){
    symbol=infix[i];
    while(f(s[top])>g(symbol)){
      postfix[j]=pop(s,&top);
      j++;
    }
    if(f(s[top])!=g(symbol)){
      push(symbol,s,&top);
    }
    else
      pop(s,&top);
  }

  while(s[top]!='#'){
    postfix[j]=pop(s,&top);
    j++;
  }
  postfix[j]='\0';

}
void main(){
  char infix[size],postfix[size];
  printf("Enter the infix expression :" );
  scanf("%s",infix);
  in_post(infix,postfix);
  printf("\n The postfix form is :\n" );
  printf("%s\n",postfix );

}
