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
    printf("\n");
    while(n!=NULL)
    {
        printf("%d->",n->data);
        n=n->next;
    }
    printf("NULL");
}

void insert_at_first(node **head_ref)
{
    node *new_node = (node*)malloc(sizeof(node));
    printf("\nData : ");
    scanf("%d",&new_node->data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void insert_at_last(node *prev_node)
{
    node *new_node = (node*)malloc(sizeof(node));
    printf("\nData : ");
    scanf("%d",&new_node->data);
    new_node->next = NULL;
    prev_node->next = new_node;
}

void insert_at_middle(node *prev_node)
{
    node *new_node = (node*)malloc(sizeof(node));
    printf("\nData : ");
    scanf("%d",&new_node->data);
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void delete_at_first(node **head_ref)
{
    node *temp;
    temp = *head_ref;
    *head_ref = temp->next;
    free(temp);
}

void delete_at_end(node *n)
{
    node *prev;
    while(n->next != NULL)
    {
        prev = n;
        n = n->next;
    }
    prev->next=NULL;
    free(n);
}

void delete_at_any(node *end_prev)
{
    node *temp;
    temp = end_prev->next;
    end_prev->next=temp->next;
    free(temp);
}

void main()
{
    node *h,*fir,*sec,*thi,*fou,*fif;
    int choice;
    h = (node*)malloc(sizeof(node));
    sec = (node*)malloc(sizeof(node));
    thi = (node*)malloc(sizeof(node));
    fou = (node*)malloc(sizeof(node));
    fif = (node*)malloc(sizeof(node));

    h->data=99;h->next=sec;
    sec->data=88;sec->next=thi;
    thi->data = 77;thi->next=fou;
    fou->data = 66;fou->next=fif;
    fif->data = 55;fif->next = NULL;

    printf("\nSelect :");
    printf("\n\t 1 - Traverse/Print \n\t 2- Insertion \n\t 3 - Deletion : ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        print_list(h);
        break;
    case 2:
        printf("\n\t 1 - first \n\t 2 - middle \n\t 3 - last : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            insert_at_first(&h);
            print_list(h);
            break;
        case 2:
            printf("\n\t Position of Insertion : ");
            scanf("%d",&choice);
            switch(choice)
            {
            case 1:
                insert_at_middle(h);
                print_list(h);
                break;
            case 2:
                insert_at_middle(sec);
                print_list(h);
                break;
            case 3:
                insert_at_middle(thi);
                print_list(h);
                break;
            case 4:
                insert_at_middle(fou);
                print_list(h);
                break;
            }
            break;


        case 3:
            insert_at_last(fif);
            print_list(h);
            break;
        }
        break;

    case 3:
        printf("\n\t 1 - first \n\t 2 - middle \n\t 3 - last : ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            delete_at_first(&h);
            print_list(h);
            break;
        case 2:
            printf("\n\t Position of Deletion : ");
            scanf("%d",&choice);
            switch(choice)
            {
            case 1:
                delete_at_any(h);
                print_list(h);
                break;
            case 2:
                delete_at_any(sec);
                print_list(h);
                break;
            case 3:
                delete_at_any(thi);
                print_list(h);
                break;
            case 4:
                delete_at_any(fou);
                print_list(h);
                break;
            }
            break;

        case 3:
            delete_at_end(fou);
            print_list(h);
            break;
        }
        break;
    }
}
