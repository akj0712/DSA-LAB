// Design, develop and execute a program in C to simulate the working of a queue of integers using an array. Provide the following operations. a. Insert b. Delete c. Display

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void insertRear(int item, int *r, int q[])
{
    if (*r == SIZE - 1)
    {
        printf("QUEUE OVERFLOW\n");
        return;
    }
    *r = *r + 1;
    q[*r] = item;
}

void deleteFront(int q[], int *f, int *r)
{
    if (*f > *r)
    {
        printf("QUEUE UNDERFLOW\n");
        return;
    }
    printf("The element deleted is: %d\n", q[(*f)++]);
    if (*f > *r && *r == SIZE - 1)
    {
        *f = 0;
        *r = -1;
    }
}

void display(int q[], int f, int r)
{
    if (f > r)
    {
        printf("QUEUE UNDERFLOW\n");
        return;
    }
    printf("Content of the Queue is: \n");
    for (int i = f; i <= r; i++)
    {
        printf("%d ", q[i]);
    }
    printf("\n");
}

int main()
{
    int choice, item, f, r, q[10];
    f = 0;
    r = -1;
    printf("1:INSERT 2:DELETE 3:DISPLAY 4:EXIT\n");
    for (;;)
    {
        printf("Enter The Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter item to be inserted: ");
            scanf("%d", &item);
            insertRear(item, &r, q);
            break;

        case 2:
            deleteFront(q, &f, &r);
            break;

        case 3:
            display(q, f, r);
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