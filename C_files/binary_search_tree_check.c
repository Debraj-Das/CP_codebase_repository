#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node
{
   int data;
   struct node *left;
   struct node *right;
} node;

node *intial_node(int data) //* for intiallised the node pointer.
{
   node *n = (node *)malloc(sizeof(node));
   n->data = data;
   n->left = NULL;
   n->right = NULL;
   return n;
}

int check_bst(node *root, int *prev , int flag)
{
    if(root == NULL)
    return flag ;
    flag = check_bst(root->left,prev , flag);
    if((flag)&&(root->data>(*prev)))
    (*prev) = root->data;
    else
    return 0 ;
    flag = check_bst(root->right, prev, flag);
    return flag ;
}

int check_tree_is_bst_or_not(node *root)
{
    int prev = INT_MIN ;
    int flag = 1 ;
    return check_bst(root, &prev , flag);
}

void Inorder_print(node *root)
{
   if(root)
   {
      Inorder_print(root->left);
      printf("%d ",root->data);
      Inorder_print(root->right);
   }
   return ;
}

void tree_free(node *root)
{
   if(root)
   {
      tree_free(root->left);
      tree_free(root->right);
      free(root);
   }
   return ;
}

//* Hurry bro isBST() function.

int isBST(node *root)       //# this function use only one time.
{
    static node *prev = NULL ;
    if(root)
    {
        if(!isBST(root->left))
        return 0;
        else if(prev != NULL && root->data <= prev->data)
        return 0;
        else
        {
            prev = root ;
            return isBST(root->right);
        }
    }
    else
    return 1;
}


int main()
{
    node *root = intial_node(5);
    node *p1 = intial_node(3);
    root->left = p1 ;
    p1->left = intial_node(1);
    p1->right = intial_node(4);
    node *p2 = intial_node(7);
    root->right = p2 ;
    p2->left = intial_node(6);
    p2->right = intial_node(8);

    printf("Print the binary tree in inorder :: \n\t");
   Inorder_print(root);
   printf("\n");

//    if(check_tree_is_bst_or_not(root))
//    printf("\nRoot is a Binary search tree\n\n");
//    else
//     printf("\nRoot is not a Binary search tree\n\n");

   if(isBST(root))
   printf("\nRoot is a Binary search tree\n\n");
   else
    printf("\nRoot is not a Binary search tree\n\n");

   tree_free(root);
    
    return 0;
}

