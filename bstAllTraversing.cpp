#include <stdio.h> 
#include <stdlib.h> 
  
struct node 
{ 
     int data; 
     struct node* left; 
     struct node* right; 
}; 
  
struct node* newNode(int data) 
{ 
     struct node* node = (struct node*) malloc(sizeof(struct node)); 
     node->data = data; 
     node->left = NULL; 
     node->right = NULL; 
     return(node); 
} 

void printPostorder(struct node* node) 
{ 
     if (node == NULL) 
        return; 
     printPostorder(node->left); 
     printPostorder(node->right); 
     printf("%d ", node->data); 
} 
  
void printInorder(struct node* node) 
{ 
     if (node == NULL) 
          return; 
     printInorder(node->left); 
     printf("%d ", node->data);   
     printInorder(node->right); 
} 
void printPreorder(struct node* node) 
{ 
     if (node == NULL) 
          return; 
     printf("%d ", node->data);  
     printPreorder(node->left);   
     printPreorder(node->right); 
}     
  
int main() 
{ 	int i,ar[5];
	for(i=0;i<5;i++)
	{
		scanf("%d",&ar[i]);
	}
	
     struct node *root  = newNode(ar[0]); 
     root->left             = newNode(ar[1]); 
     root->right           = newNode(ar[2]); 
     root->left->left     = newNode(ar[3]); 
     root->left->right   = newNode(ar[4]);  
  
     printf("\nPreorder traversal of binary tree is \n"); 
     printPreorder(root); 
  
     printf("\nInorder traversal of binary tree is \n"); 
     printInorder(root);   
  
     printf("\nPostorder traversal of binary tree is \n"); 
     printPostorder(root); 
  
     getchar(); 
     return 0; 
} 
