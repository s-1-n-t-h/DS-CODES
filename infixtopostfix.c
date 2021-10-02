#include<stdio.h>
#include<ctype.h>
#define SIZE 50
char stack[SIZE];
int top =  -1;

void push(char x)
{
    if(top==SIZE)
    {
        printf("\n stack is full !");
        return;
    }
    stack[++top] = x;
}

char pop()
{
    if(top==-1)
    {
        printf("\n stack is empty ! ");
    }
    return stack[top--];
}

int priority(char x)
{
    if(x=='(')
    {
        return 0;
    }
    else if(x=='+'||x=='-')
    {
        return 1;
    }
    else if(x=='*'||x=='/'||x=='%')
    {
        return 2;
    }
    else if(x=='^')
    {
        return 3;
    }
    return 0;

}

void main()
{
    char exp[SIZE];
    char *e,x;
    printf("\n enter the infix expression : ");
    scanf("%s",exp);
    printf("\n");
    e = exp;

    while(*e != '\0')
    {
        if(isalnum(*e))
        {
            printf("%c ",*e);
        }
        else if(*e == '(')
        {
            push(*e);
        }
        else if(*e == ')')
        {
            while((x=pop())!='(')
            {
                printf("%c ",x);
            }
        }
        else
        {
            while(priority(*e)<=priority(stack[top]))
            {
                printf("%c ",pop());
            }
            push(*e);
        }
        e++;
    }
    while(top != -1)
    {
        printf("%c ",pop());
    }
}

