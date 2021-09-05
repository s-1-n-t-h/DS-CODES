#include<stdio.h>
# define SIZE 10
void push();void pop();void print();
int top = -1;int stack[SIZE];
void main()
{
    int ch;

    do
    {
        printf("\n\n Select :\n1. To Push\n2. To Pop\n3.To Print\n4.To Exit\n::");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                print();
                break;
            case 4:
                printf("\n\tExited .");
                break;
            default:
                printf("\nNot a valid choice");

        }
    }while(ch!=4);
}
void push()
{
    int data;

    if(top==SIZE-1)
    {
        printf("\nStack is Full !! No push possible .");
    }
    else
    {
        printf("\nPlease input the data to be pushed : ");
        scanf("%d",&data);
        top++;
        stack[top] = data;
    }
}
void pop()
{
    if(top==-1)
    {
        printf("\nStack is Empty !! No further pop possible .");
    }
    else
    {
        printf("\nThe element popped is %d.",stack[top]);
        top--;
    }
}
void print()
{
    if(top==-1)
    {
        printf("\nThe stack is in Underflow State .");
    }
    else
    {
        printf("\nThe stack is : ");
        for(int i = top;i>=0;i--)
        {
            printf("\n\t%d",stack[i]);
        }
    }
}
