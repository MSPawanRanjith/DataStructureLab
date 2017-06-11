#include<stdio.h>
#include<stdlib.h>

struct node{
  int info;
  struct node *left;
  struct node *right;
};
typedef struct node* NODE;
NODE get_node(){
  NODE temp;
  temp=(NODE)malloc(sizeof(struct node));
  if(temp==NULL){
    printf("No space\n" );
    return 0;
  }
  return temp;
}
NODE i_order(NODE root,int ele){
  NODE temp,curr,prev;
  temp=get_node();
  temp->info=ele;
  temp->left=temp->right=NULL;
  curr=root;
  prev=NULL;
  if(root==NULL){
    return temp;
  }
  if(ele<root->info){
    while(curr!=NULL && ele<root->info){
      prev=curr;
      curr=curr->right;
    }
    temp->right=curr;
    temp->left=prev;
    prev->right=temp;
    if(curr!=NULL)
     curr->left=temp;
    return root;
  }
  temp->right=root;
  root->left=temp;
  return temp;

}
NODE delete(NODE root){
  if(root==NULL){
    printf("Underflow\n" );
    return NULL;
  }
  NODE temp=root;
  printf("%d is deleted\n",temp->info);
  root=root->right;
  free(temp);
  return root;
}
void display(NODE root)
{
    NODE curr;
    if(root==NULL)
        printf("list full\n");
    else
    {
        curr=root;
        while(curr!=NULL)
        {printf("%d\t",curr->info); curr=curr->right;}
        printf("\n");
    }
}

int main()
{
    NODE root;
    root=NULL;
    int ele,i;
    for(;;)
    {
        printf("enter 1 to input element in list, 2 to display 3\n");
        scanf("%d",&i);
        switch(i)
        {
        case 1:
            printf("enter element\n");
            scanf("%d",&ele);
            root=i_order(root,ele);
            break;
        case 2: root=delete(root);
                break;
        case 3:
            display(root); break;
        default: exit(0);
        }
    }
    return 0;
}
