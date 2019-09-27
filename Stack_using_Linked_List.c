#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void AddAtBeg(struct node **,int);
void DelAtBeg(struct node **);
void DelAtPos(struct node **,int);
int CountNodes(struct node *);
void Display(struct node *);

void main()
{
	struct node *Head=NULL;
	int choice,x,pos,no_of_nodes;
	


while(1)
{
	printf("\n\n********** STACK **********\n");
	printf("Choose a option: \n");
	printf("1.Push\n");
	printf("2.Pop\n");
	printf("3.Display Stack\n");
	printf("4.Count the elements in stack\n");
	printf("0.Exit.\n\n");
	printf("Enter your choice: ");
	scanf("%d",&choice);

	switch(choice)
	{
		case 0:
			exit(0);
			break;

		case 1:
			printf("Enter the Data: ");
			scanf("%d",&x);
			AddAtBeg(&Head,x);
			break;

		case 2:
			DelAtBeg(&Head);
			break;

		case 3:
			printf("\n\n---------- STACK -----------\n");			
			Display(Head);
			break;
		case 4:
			no_of_nodes=CountNodes(Head);
			printf("\n %d nodes are there in Stack.",no_of_nodes);
			break;
			
		default:
			printf("\nInvalid Choice !! Try Again.");
			break;
	}	
}

}



void AddAtBeg(struct node **TempHead,int x)
{
	struct node *Temp;
	Temp=(struct node *)malloc(sizeof(struct node));
	Temp->data=x;
	Temp->next=NULL;

	Temp->next=*TempHead;
	*TempHead=Temp;
}

void Display(struct node *TempHead)
{
	
	while(TempHead!=NULL)
	{
		
		printf(" | %d | \n",TempHead->data);
		TempHead=TempHead->next;
	}
}



void DelAtBeg(struct node **TempHead)
{

struct node *Temp;
Temp=*TempHead;

if(*TempHead==NULL)
{
	printf("\nStack is Empty.");
}
else
{
*TempHead=Temp->next;
free(Temp);
}
}

int CountNodes(struct node *TempHead)
{
int count=1;

if(TempHead==NULL)
{
	return 0;
}
else
{
while(TempHead->next!=NULL)
{
	count++;
	TempHead=TempHead->next;
}


return count;
}
}

