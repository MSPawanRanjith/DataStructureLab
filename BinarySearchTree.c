#include<stdio.h>
#include<stdlib.h>

struct node{
  int info;
  struct node *left;
  struct node *right;
};
typedef struct node* NODE;
NODE get_node(int x){
  NODE temp;
  temp=(NODE)malloc(sizeof(struct node));
  if(temp==NULL)
    printf("No space \n");
  temp->info=x;
  temp->left=NULL;
  temp->right=NULL;  
  return temp;
}
NODE insert_node(NODE p,int x){
  if(p==NULL){
    p=get_node(x);
  }
  else{
    if(p->info>x)
      p->left=insert_node(p->left,x);
    else if(p->info<x)
      p->right=insert_node(p->right,x);

  }
  return p;
}
void inorder(NODE p){
  if(p!=NULL){
    inorder(p->left);
    printf("%d\t",p->info );
    inorder(p->right);

  }

}
int main() {
  NODE root;
  root=NULL ;
  int x;
  int ch;
  for(;;){
    printf("Enter the choice \n" );
    scanf("%d",&ch );
    switch (ch) {
      case 1: printf("Enter the value : \n");
              scanf("%d",&x );
            //  printf("Enter the direction l or r and q to end\n");
              root=insert_node(root,x);
              break;
      case 2: printf("Inorder \n");
              inorder(root);
              break;
      default: exit(0);
    }
  }
  return 0;
}
