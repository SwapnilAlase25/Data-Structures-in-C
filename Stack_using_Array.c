#include<stdlib.h>
#include<stdio.h>
#define SIZE 5

int push(int [],int,int*);
void pop(int [],int*);
void display(int [],int*);
void count(int [],int);

void main()
{
int stack[SIZE],top=-1,choice,data,push_status;

     while(1)
    {
	printf("\n\n********** Stack **********\n");
	printf("1.Push data in stack.\n");
	printf("2.Pop data out of stack.\n");
	printf("3.Display stack.\n");
	printf("4.Count data in stack.\n");
	printf("0.Exit\n");
	printf("Enter your choice : ");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1:
			printf("\nEnter data: ");
			scanf("%d",&data);
			push_status=push(stack,data,&top);
			if(push_status==0)
				printf("\nPush Unsuccessful \n");
			else if(push_status==1)
				printf("\n Push Successful ");
			break;

		case 2:
			pop(stack,&top);
			break;

		case 3:
			display(stack,&top);
			break;

		case 4:
			count(stack,top);
			break;

		case 0:
			exit(0);

		default:
			printf("\n Invalid choice, try again. ");
			break;
	}

    }
}

int push(int stack[SIZE],int data,int *top)
{

	if(*top==(SIZE-1))
	{
		printf("\n Stack Full \n");
		return 0;
	}
	else
	{
		(*top)++;
		stack[*top]=data;
		return 1;
	}
}

void pop(int stack[SIZE],int *top)
{

	if(*top==-1)
	{
		printf("\n Stack Empty \n Pop Unsuccessful \n");
	}
	else
	{
		stack[*top]=0;
		(*top)--;
		printf("\n Poped Successfuly \n");
	}

}

void display(int stack[SIZE],int *top)
{
int i=0;

   if(*top==-1)
   {
    printf("\n Stack Empty \n");
   }
    else
   {
	for(i=0;i<=(*top);i++)
	{
	printf("| %d |\n",stack[*top-i]);
	}
   }
}

void count(int stack[SIZE],int top)
{
int counter=0,i=0;

for(i=0;i<=top;i++)
{
	counter++;
}

printf("\n Count is %d \n",counter);

}
