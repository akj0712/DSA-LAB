// Design, develop and execute a program in C to perform the following operation on Singly linked list a. Insert the node at a specific location b. Delete a node at the beginning of the list c. Display the list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

typedef struct node *NODE;

NODE insertLoc(NODE first)
{
    int loc, count;
    NODE temp, cur;

    printf("Enter the location: ");
    scanf("%d", &loc);
    temp = (NODE)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &temp->data);
    temp->link = NULL;

    if (first == NULL)
    {
        if (loc == 1)
        {
            first = temp;
        }
        else
        {
            printf("INVALID LOCATION\n");
        }
    }

    else if (loc == 1)
    {
        temp->link = first;
        first = temp;
    }

    else
    {
        cur = first;
        count = 1;
        while (cur != NULL)
        {
            if (count == loc - 1)
            {
                temp->link = cur->link;
                cur->link = temp;
                break;
            }
            cur = cur->link;
            count++;
        }
        if (cur == NULL)
        {
            printf("INVALID LOCATION\n");
        }
    }
    return first;
}

NODE deleteFirst(NODE first)
{
    NODE temp;
    if (first == NULL)
    {
        printf("LIST IS EMPTY\n");
        return first;
    }
    temp = first;
    first = first->link;
    printf("Item to be removed: %d\n", temp->data);
    free(temp);
    return first;
}

NODE display(NODE first)
{
    NODE temp;
    if (first == NULL)
    {
        printf("LIST IS EMPTY\n");
    }
    else
    {
        printf("Content of the list is: \n");
        temp = first;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}

int main()
{
    int ch;
    NODE first = NULL;
    printf("1:INSERT \t 2:DELETE \t 3:DISPLAY \t 4.EXIT\n");

    for (;;)
    {
        printf("Enter the choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            first = insertLoc(first);
            break;

        case 2:
            first = deleteFirst(first);
            break;

        case 3:
            display(first);
            break;

        case 4:
            exit(0);
            break;

        default:
            printf("INVALID CHOICE\n");
            break;
        }
    }

    return 0;
}