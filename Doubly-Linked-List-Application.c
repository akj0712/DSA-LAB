// Colleges maintain the student’s records. As students enroll and graduate, the records have to be updated. It is necessary to access the student’s data whenever required by college. Using suitable data structures develop a program for above scenario

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char name[30];
    char USN[20];
    int sem;
    struct node *left;
    struct node *right;
};

typedef struct node *NODE;

NODE insert(NODE first)
{
    NODE newNode;
    char name[30];
    char USN[20];
    int sem;
    newNode = (NODE)malloc(sizeof(struct node));
    newNode->left = newNode->right = NULL;
    printf("Enter Students Details: \n");
    printf("Name: ");
    scanf("%s", name);
    printf("USN: ");
    scanf("%s", USN);
    printf("Semester: ");
    scanf("%d", &sem);
    strcpy(newNode->name, name);
    strcpy(newNode->USN, USN);
    newNode->sem = sem;

    if (first == NULL)
    {
        first = newNode;
        return first;
    }
    else
    {
        newNode->right = first;
    }
    first->left = newNode;
    first = newNode;
    return first;
}

void search(NODE first)
{
    NODE pres;
    char USN[20];
    if (first == NULL)
    {
        printf("Empty Database\n");
        return;
    }
    printf("Enter the USN to be searched: ");
    scanf("%s", USN);
    pres = first;
    while (pres != NULL && strcmp(USN, pres->USN) != 0)
        pres = pres->right;

    if (pres == NULL)
    {
        printf("Student Not Found\n");
    }
    else
    {
        printf("Student Found\n");
    }
}

void display(NODE first)
{
    if (first == NULL)
    {
        printf("Empty Database\n");
    }
    else
    {
        printf("Student Details\n");
        printf("Name\t\tUSN\t\tSemester\n");
        while (first != NULL)
        {
            printf("%s\t\t%s\t\t%d\n", first->name, first->USN, first->sem);
            first = first->right;
        }
    }
}
int main()
{
    int ch;
    NODE first = NULL;
    printf("1:INSERT 2:SEARCH 3:DISPLAY 4:EXIT\n");
    for (;;)
    {
        printf("Enter Your Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            first = insert(first);
            break;

        case 2:
            search(first);
            break;

        case 3:
            display(first);
            break;

        case 4:
            exit(0);

        default:
            printf("INVALID CHOICE\n");
            break;
        }
    }

    return 0;
}