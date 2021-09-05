#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

typedef struct Node node;

void print_list(node *head_ref)
{
    if(head_ref==NULL)
    {
        printf("\nThe list does not exist \n");
        return;
    }
    printf("The Circular Double Linked list is : ");
    node *temp = head_ref;
    do
    {
        printf("<-%d->",temp->data);
        temp = temp->next;

    }while(temp != head_ref);
}

void main()
{
    node *head,*second,*third,*fourth,*fifth;


    head = (node*)malloc(sizeof(node));
    second = (node*)malloc(sizeof(node));
    third = (node*)malloc(sizeof(node));
    fourth = (node*)malloc(sizeof(node));
    fifth = (node*)malloc(sizeof(node));

    head->data = 20;
    second->data = 30;
    third->data = 40;
    fourth->data = 60;
    fifth->data = 80;


    head->next = second;head->prev = fifth;
    second->next = third;second->prev=third;
    third->next = fourth;third->prev=second;
    fourth->next = fifth;fourth->prev=third;
    fifth->next = head;fifth->prev=fourth;

     print_list(head);

}
