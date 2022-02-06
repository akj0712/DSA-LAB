// Design, develop and execute a program in C to implement a doubly linked list where each node consists of integers. The program should support the following operations: a. Create a doubly linked list by adding each node at the front b. Delete the node of a given data If it is found, otherwise display appropriate message c. Display the contents of the list.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *llink;
    struct node *rlink;
};

typedef struct node *NODE;
NODE first = NULL;
NODE last = NULL;

void insert(int info)
{
    NODE newNode;
    newNode = (NODE)malloc(sizeof(struct node));
    newNode->data = info;
    newNode->rlink = NULL;
    newNode->llink = NULL;

    if (first == NULL)
    {
        first = last = newNode;
        return;
    }
    newNode->rlink = first;
    first->llink = newNode;
    first = newNode;
}

void delete (int key)
{
    int flag = 0;
    NODE prev, cur, next;
    if (first == NULL)
    {
        printf("LIST IS EMPTY\n");
        return;
    }
    if (first->rlink == NULL)
    {
        if (first->data == key)
        {
            printf("Deleted element: %d ", first->data);
            free(first);
            first = last = NULL;
            return;
        }
    }
    if (key == first->data)
    {
        printf("Deleted Item: %d ", first->data);
        cur = first;
        first = first->rlink;
        first->llink = NULL;
        free(cur);
        cur = NULL;
        return;
    }
    if (key == last->data)
    {
        printf("Deleted Item: %d ", last->data);
        cur = last;
        last = last->llink;
        last->rlink = NULL;
        free(cur);
        cur = NULL;
        return;
    }

    cur = first->rlink;
    while (cur != last)
    {
        if (cur->data == key)
        {
            prev = cur->llink;
            next = cur->rlink;
            printf("Deleted Item: %d ", cur->data);
            prev->rlink = next;
            next->llink = prev;
            free(cur);
            cur = NULL;
            flag = 1;
            break;
        }
        cur = cur->rlink;
    }

    if (flag == 0)
    {
        printf("\nKEY NOT FOUND\n");
    }
}

void display()
{
    NODE temp;
    if (first == NULL)
    {
        printf("LIST IS EMPTY\n");
    }
    else
    {
        printf("Content of the List is: \n");
        temp = first;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->rlink;
        }
        printf("\n");
    }
}

int main()
{
    int ch, info;
    printf("1:INSERT 2:DELETE 3:DISPLAY 4:EXIT\n");
    for (;;)
    {
        printf("Enter Your Choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &info);
            insert(info);
            break;

        case 2:
            printf("Enter the data to be deleted: ");
            scanf("%d", &info);
            delete (info);
            break;

        case 3:
            display();
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