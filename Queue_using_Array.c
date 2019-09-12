#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

void push(int [],int*,int);
void pop(int [],int*);
void display(int [],int*);

void main()
{
	int queue[SIZE],r=-1,i,choice,data;

	while(1)
	{
		printf("\n\n********** Queue **********\n");
		printf("1.Push data in Queue.\n");
		printf("2.Pop data out of Queue.\n");
		printf("3.Display data in Queue.\n");
		printf("4.Count data in Queue.\n");
		printf("0.Exit\n");
		printf("Enter a choice: ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("\nEnter Data: ");
				scanf("%d",&data);
				push(queue,&r,data);
				break;
			case 2:
				pop(queue,&r);
				break;
			
			case 3:
				display(queue,&r);
				break;
			case 4:
				printf("\nCount is %d\n",r+1);
				break;
			case 0:
				exit(0);

			default:
				printf("\n Invalid Choice, Try Again.");
				break;
		}



	}

}


void push(int queue[SIZE],int *r,int data)
{

	if(*r==(SIZE-1))
	{
		printf("\n Queue is Full. \n");
	}
	else
	{
		(*r)++;
		queue[*r]=data;
		printf("\n Push Successful. \n");
	}

}


void pop(int queue[SIZE],int *r)
{

	int i=0;

	if(*r==-1)
	{
		printf("\n Queue is Empty. \n");
	}
	else
	{

		queue[0]=0;
		
		for(i=0;i<=*r;i++)
		{
			queue[i]=queue[i+1];
		}
		
		(*r)--;
		
		printf("\n Pop Successful. \n");

	}
}

void display(int queue[SIZE],int *r)
{

int i=0;
if(*r==-1)
{
	printf("\n Queue is Empty. \n");
}
else
{
for(i=0;i<=*r;i++)
{
	printf(" | %d | ",queue[i]);
}

}
}

