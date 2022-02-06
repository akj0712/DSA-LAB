// Write a program in C to simulate the working of a stack of integers using an array. Provide the following operations. a. Insert b. Delete c. Display

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void push(int item, int *top, int s[])
{
    if (*top == SIZE - 1)
    {
        printf("STACK OVERFLOW\n");
        return;
    }
    *top = *top + 1;
    s[*top] = item;
}

int pop(int *top, int s[])
{
    int item_deleted;
    if (*top == -1)
    {
        return 0;
    }
    item_deleted = s[*top];
    *top = *top - 1;
    return item_deleted;
}

void display(int top, int s[])
{
    int i;
    if (top == -1)
    {
        printf("STACK UNDERFLOW\n");
    }
    else
    {
        printf("Content of the stack is: \n");
        for (i = top; i >= 0; i--)
        {
            printf("%d ", s[i]);
        }
        printf("\n");
    }
}

int main()
{
    int top = -1;
    int s[10];
    int item;
    int item_deleted;
    int choice;
    printf("1:PUSH 2:POP 3:DISPLAY 4:EXIT\n");
    for (;;)
    {
        printf("Enter the Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the Element to be inserted: ");
            scanf("%d", &item);
            push(item, &top, s);
            break;

        case 2:
            item_deleted = pop(&top, s);
            if (item_deleted == 0)
            {
                printf("STACK UNDERFLOW\n");
            }
            else
            {
                printf("Item Deleted: %d\n", item_deleted);
            }
            break;

        case 3:
            display(top, s);
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