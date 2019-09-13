#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

void push(int [],int*,int*,int);
void pop(int [],int*,int*);
void display(int [],int*,int*);

void main()
{
	int cqueue[SIZE]={0},r=-1,f=-1,i,choice,data;

	while(1)
	{
		printf("\n\n********** Cqueue **********\n");
		printf("1.Push data in cqueue.\n");
		printf("2.Pop data out of Cqueue.\n");
		printf("3.Display data in Cqueue.\n");
		printf("4.Count data in Cqueue.\n");
		printf("0.Exit\n");
		printf("Enter a choice: ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("\nEnter Data: ");
				scanf("%d",&data);
				push(cqueue,&r,&f,data);
				break;
			case 2:
				pop(cqueue,&r,&f);
				break;
			
			case 3:
				display(cqueue,&r,&f);
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


void push(int cqueue[SIZE],int *r,int *f,int data)
{

	if ( ((*f)==0 && (*r)==(SIZE-1)) || (*r+1==*f))
	{
		printf("\n Cqueue is Full. \n");
	}
	else
	{
	        if((*r)==SIZE-1)
		{
		*r=0;
		}
		else
		{
		(*r)++;
		}
		cqueue[*r]=data;
		if(*f==-1)
		{
			*f=0;
		}
		printf("\n Push Successful. \n");
	}

}


void pop(int cqueue[SIZE],int *r,int *f)
{

	int i=0;

	if(*f==-1)
	{
		printf("\n Cqueue is Empty. \n");
	}
	else
	{
                
		cqueue[*f]=0;
	

		if(*f==*r)
		{
			*f=-1;
			*r=-1;
		}
		else if(*f==SIZE-1)
			*f=0;
		else
		{
			(*f)++;
		}
		
		printf("\n Pop Successful. \n");

	}
}

void display(int cqueue[SIZE],int *r,int *f)
{

int i=0;
if(*f==-1)
{
	printf("\n Queue is Empty. \n");
}
else
{
for(i=0;i<5;i++)
{
	printf(" | %d | ",cqueue[i]);
}

}
}

