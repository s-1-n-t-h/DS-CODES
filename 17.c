#include<stdio.h>
#include<stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

typedef struct Node node;

//code for traversing the linked list

void traverse(node *iptr)
{
    printf("\n\t");
    while(iptr != NULL)
    {
        printf("%d<->",iptr->data);
        iptr = iptr->next;
    }
    printf("\n\tTraversion completed\n\t");
}

// code for traversing the list and printing the data

void print_list(node *iptr)
{
    printf("NULL<->");
    while(iptr != NULL)
    {
        printf("%d<->",iptr->data);
        iptr = iptr->next;
    }
    printf("NULL");
}

// code for insertion at node

void in_at_first(node **head_ref )// for inserting a new node at the starting of linked list
{
    node *new_node = (node*)malloc(sizeof(node));
    node *temp = *head_ref;

    printf("\nInput the data of the new node to insert : ");
    scanf("%d",&new_node->data);

    new_node->next = *head_ref;
    new_node->prev = NULL;

    temp->prev = new_node;
    *head_ref = new_node;
}

void in_at_any(node *prev_node)
{
    node *new_node = (node*)malloc(sizeof(node));

    printf("\nInput the data of the new node to insert : ");
    scanf("%d",&new_node->data);

    new_node->next = prev_node->next;
    prev_node->next->prev  = new_node;

    new_node->prev = prev_node;
    prev_node->next = new_node;


}

void in_at_last(node *prev_node)
{
    node *new_node = (node*)malloc(sizeof(node));

    printf("\nInput the data of the new node to insert : ");
    scanf("%d",&new_node->data);

    new_node->next = NULL;

    prev_node->next = new_node;
    new_node->prev = prev_node;

}

// codes for deletion of a node

void del_at_first(node **head_ref)
{
    node *temp,*temp1;

    temp = *head_ref;

    *head_ref = temp->next;
    temp1 = temp->next;

    temp1->prev = NULL;

    free(temp);
}

void del_at_end(node *n)
{
    node *prev = n->prev;

    prev->next = NULL;

    free(n);
}

void del_at_any(node *prev_n)
{
    prev_n->next->prev = prev_n->prev;
    prev_n->prev->next = prev_n->next;
    free(prev_n);

}
void main()
{
    node *head,*second,*third,*fourth,*fifth,*sixth;
    int choice;

    head = (node*)malloc(sizeof(node));
    second = (node*)malloc(sizeof(node));
    third = (node*)malloc(sizeof(node));
    fourth = (node*)malloc(sizeof(node));
    fifth = (node*)malloc(sizeof(node));
    sixth = (node*)malloc(sizeof(node));

    head->data = 6;
    second->data = 7;
    third->data = 8;
    fourth->data = 8;
    fifth->data = 9;
    sixth->data = 10;


    head->next = second;head->prev = NULL;
    second->next = third;second->prev = head;
    third->next = fourth;third->prev = second;
    fourth->next = fifth;fourth->prev = third;
    fifth->next = sixth;fifth->prev = fourth;
    sixth->next = NULL;sixth->prev = fifth;

    printf("\nPlease select any one of four choices : \n");
    printf("\nSelect \n\t1 for Traversing the list \n\t2 for Printing the linked list \n\t3 for performing Insertion \n\t4 for performing deletion : ");
    scanf("%d",&choice);

    switch (choice)
    {

        case 1:
            traverse(head);
            break;

        case 2:
            print_list(head);
            break;
        case 3:
            printf("\nSelect 1 for Inserting at the beginning of list,\nSelect 2 for performing Insertion at Middle or Any position,\nSelect 3 for performing Insertion at end : ");
            scanf("%d",&choice);
            switch (choice)
                {


                case 1:
                    in_at_first(&head);
                    printf("\n\n\tThe new list formed after the operation is : ");
                    print_list(head);
                    break;

                case 2:
                    printf("\n\tSpecify the position after which insertion should take place : ");
                    scanf("%d",&choice);
                    switch (choice)
                    {


                        case 1:
                            in_at_any(head);
                            printf("\n\n\tThe new list formed after the operation is : ");
                            print_list(head);
                            break;
                        case 2:
                            in_at_any(second);
                            printf("\n\n\tThe new list formed after the operation is : ");
                            print_list(head);
                            break;
                        case 3:
                            in_at_any(third);
                            printf("\n\n\tThe new list formed after the operation is : ");
                            print_list(head);
                            break;
                        case 4:
                            in_at_any(fourth);
                            printf("\n\n\tThe new list formed after the operation is : ");
                            print_list(head);
                            break;
                        case 5:
                            in_at_any(fifth);
                            printf("\n\n\tThe new list formed after the operation is : ");
                            print_list(head);
                            break;
                    }
                    break;

                case 3:
                    in_at_last(sixth);
                    printf("\n\n\tThe new list formed after the operation is : ");
                    print_list(head);
                    break;

                }
                break;

        case 4:

            printf("\nSelect 1 for Deleting at the beginning of list,\nSelect 2 for performing Deletion at Middle or Any position,\nSelect 3 for performing Deletion at end : ");
            scanf("%d",&choice);
            switch (choice)
            {


                case 1:
                    del_at_first(&head);
                    printf("\n\n\tThe new list formed after the operation is : ");
                    print_list(head);
                    break;

                case 2:
                    printf("\n\tSpecify the position after which Deletion should take place : ");
                    scanf("%d",&choice);
                    switch (choice)
                    {


                        case 1:
                            del_at_any(head);
                            printf("\n\n\tThe new list formed after the operation is : ");
                            print_list(head);
                            break;
                        case 2:
                            del_at_any(second);
                            printf("\n\n\tThe new list formed after the operation is : ");
                            print_list(head);
                            break;
                        case 3:
                            del_at_any(third);
                            printf("\n\n\tThe new list formed after the operation is : ");
                            print_list(head);
                            break;
                        case 4:
                            del_at_any(fourth);
                            printf("\n\n\tThe new list formed after the operation is : ");
                            print_list(head);
                            break;
                        case 5:
                            del_at_any(fifth);
                            printf("\n\n\tThe new list formed after the operation is : ");
                            print_list(head);
                            break;
                    }
                    break;

                 case 3:
                    del_at_end(sixth);
                    printf("\n\n\tThe new list formed after the operation is : ");
                    print_list(head);
                    break;

            }
            break;


    }
}










