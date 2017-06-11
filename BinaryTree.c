#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node {
  int info;
  struct node* left;
  struct node* right;
};
typedef struct node* NODE;
NODE get_node(int x){
  NODE temp;
  temp=(NODE)malloc(sizeof(struct node));
  if(temp==NULL){
    printf("No space \n");
  //  return ;
  }
  temp->info=x;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}
NODE insert_node(NODE p,int x){
  int dir;

  //NODE temp=p;
  scanf("%d",&dir);
  //printf("oki......\n");
  if(dir==3|| p==NULL){
    //printf("clown......\n" );
    if(p==NULL){
      //printf("king  ...\n" );
      p=get_node(x);
    //  return p;
    }
    else
      printf("No memeory \n");
  }
  else{
  if(dir==1)
    p->left=insert_node(p->left,x);
  else if(dir==2)
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
              printf("Enter the direction l or r and q to end\n");
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
