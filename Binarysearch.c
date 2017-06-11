#include<stdio.h>

int binary(int a[],int ele,int low ,int high){
  int mid;
  if(low>high)
    return -1;
  mid=(low+high)/2;
  if(ele==a[mid])
    return mid+1;
  if(ele<a[mid])
      binary(a,ele,low,mid-1);
  else
      binary(a,ele,mid+1,high);

}
void main(/* arguments */) {
  /* code */
  int a[10],ele,pos;
  for(int i=0;i<4;i++){
    scanf("%d",&a[i] );
  }
  printf("Enetr the ele \n" );
  scanf("%d",&ele );
  pos=binary(a,ele,0,3);
  if(pos>0)
    printf("Element found : %d\n",pos );
  else
    printf("Element not found\n");
}
