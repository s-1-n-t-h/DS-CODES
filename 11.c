#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node node;

void print_list(node *n)
{
    while(n!=NULL)
    {
        printf("%d->",n->data);
        n=n->next;
    }
    printf("NULL");
}

void main()
{
    node *h,*sec,*thi,*fou,*fif;

    h = (node*)malloc(sizeof(node));
    sec = (node*)malloc(sizeof(node));
    thi = (node*)malloc(sizeof(node));
    fou = (node*)malloc(sizeof(node));
    fif = (node*)malloc(sizeof(node));

    h->data = 9;h->next=sec;
    sec->data = 8;sec->next=thi;
    thi->data = 7;thi->next = fou;
    fou->data = 6;fou->next = fif;
    fif->data = 5;fif->next = NULL;
    printf("\nThe Single Linked List using Dynamic Representation is : ");
    print_list(h);

}
