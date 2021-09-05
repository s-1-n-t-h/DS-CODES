#include<stdio.h>
#define SIZE 10
void EnQueue();void DeQueue();void Print();void isFull();void isEmpty();void peek();
int queue[SIZE], front = -1, rear = -1;
void main()
{
    int ch;
    do
    {
        printf("\n\n Select :\n1. ENQUEUE\n2. DEQUEUE\n3. PRINT\n4. IsFull\n5. IsEmpty\n6. peek\n7. EXIT\n::");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                EnQueue();
                break;
            case 2:
                DeQueue();
                break;
            case 3:
                Print();
                break;
            case 4:
                isFull();
                break;
            case 5:
                isEmpty();
                break;
            case 6:
                peek();
                break;
            case 7:
                printf("\n\tExited .");
                break;
            default:
                printf("\nNot a valid choice");
        }
    }while(ch!=7);
}
void EnQueue()
{
    int data;

    if(rear==SIZE-1)
    {
        printf("\nQueue is Full !! No Enqueuing possible .");
    }
    else
    {
        if(front==-1)
            front++;
        rear++;
        printf("\nPlease input the data to be added : ");
        scanf("%d",&data);
        queue[rear] = data;
        printf("\n\tEnqueued %d to the queue",data);

    }
}
void DeQueue()
{
    if(front==-1)
    {
        printf("\nQueue is Empty !! No further dequeuing possible .");
    }
    else
    {
        printf("\nThe element removed is %d.",queue[front]);
        front++;
        if(front > rear)
        {
            front = rear = -1;
        }
    }
}
void Print()
{
    if(rear==-1)
    {
        printf("\nThe Queue is Underflow !! Nothing to print.");
    }
    else
    {
        printf("\nThe Queue is :");
        for(int i=front;i<=rear;i++)
        {
            printf(" %d ",queue[i]);
        }
        printf("\n");
    }
}
void isFull()
{
    if(rear==SIZE-1)
    {
        printf("\n The Queue is FULL !");
    }
    else
    {
        if(front==-1)
        {
            printf("\nThe Queue is Not Full !");
            printf("\nContains %d elements.",0);
            return;
        }
        printf("\nThe Queue is Not Full !");
        printf("\nContains %d elements.",rear-front+1);
    }
}
void isEmpty()
{
    if(rear==-1)
    {
        printf("\nThe Queue is Empty !!");
    }
    else
    {
        printf("\nThe Queue is Not Empty !");
        printf("\nContains %d elements.",rear-front+1);
    }
}
void peek()
{
    if(front==-1)
    {
        printf("\nThe Queue is Empty .");
    }
    else
    {
        printf("\nThe element at the first of the Queue is :");
        printf(" %d",queue[front]);
    }
}
