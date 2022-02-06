// In a system, resources are shared among multiple consumers for optimal performance. Considering jobs submitted to the printer have to be printed in the order of arrival. In print spooling, documents are loaded into a buffer and then the printer pulls them off the buffer at its own rate. Spooling also lets you place a number of print jobs on a queue instead of waiting for each one to finish before specifying the next one. Develop a program for such scheduling using appropriate data structure

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

void insertRear(int cq[SIZE], int *rear, int item, int *count)
{
    *rear = (*rear + 1) % SIZE;
    cq[*rear] = item;
    *count = *count + 1;
}

void deletion(int cq[SIZE], int *front, int *count)
{
    if (*count == 0)
    {
        printf("NO JOB IN PRINT SPOOL\n");
    }
    else
    {
        printf("%d Exits Print Spool\n", cq[*front]);
        *front = (*front + 1) % SIZE;
        *count = *count - 1;
    }
}

void display(int cq[SIZE], int front, int count)
{
    if (count == 0)
    {
        printf("Print Spool is Empty\n");
        return;
    }
    else
    {
        int j = front;
        printf("Content of Print Spool\n");
        for (int i = 0; i < count; i++)
        {
            printf("%d is printing\n", cq[j]);
            j = (j + 1) % SIZE;
        }
    }
}

int main()
{
    int cq[SIZE], rear = -1, count = 0, front = 0, item, ch;
    printf("1:INSERT 2:DELETE 3:DISPLAY 4.EXIT\n");
    for (;;)
    {
        printf("Enter the choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the Print job in Spool: ");
            scanf("%d", &item);
            insertRear(cq, &rear, item, &count);
            break;

        case 2:
            deletion(cq, &front, &count);
            break;

        case 3:
            display(cq, front, count);
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