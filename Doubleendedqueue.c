#include<stdio.h>
#include<conio.h>
#define MAX 100

int q[MAX];
int r = -1, f = -1;
int enquef()
{		int i,val;
        if(r==MAX-1)
        {printf("\nOVERFLOW\n");return 1;}
        else
        {
        	for(i=r;i<f;i--)
        	{
        		q[i]=q[i-1];
			}
			 printf("\nEnter value:\n");
       		 scanf("%d",&val);
			q[f]=val;
			r+=1;
		}
}
int enquer()
{
        int val;
        if(r==MAX-1)
            {printf("\nOVERFLOW\n");return 1;}

        else
       {
       	printf("\nEnter value:\n");
       	scanf("%d",&val);
       	q[r]=val;
       	r+=1;
	   } 
}
int dequer()
{
    if(f==r)
    {
            printf("\nUnderflow\n");return 1;
    }
   
       else
       {
       	r=r-1;
       	q[r]=-1;
	   }
   
}
int dequef()
{
    if(f==r)
    {
            printf("\nUnderflow\n");return 1;
    }
    
  
        else 
		{
			q[f]=-1;
			f+=1;
  		}
}
int display()
{
    int i;
     if(f==r)
    {
            printf("\nUnderflow\n");return 1;
    }
    else
    {
        for(i=f;i<r;i++)
            printf(" %d\t",q[i]);
    }
    
return 0;
}

int main()
{
    char ch;
    int ch1, ch2;
    printf("\n*****Double Ended Queue*****\n");
     do
     {
          printf("\n1.Input-restricted deque \n");
          printf("2.Output-restricted deque \n");
          printf("\nEnter your choice: ");
          scanf("%d",&ch1);
          switch(ch1)
          {
               case 1: 
                    printf("\nSelect the Operation\n");
                    printf("1.Insert\n2.Delete from Rear\n3.Delete from Front\n4. Display");
                    do
                    {
                       printf("\nEnter your choice for the operation in c deque: ");
                       scanf("%d",&ch2);
                       switch(ch2)
                       {   
                          case 1: enquer();
                                  display();
                       		  break;
                       	  case 2: dequer();
                       		  
                                  display();
                       		  break;
                          case 3: dequef();
                       	          
                                  display();
                       	          break;
                          case 4: display();
                                  break;
                          default:printf("Wrong choice");
                       }
                       printf("\nDo you want to perform another operation (Y/N): ");
                       ch=getch();
                    }while(ch=='y'||ch=='Y');
                    getch();
                    break; 
     
               case 2 :
                   printf("\n---- Select the Operation ----\n");
                   printf("1. Insert at Rear\n2. Insert at Front\n3. Delete\n4. Display");
                   do
                   {
                      printf("\nEnter your choice for the operation: ");
                      scanf("%d",&ch2);
                      switch(ch2)
                      {   
                         case 1: enquer();
                                 display();
                                 break;
                         case 2: enquef();
                                 display();
                                 break;
                         case 3: dequef();
                                 display();
                                 break;
                         case 4: display();
                                 break;
                         default:printf("Wrong choice");
                       }
                       printf("\nDo you want to perform another operation (Y/N): ");
                       ch=getch();
                    } while(ch=='y'||ch=='Y');
                    getch();
                    break ;
            }
            printf("\nDo you want to continue(y/n):");
            ch=getch();
      }while(ch=='y'||ch=='Y');
}


