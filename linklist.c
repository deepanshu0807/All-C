#include<stdio.h>
#include<stdlib.h>


struct node
{
	int info;
	struct node *link;
};
struct node *start=NULL;

int ins_at_beg(int x)
{
	struct node *t;
	t=(struct node*)malloc(sizeof(struct node));
	if(start==NULL)
	{
		start=t;
		start->info=x;
		start->link=NULL;
		return 0;
	}
	
	t->info=x;
	t->link=start;
	start=t;

}
int ins_at_end(int x)
{
	struct node *t,*temp;
	t=(struct node*)malloc(sizeof(struct node));
	if(start==NULL)
	{
		start=t;
		start->info=x;
		start->link=NULL;
		return 0;
	}
	temp=start;
	while(temp->link!=NULL)
	{
		temp=temp->link;
	}
	temp->link=t;
	t->info=x;
	t->link=NULL;
}
int traverse()
{
	struct node *t;
	t=start;
	if(t==NULL)
	{
		printf("\nEMPTY LIST.\n");
		return 0;
	}
	while(t->link!=NULL)
	{
		printf("%d->",t->info);
		t=t->link;
	}
	printf("%d\n",t->info);
	
}
int del_from_end()
{	int n;
	struct node *t,*s;
	if(start==NULL)
	{
		printf("\nEMPTY LIST.\n");
		return 0;
	}
	if (start->link == NULL) 
	{
      n = start->info;
      free(start);
      start = NULL;
      return 0;
    }
	t=start;
	while(t->link!=NULL)
	{	s=t;
		t=t->link;
	}
	n=t->info;
	s->link=NULL;
	free(t);
	
}
int del_from_beg()
{
	struct node *t;
	int n;
	if(start==NULL)
	{
		printf("\nEMPTY LIST.\n");
		return 0;
	}

	n=start->info;
	t=start->link;
	free(start);
   	start = t;	
}

int ins_at_mid(int x)
{
	struct node *t,*temp,*s;
	int val;
	t=(struct node*)malloc(sizeof(struct node));
	temp=start;
	printf("\nEnter val after which you want to insert:\n");
	scanf("%d",&val);
	while(temp->info!=val)
	{
		temp=temp->link;
	}
	t->info=x;
	t->link=temp->link;
	temp->link=t;
}
int del_from_mid()
{
	struct node *t,*s;
	int n,pos;
		if(start==NULL)
	{
		printf("\nEMPTY LIST.\n");
		return 0;
	}
	printf("\nEnter Position from where you want to delete:\n");
	scanf("%d",&pos);
	t=start;
	while(pos-1)
	{	s=t;
		t=t->link;
		pos--;
	}
	n=t->info;
	s->link=t->link;
	free(t);

}
int main()
{
	int ch,val;
	while(ch=1)
    {

        printf("\n1.Insert at Beginning\n2.Insert in-between\n3.Insert at end\n4.Traverse\n5.Delete from beginning\n6.Delete from in-between\n7.Delete from end\n8.EXIT\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("\nEnter value to be inserted:\n");
            		scanf("%d",&val);
					ins_at_beg(val);
					break;
            case 2:printf("\nEnter value to be inserted:\n");
            		scanf("%d",&val);
					ins_at_mid(val);
					break;
            case 3:printf("\nEnter value to be inserted:\n");
            		scanf("%d",&val);
					ins_at_end(val);
					break;
            case 4:traverse();
           			 break;
           	case 5:del_from_beg();
           			break;
           	case 6:del_from_mid();
           			break;
           	case 7:del_from_end();
           			break;
           	case 8:exit(0);
            default:printf("\nWrong Choice choice!\n");
        }
    }
    return 0;
}
