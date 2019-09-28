#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void AddAtBeg(struct node **,int);
void DelAtEnd(struct node **);
int CountNodes(struct node *);
void Display(struct node *);

void main()
{
	struct node *Head=NULL;
	int choice,x,pos,no_of_nodes;
	


while(1)
{
	printf("\n\n********** Queue **********\n");
	printf("Choose a option: \n");
	printf("1.Insert\n");
	printf("2.Delete\n");
	printf("3.Display Queue\n");
	printf("4.Count the Elements in Queue\n");
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
			DelAtEnd(&Head);
			break;

		case 3:
			printf("\n\n---------- Queue -----------\n");			
			Display(Head);
			break;
		case 4:
			no_of_nodes=CountNodes(Head);
			printf("\n %d elements are there in Queue.",no_of_nodes);
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
		
		printf("%d --> ",TempHead->data);
		TempHead=TempHead->next;
	}
printf("\b\b\b\b     \n\n");
}




void DelAtEnd(struct node **TempHead)
{
struct node *Temp1, *Temp2;
int count;
Temp1=*TempHead;
count=CountNodes(*TempHead);

if(count==1)
{
*TempHead=NULL;
free(*TempHead);
}
else if(*TempHead==NULL)
{
	printf("\nQueue is Empty.");
}
else
{
	while(Temp1->next!=NULL)
	{
		Temp2=Temp1;
		Temp1=Temp1->next;
	}
	Temp2->next=NULL;
	free(Temp1);

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


