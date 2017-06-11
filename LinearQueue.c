#include<stdio.h>
#include<stdlib.h>
int size=10;

void insert(int q[],int *r,int *f,int item ){
  if(*r==size-1){
    printf("Owerflow \n" );
    return;
  }
  (*r)++;
  q[*r]=item;
}
void delete (int q[],int *r,int *f){
  if(*f>*r){
    printf("Underflow \n" );
    return ;
  }
  int item_del=q[*f];
  (*f)++;
  printf("%d deleted",item_del);
  if(*f>*r){
    *f=0;
    *r=-1;
  }
}
void display(int q[],int *r,int *f){
  int i;
  if(*f>*r){
    printf("no elements \n");
    return;
  }
  for(i=*f;i<=*r;i++){
    printf("%d\t",q[i] );
  }
  printf("\n" );
}
void main(){
  int q[size],r,f;
  r=-1;
  f=0;
  int ch,item;
  for(;;){
  printf("Enter the choice \n" );
  scanf("%d",&ch );
  switch (ch) {
    case 1: printf("Enetr the element \n" );
            scanf("%d",&item );
            insert(q,&r,&f,item);
            break;
    case 2: delete(q,&r,&f);
            break;
    case 3: display(q,&r,&f);
            break;
    default: exit(0);
  }
}
}
