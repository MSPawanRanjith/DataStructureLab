#include <stdio.h>

int gcd(int n1,int n2){
  if(n2!=0){
    gcd(n2,n1%n2);
  }
  else
    return n1;
}
void main (/* arguments */) {
  /* code */
  int n1,n2;
  printf("Enetr the both values \n" );
  scanf("%d%d",&n1,&n2);
  printf("The res %d\n",gcd(n1,n2) );
}
