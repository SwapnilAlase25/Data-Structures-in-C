#include<stdio.h>
#include<stdlib.h>

struct bst 
{
struct bst *left;
int data;
struct bst *right;
};

void insert(struct bst **,int);
void preorderdis(struct bst *);
void inorderdis(struct bst *);
void postorderdis(struct bst *);

void main()
{
struct bst *root=NULL;
int choice,x;
while(1)
{	
printf("\n\n*****Binary Search Tree*****\n");
printf("1.Insert\n");
printf("2.Preorder\n");
printf("3.Inorder\n");
printf("4.Postorder\n");
printf("5.Exit\n");
printf("Enter choice\n");
scanf("%d",&choice);
printf("\n");

switch(choice)
   { 
     case 1:
            printf("Enter node :\n");
            scanf("%d",&x);	    
            insert(&root,x);
	    break;
     case 2:
             printf("Preorder:\n");
             preorderdis(root);	     
             break;
     case 3:
             printf("Inorder:\n");
             inorderdis(root);
             break;
     case 4:
             printf("Postorder:\n");
             postorderdis(root);
             break;

     case 5:
             exit(1);	     
     default :
              printf("\nInvalid choice\n");	     

 }
}
}	

void insert(struct bst **r,int x)
{
if(*r==NULL)
{	
(*r)=(struct bst *)malloc(sizeof(struct bst));
(*r)->left=NULL;
(*r)->right=NULL;
(*r)->data=x;
}
else
   {     
	if(x<((*r)->data)) 
     {
     insert(&((*r)->left),x);
     }
     else  
     {
     insert(&((*r)->right),x);	
     }	
    }
}


void preorderdis(struct bst *r)
{
if(r!=NULL)
  {
   printf("%d ",r->data);
   preorderdis(r->left);
   preorderdis(r->right);
   }
}


void inorderdis(struct bst *r)
{
if(r!=NULL)
  {
  inorderdis(r->left);
  printf("%d ",r->data);
  inorderdis(r->right);
   }	
}	


void postorderdis(struct bst *r)
{
if(r!=NULL)
  {
  postorderdis(r->left);
  postorderdis(r->right);
  printf("%d ",r->data);
  }	
}
