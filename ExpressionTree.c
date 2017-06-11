#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>

struct node{
  char info;
  struct node* left;
  struct node* right;
};
typedef struct node* NODE;
struct stack{
  int top;
  NODE arr[20];
};
NODE get_node(){
  NODE temp;
  temp=(NODE)malloc(sizeof(struct node));
  if(temp==NULL){
    printf("No space\n" );
  }
  return temp;
}
void push(struct stack *s,NODE ele){
  if(s->top==19){
    printf("Owerflow\n" );
  }
  else{
    (s->top)++;
    s->arr[s->top]=ele;
  }

}
NODE pop(struct stack *s){
  NODE del;
  if(s->top==-1){
    printf("Underflow\n" );

  }
  else{
    del=s->arr[s->top];
    (s->top)--;
  }
  return del;
}
NODE create(char postfix[]){
  char ch;
  NODE tree,temp;
  NODE lc,rc;
  struct stack s;
  s.top=-1;
  int i=0;
  for(i=0;i<strlen(postfix);i++){
    ch=postfix[i];
    temp=get_node();
    temp->info=ch;
    temp->left=temp->right=NULL;
    if(isdigit(ch)){
      push(&s,temp);
    }
    else{
      rc=pop(&s);
      lc=pop(&s);
      temp->left=lc;
      temp->right=rc;
      push(&s,temp);
    }

  }
  tree=pop(&s);
  return tree;
}
float evaluate(NODE tree)
{
    switch(tree->info)
    {
    case '+':return (evaluate(tree->left)+evaluate(tree->right));
    case '-':return (evaluate(tree->left)-evaluate(tree->right));
    case '*':return (evaluate(tree->left)*evaluate(tree->right));
    case '/':return (evaluate(tree->left)/evaluate(tree->right));
    case '^':return (pow(evaluate(tree->left),evaluate(tree->right)));
    case '$':return (pow(evaluate(tree->left),evaluate(tree->right)));
    default: return ((tree->info)-'0');
    }
}
int main(){
  NODE tree;
  float res;
  char postfix[20];
  printf("Enetr postfix :\n" );
  scanf("%s",postfix);
  tree=create(postfix);
  res=evaluate(tree);
  printf("Result : %f\n",res );
  return 0;
}
