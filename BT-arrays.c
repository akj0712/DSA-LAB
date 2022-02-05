#include<stdio.h>
#include<stdlib.h>
#define SZ 100

void bt(int a[SZ], int ele)
{
    int c, p, i;
    if (a[0] == '\0')
    {
        a[0] = ele;
        return;
    }
    c = 0;
    while (a[c] != '\0')
    {
        p = c;
        if (ele < a[c])
        {
            c = 2*c + 1;
        }
        else
        {
            c = 2*c + 2;
        }
    }
    if (ele < a[p])
    {
        c = 2*p + 1;
    }
    else
    {
        c = 2*p + 2;
    }
    a[c] = ele;
    printf("Constructed Binary Tree is\n");
    for (int i = 0; i < SZ; i++)
    {
        if (a[i] != '\0')
        {
            printf("a[%d] ==>> %d\n", i, a[i]);
        }
    }
}

int main(void)
{
    int n, a[SZ], i, ele;
    for ( i = 0; i < SZ; i++)
    {
        a[i] = '\0';
    }
    printf("Enter the number of data in a Binary Tree\n");
    scanf("%d", &n);
    printf("Enter the data in a Binary Tree\n");
    for ( i = 0; i < n; i++)
    {
        scanf("%d", &ele);
        bt(a, ele);
    }
    
}