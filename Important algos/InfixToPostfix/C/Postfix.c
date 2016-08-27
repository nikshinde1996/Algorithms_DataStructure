#include<stdio.h>
#include <ctype.h>
#define SIZE 50

char s[SIZE];
int top = -1;

push(char elem)
{
    s[++top] = elem;  //push the element in the stack.
}

char pop()
{
    return (s[top--]); //pop the element out of the stack.
}

int pr(char elem)
{
    switch (elem)
    {
        case '#':
            return 0;
        case '(':
            return 1;
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 3;
        case '^':
            return 4;
    }
}

main()
{
    char infix[50], postfix[50], ch, elem;
    int i = 0, k = 0;

    printf("\n\nRead the Infix Expression : ");
    scanf("%s", infix);

    push('#');

    while ((ch = infix[i++]) != '\0')
    {
        if (ch == '(')
            push(ch);
        else if (isalnum(ch))
            postfix[k++] = ch;
        else if (ch == ')')
        {
            while (s[top] != '(')
                postfix[k++] = pop();

            elem = pop();
        }
        else
        {
            while (pr(s[top]) >= pr(ch))
                postfix[k++] = pop();

            push(ch);
        }
    }
    while (s[top] != '#')
        postfix[k++] = pop();
        postfix[k] = '\0';

    printf("\n\nGiven Infix Expn: %s \n\n Postfix Expn: %s\n", infix, postfix);
}
