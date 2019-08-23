#include<stdio.h>
#include<conio.h>

#define MAX 5
int f=-1,r=-1;
int q[MAX];
 
void enq()
{
	int val;
	if((r+1)%MAX==f)
	{
		printf("OVERFLOW.\n");
	}
	else if(f==-1 && r==-1)
	{
		f=0;
		r=0;
	}
	else
	r=(r+1)%MAX;
	
	printf("Value: ");
	scanf("%d",&val);
	q[r]=val;
}
void deq()
{
	if(f==-1)
	printf("UNDERFLOW.\n");
	else if(f==r)
	{
		f==-1;
		r==-1;
	}
	else
	{
		printf("\nDeleted : %d",q[f]);
		f=(f+1)%MAX;
	}
		
}
void display()
{	int i;
	if(f==-1)
	printf("NO ELEMENT.\n");
	else if(f>r)
	{
		for(i=f;i<MAX;i++)
		{
			printf("%d\n",q[i]);
		}
		for(i=0;i<=r;i++)
		{
			printf("%d\n",q[i]);
		}
	}
	else
	{
		for(i=f;i<=r;i++)
		{
			printf("%d\n",q[i]);
		}
	}
}

int main()
{

	
	int choice;
	while(1)
	{
		printf("\n\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:enq();break;
			case 2:deq();break;
			case 3:display();break;
			case 4:exit(0);
			default:printf("wrong choice!");
			
		}
		
	}
return 0;
}

