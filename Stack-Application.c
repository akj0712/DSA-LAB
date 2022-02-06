// Application: In a calculator application, given an expression with parenthesis it is required to flag any parenthesis mismatch. Develop a program for this calculator application using appropriate data structure

#include <stdio.h>
#include <string.h>

#define SIZE 20

void push(char s[SIZE], int *top, char ch)
{
    *top = *top + 1;
    s[*top] = ch;
}

void pop(int *top)
{
    *top = *top - 1;
}

int main()
{
    char in[SIZE], ch, s[SIZE];
    int i, top = -1;
    printf("Enter the Expression: ");
    scanf("%s", in);
    push(s, &top, '#');

    for (i = 0; i < strlen(in); i++)
    {
        ch = in[i];
        if (ch == '(')
        {
            push(s, &top, ch);
        }
        if (ch == ')')
        {
            if (s[top] != '#')
            {
                pop(&top);
            }
            else
            {
                printf("Closing Parenthesis are not balanced\n");
                return 0;
            }
        }
    }
    if (s[top] == '#')
    {
        printf("Parenthesis is balanced\n");
    }
    else
    {
        printf("Opening Parenthesis are not balanced\n");
    }

    return 0;
}