#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;

};

typedef struct Node node;

void printlist(node *head)
{
    node *temp;
    temp = head;

    do
    {
        printf("<-%d->",temp->data);
        temp = temp->next;
    }while(temp != head);
    printf("NULL");

}

void main()
{
    node *head,*second,*third,*fourth,*fifth;

    head = (node*)malloc(sizeof(node));
    second = (node*)malloc(sizeof(node));
    third = (node*)malloc(sizeof(node));
    fourth = (node*)malloc(sizeof(node));
    fifth = (node*)malloc(sizeof(node));

    head->data = 100;
    second->data = 200;
    third->data = 300;
    fourth->data = 400;
    fifth->data = 500;

    head->prev = fifth;
    head->next = second;

    second->prev = head;
    second->next = third;

    third->next = fourth;
    third->prev = second;

    fourth->next = fifth;
    fourth->prev = third;

    fifth->next = head;
    fifth->prev = fourth;


    printlist(head);
}

