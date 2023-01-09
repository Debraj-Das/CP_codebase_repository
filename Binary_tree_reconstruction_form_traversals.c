#include <stdio.h>
#include <stdlib.h>

typedef struct Bin_tree
{
    int data;
    struct Bin_tree *left;
    struct Bin_tree *right;
} Bin_tree;

Bin_tree *intial_Bin_tree(int data) //* for intiallised the Bin_tree pointer.
{
    Bin_tree *n = (Bin_tree *)malloc(sizeof(Bin_tree));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

Bin_tree *reconstruction_of_tree_by_preorder(int n, int preorder[], int inorder[])
{
    Bin_tree *root;
    if (n == 0)
        root = NULL;
    else if (n == 1)
        root = intial_Bin_tree(preorder[0]);
    else
    {
        int root_position;
        for (int i = 0; i < n; ++i)
            if (inorder[i] == preorder[0])
            {
                root_position = i;
                break;
            }
        int Lst = root_position, Rst = n - root_position - 1;
        root = intial_Bin_tree(preorder[0]);
        root->left = reconstruction_of_tree_by_preorder(Lst, preorder + 1, inorder);
        root->right = reconstruction_of_tree_by_preorder(Rst, preorder + Lst + 1, inorder + Lst + 1);
    }
    return root;
}

void Postorder_print(Bin_tree *root)
{
    if (root)
    {
        Postorder_print(root->left);
        Postorder_print(root->right);
        printf("%d ", root->data);
    }
    return;
}

void tree_free(Bin_tree *root)
{
    if (root)
    {
        tree_free(root->left);
        tree_free(root->right);
        free(root);
    }
    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    int *preorder = (int *)malloc(n * sizeof(int));
    int *inorder = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i)
        scanf("%d", &preorder[i]);

    for (int i = 0; i < n; ++i)
        scanf("%d", &inorder[i]);

    Bin_tree *root = reconstruction_of_tree_by_preorder(n, preorder, inorder);
    free(preorder);
    free(inorder);

    Postorder_print(root);

    tree_free(root);
    return 0;
}