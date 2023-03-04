#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Implement a program for converting an infix expression to postfix expression using stack.
 * @author Obaydur Rahman (213902018) <obayed.opu@gmail.com>
 * @date 2022-08-07 (16:33)
 *
 * @returns int
 */

int main()
{
    char infix[100],
        postfix[100],
        stack[100];

    int i,
        j,
        top = -1;

    printf("Enter an infix expression: ");
    scanf("%s", infix); // example: (a+b)*c

    for (i = 0; infix[i] != '\0'; i++)
    {
        if (infix[i] == '(')
        {
            stack[++top] = infix[i];
        }
        else if (infix[i] == ')')
        {
            while (stack[top] != '(')
            {
                postfix[++j] = stack[top];
                top--;
            }
            top--;
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
        {
            while (top != -1 && stack[top] != '(' && (stack[top] == '+' || stack[top] == '-' || stack[top] == '*' || stack[top] == '/'))
            {
                postfix[++j] = stack[top];
                top--;
            }
            stack[++top] = infix[i];
        }
        else
        {
            postfix[++j] = infix[i];
        }
    }
    while (top != -1)
    {
        postfix[++j] = stack[top];
        top--;
    }
    postfix[++j] = '\0';
    printf("Postfix expression: %s\n", postfix); // example: ab+c*

    return 0;
}
