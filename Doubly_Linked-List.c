
#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

struct node
{
	struct node *prev;
	int data;
	struct node *next;
};

void AddAtEnd(struct node **,int);
void AddAtBeg(struct node **,int);
void AddAtPos(struct node **,int,int);
void DelAtEnd(struct node **);
void DelAtBeg(struct node **);
void DelAtPos(struct node **,int);
int CountNodes(struct node *);
void Display(struct node *);
void RevDisplay(struct node *,int);

void main()
{
	struct node *Head=NULL;
	int choice,x,pos,no_of_nodes;
	


while(1)
{
	printf("\n\n********** Linked List **********\n");
	printf("Choose a option: \n");
	printf("1.Enter a Node at End.\n");
	printf("2.Enter a Node at Begining.\n");
	printf("3.Enter a Node at Position.\n");
	printf("4.Delete a Node at End.\n");
	printf("5.Delete a Node at Begining.\n");
	printf("6.Delete a Node at Position.\n");
	printf("7.Display Linked List.\n");
	printf("8.Count the Nodes in linked list.\n");
	printf("9.Reverse Display of linked list.\n");
	printf("0.Exit.\n\n");
	printf("Enter your choice: ");
	scanf("%d",&choice);
        __fpurge(stdin);
	switch(choice)
	{
		case 0:
			exit(0);
			break;
		
		case 1:
			printf("Enter the Data: ");
			scanf("%d",&x);
			AddAtEnd(&Head,x);
			break;

		case 2:
			printf("Enter the Data: ");
			scanf("%d",&x);
			AddAtBeg(&Head,x);
			break;

		case 3:
			printf("Enter the Data and Pos: ");
			scanf("%d %d",&x,&pos);
			AddAtPos(&Head,x,pos);
			break;

		case 4:
			DelAtEnd(&Head);
			break;

		case 5:
			DelAtBeg(&Head);
			break;

		case 6:
			printf("Enter Position to Delete: ");
			scanf("%d",&pos);
			DelAtPos(&Head,pos);
			break;
			

		case 7:
			printf("\n\n---------- Linked List -----------\n");			
			Display(Head);
			break;

			
		case 8:
			no_of_nodes=CountNodes(Head);
			printf("\n %d nodes are there in linked list.",no_of_nodes);
			break;
			
		case 9:
			no_of_nodes=CountNodes(Head); 
			
			if(Head==NULL)
			{
				printf("\n Doubly Linked List is Empty. \n");
			}
			else
			{
			RevDisplay(Head,no_of_nodes);
			printf("\b\b\b\b     \n\n");
			}
			 break;

		default:
			printf("\nInvalid Choice !! Try Again.\n");
			break;
	}	
}

}



void AddAtBeg(struct node **TempHead,int x)
{
	struct node *Temp;
	Temp=(struct node *)malloc(sizeof(struct node));
	
	Temp->prev=NULL;
	Temp->data=x;
	Temp->next=NULL;
   
if(*TempHead==NULL)
{
	*TempHead=Temp;
}
else
{
	Temp->next=*TempHead;
	(*TempHead)->prev=Temp;
	*TempHead=Temp;
}
}

void Display(struct node *TempHead)
{
	struct node *t1;
	t1=TempHead;
	if(TempHead==NULL)
	{
		printf("\n Doubly Linked List is Empty. \n");
	}
	else
	{
	while(t1!=NULL)
	{
		
		printf("%d --> ",t1->data);
		t1=t1->next;
	}
printf("\b\b\b\b     \n\n");
	}
}




void AddAtEnd(struct node **TempHead,int x)
{
	struct node *Temp;
	Temp=(struct node *)malloc(sizeof(struct node));
	Temp->prev=NULL;
	Temp->data=x;
	Temp->next=NULL;
	
	if(*TempHead==NULL)
	{
		*TempHead=Temp;
	}
	else
	{
		struct node *t1;
		
		t1=*TempHead;
		while(t1->next!=NULL)
		{
			t1=t1->next;
		}

		t1->next=Temp;
		Temp->prev=t1;	 
	}
}

void AddAtPos(struct node **TempHead,int x,int pos)
{
struct node *Temp;
int i=0;
Temp=(struct node *)malloc(sizeof(struct node));
Temp->prev=NULL;
Temp->data=x;
Temp->next=NULL;

if(pos<=0)
{
	printf("\n Invalid Position \n");
}
else if(pos==1)
{
 *TempHead=Temp;

}
else
{
struct node *t1,*t2;
t1=*TempHead;

	while(++i<(pos))
	{
		t2=t1;
		t1=t1->next;
	}

Temp->prev=t2;
Temp->next=t1;

t1->prev=Temp;
t2->next=Temp;

}

}


void DelAtBeg(struct node **TempHead)
{
int count;
struct node *Temp;
Temp=*TempHead;


count=CountNodes(*TempHead);

if(count==1)
{
*TempHead=NULL;
free(*TempHead);
}
else if(*TempHead==NULL)
{
	printf("\n Doubly Linked List is Empty. \n");
}
else
{
*TempHead=Temp->next;
Temp->next->prev=NULL;
free(Temp);

}
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
	printf("\n Doubly Linked List is Empty. \n");
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

void DelAtPos(struct node **TempHead,int pos)
{
struct node *Temp1,*Temp2;
int i=0,count;
Temp1=*TempHead;
count=CountNodes(*TempHead);

if(pos<=0)
{
	printf("\n Invalid Position\n");
}
else if(count==0)
{
	printf("\n Doubly Linked List is Empty. \n");
}
else
{
	if(pos==1)
	{
	*TempHead=Temp1->next;
	free(Temp1);
	}
	else
	{
	while(++i<pos)
	{
		Temp2=Temp1;
		Temp1=Temp1->next;	
	}
	Temp2->next=Temp1->next;

	if(Temp1->next!=NULL)
	{
	Temp1->next->prev=Temp2;
	}
	else
	{
	Temp2->next=NULL;
	}
	free(Temp1);
	
	}
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

//printf("\n %d nodes are there in linked list.",count);
return count;
}
}



void RevDisplay(struct node *TempHead,int count)
{
if(count==0)
	return;
else
{
	
	RevDisplay(TempHead->next,--count);
	printf("%d --> ",TempHead->data);
	

}
}

