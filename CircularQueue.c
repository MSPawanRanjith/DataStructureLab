#include<stdio.h>
#include<stdlib.h>

int size=5;
int count=0;
void insert(int q[],int *r,int *f,int item){
  if(count==size){
    printf("Owerflow\n" );
    return;
  }
  *r=(*r+1)%size;
  q[*r]=item;
  count++;
}
void delete(int q[],int *r,int *f){
  if(count==0){
    printf("Underflow \n" );
    return;
  }
  int item_del=q[*f];
  printf("%d is deleted \n",item_del );
  *f=(*f+1)%size;
  count--;
}
void display(int q[],int *r,int *f){
  if(count==0){
    printf("No elements \n" );
    return;
  }
  int j;
  int i=*f;
  for( j=1;j<=count;j++){
    printf("%d\t",q[i] );
    i=(i+1)%size;
  }
  printf("\n" );
}
void main(){
  int q[size],item,ch;
  int r,f;
  r=-1;
  f=0;
  for(;;){
    printf("Enter the choice \n" );
    scanf("%d",&ch );
    switch (ch) {
      case 1: printf("Enter the item \n");
              scanf("%d",&item);
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
