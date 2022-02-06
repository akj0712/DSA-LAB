// In a payroll management system, it is required to store the employee data (Employee ID, Employee name, Login Time) as one logs in to the system. At the end of the day, it is required to generate a report of all the employee who logged in that day in ascending order of the Employee ID. Develop a program to generate this report

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int EID;
    char eName[20];
    float LT;
    struct node *left;
    struct node *right;
};

typedef struct node *NODE;

NODE insert(NODE root, int EID, char eName[20], float LT)
{
    NODE newNode, prev = NULL, pres;
    newNode = (NODE)malloc(sizeof(struct node));
    newNode->EID = EID;
    strcpy(newNode->eName, eName);
    newNode->LT = LT;

    if (root == NULL)
    {
        root = newNode;
        return root;
    }
    pres = root;
    while (pres != NULL)
    {
        prev = pres;
        if (EID < pres->EID)
        {
            pres = pres->left;
        }
        else if (EID > pres->EID)
        {
            pres = pres->right;
        }
        else
        {
            printf("DUPLICATE\n");
            return root;
        }
    }
    if (EID < prev->EID)
    {
        prev->left = newNode;
    }
    else
    {
        prev->right = newNode;
    }

    return root;
}

void InOder(NODE root)
{
    if (root != NULL)
    {
        // printf("In-Order:\n");
        InOder(root->left);
        printf("%d \t %s \t %.2f\n", root->EID, root->eName, root->LT);
        InOder(root->right);
    }
}

int main()
{
    NODE root = NULL;
    int ch, EID;
    char eName[20];
    float LT;
    printf("1:INSERT 2:INORDER 3:EXIT\n");
    for (;;)
    {
        printf("Enter Your Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter Employee's Details: ");
            printf("Employee ID\n");
            scanf("%d", &EID);
            printf("Employee Name: ");
            scanf("%s", eName);
            printf("Login Time: ");
            scanf("%f", &LT);
            root = insert(root, EID, eName, LT);
            break;

        case 2:
            if (root == NULL)
                printf("Employee Details Absent\n");
            else
            {
                printf("EID\tEName\tLT\n");
                InOder(root);
            }
            break;

        case 3:
            exit(0);
            break;

        default:
            printf("INVALID CHOICE\n");
            break;
        }
    }

    return 0;
}