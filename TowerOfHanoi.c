#include<stdio.h>
void tower(int n,char s,char d,char t){
  if(n==1){
    printf("Move %d disk from %c to %c \n",n,s,d);
    return;
  }
  tower(n-1,s,t,d);
  printf("Move %d disk from %c to %c \n",n,s,d);
  tower(n-1,t,d,s);
}
void main(){
  int n;
  scanf("%d",&n);
  tower(n,'A','C','B');
}
