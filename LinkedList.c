#include<stdio.h>
#include<stdlib.h>

struct node {
  int info;
  struct node* link;
};
typedef struct node* NODE;
NODE getnode(){
  NODE temp;
  temp=(NODE)malloc(sizeof(struct node));
  if(temp==NULL){
    printf("No space \n" );
    return;
  }
  return temp;
}
NODE in_beg(NODE root,int ele){
  NODE temp;
  temp=getnode();
  temp->info=ele;
  temp->link=root;
  return temp;
}
NODE del_beg(NODE root){
  NODE temp;
  temp=root;
  if(root==NULL){
    return temp;
  }
  printf("%d is deleted\n",temp->info);
  root=root->link;
  free(temp);
  return root;
}
NODE in_rear(NODE root,int ele){
  NODE temp,curr;
  temp=getnode();
  temp->info=ele;
  temp->link=NULL;
  curr=root;
  if(root==NULL){
    return temp;
  }
  while(curr->link!=NULL){
    curr=curr->link;
  }
  curr->link=temp;
  return root;
}
NODE del_rear(NODE root){
  NODE temp,prev,curr;
  if(root==NULL){
        printf("UNderflow\n");
        return NULL;
  }
  if(root->link==NULL){
    printf("%d item deleted\n",root->info);
    free(root);
    return NULL;
  }
  curr=root;
  prev=NULL;
  while(curr->link!=NULL){
    prev=curr;
    curr=curr->link;
  }
  temp=curr;
  prev->link=NULL;
  printf("%d item deleted\n",temp->info);
  free(temp);
  return root;
}
NODE in_pos(NODE root,int ele,int pos){
  NODE temp,curr;
  int i=0;
  curr=root;
  temp=getnode();
  temp->info=ele;
  for(i=1;i<pos-1;i++){
    curr=curr->link;
  }
  temp->link=curr->link;
  curr->link=temp;
  return root;
}
NODE del_pos(NODE root,int pos){
  NODE curr,prev;
  int i=0;
  if(root==NULL){
    printf("Nothing to delete \n" );
    return NULL;
  }
  if(pos==1){
    printf("%d is delted\n",root->info);
    free(root);
    return NULL;
  }
  curr=root;
  prev=NULL;
  for(i=1;i<pos-1;i++){
    prev=curr;
    curr=curr->link;
  }
  prev->link=curr->link;
  printf("%d is delted\n",curr->info);
  free(curr);
  return root;
}
void display(NODE root){
  if(root==NULL){
    printf("No elements\n");
  }
  while(root!=NULL){
    printf("%d\t",root->info);
    root=root->link;
  }
  printf("\n");
}
int main()
{
    NODE root=NULL;
    int ch,pos,x,n=1;
    printf("Enter choice\n");
    while( n==1)
    {
        printf("\n\n\n1.Insert Front\n");
        printf("2.Insert Rear\n");
        printf("3.Delete Front\n");
        printf("4.Delete Rear\n");
        printf("5.Display\n");
        //printf("6.Search"<<endl;
        printf("7.Insert at position\n");
        printf("8.Delete at position\n");
        //printf("9.Delete all instances of"<<endl;
        printf("10.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\nEnter the element to enter : ");
            scanf("%d",&x);
            root=in_beg(root,x);
            break;
        case 2:
            printf("\nEnter the element to enter : ");
            scanf("%d",&x);
            root=in_rear(root,x);
            break;
        case 3:
            root=del_beg(root);
            break;
        case 4:
            root=del_rear(root);
            break;
        case 5:
            printf("\nList:  ");
            display(root);
            break;

        case 7:
            printf("\nEnter Position to Insert at : ");
            scanf("%d",&pos);
            if(pos<=0)
            {
                printf("\nWrong Position");
                break;
            }
            printf("\nEnter the element to insert : ");
            scanf("%d",&x);
            root=in_pos(root,x,pos);
            break;
        case 8:
            printf("\nEnter Position to Delete at : ");
            scanf("%d",&pos);
            if(pos<=0)
            {
                printf("\nWrong Position");
                break;
            }
            root=del_pos(root,pos);
            break;

        case 10:
            n=0;
            break;
        default:
            printf("\nWrong Input.");
            break;
        }
    }
    return 0;
}
