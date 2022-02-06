// Design, develop and execute a program in C to create a Binary search tree and perform preorder traversals

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *left;
    struct node *right;
};

typedef struct node *NODE;

NODE insert(NODE root, int item)
{
    NODE newNode, prev = NULL, pres;
    newNode = (NODE)malloc(sizeof(struct node));
    newNode->info = item;
    newNode->left = NULL;
    newNode->right = NULL;

    if (root == NULL)
    {
        root = newNode;
        return root;
    }

    pres = root;
    while (pres != NULL)
    {
        prev = pres;
        if (item < pres->info)
        {
            pres = pres->left;
        }
        else if (item > pres->info)
        {
            pres = pres->right;
        }
        else
        {
            printf("DUPLICATION OF ITEM IS NOT ALLOWED\n");
            return root;
        }
    }
    if (item < prev->info)
    {
        prev->left = newNode;
    }
    else
    {
        prev->right = newNode;
    }

    return root;
}

void Preorder(NODE root)
{
    if (root != NULL)
    {
        printf("%d ", root->info);
        Preorder(root->left);
        Preorder(root->right);
    }
}

int main()
{
    NODE root = NULL;
    int ch, item;
    printf("\n1:INSERT \t 2:PREORDER \t 3:EXIT\n");
    for (;;)
    {
        printf("Enter Your Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the Item: ");
            scanf("%d", &item);
            root = insert(root, item);
            break;

        case 2:
            if (root == NULL)
            {
                printf("Empty Tree\n");
            }
            else
            {
                printf("Pre-Order:\n");
                Preorder(root);
                printf("\n");
            }
            break;

        case 3:
            exit(0);

        default:
            printf("INVALID CHOICE\n");
            break;
        }
    }

    return 0;
}