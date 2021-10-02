#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define SIZE 50
char spf[SIZE];
char stack[SIZE];
char revexp[SIZE];
int top =  -1,i=0;

void brackets(char exp[])
{
    char *e = exp;
    while(*e != '\0')
    {
        if(*e == ')')
        {
            *e = '(';
        }
        else if(*e == '(')
        {
            *e = ')';
        }
        e++;
    }
}
void reverse(char exp[])
{
    strcpy(revexp,strrev(exp));
}
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
    reverse(exp);
    brackets(revexp);
    e = revexp;
    while(*e != '\0')
    {
        if(isalnum(*e))
        {
            spf[i] = *e;
            i++;
        }
        else if(*e == '(')
        {
            push(*e);
        }
        else if(*e == ')')
        {
            while((x=pop())!='(')
            {
                spf[i] = x;
                i++;
            }
        }
        else
        {
            while(priority(*e)<=priority(stack[top]))
            {
                spf[i] = pop();
                i++;
            }
            push(*e);
        }
        e++;
    }
    while(top != -1)
    {
        spf[i] = pop();
        i++;
    }
    strcpy(spf,strrev(spf));
    printf("\n prefix expression is : ");
    for(int j = 0;j<strlen(spf);j++)
    {
        printf("%c ",spf[j]);
    }
}
