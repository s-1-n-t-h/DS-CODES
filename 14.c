#include<stdio.h>
struct Node
{
    struct Node* p;
    int d;
    struct Node* n;
};
typedef struct Node node;
void printlist(node* head_ref)
{
    node* temp = head_ref;
    printf("\n\t The Double Linked List created using static method is :");
    printf("\n\n\tNULL<->");
    while(temp)
    {
        printf("%d<->",temp->d);
        temp = temp->n;
    }
    printf("NULL\n\n\t");
}
void static_list_creation(int arr[],int n)
{
    node A[n];
    for(int i = 0;i<n;i++)
    {
        A[i].d = arr[i];

        if(i==0)
        {
            A[i].p = NULL;
            A[i].n = &A[1];
        }
        else if(i==n-1)
        {
            A[i].p = &A[i-1];
            A[i].n = NULL;
        }
        else
        {
            A[i].n = &A[i+1];
            A[i].p = &A[i-1];
        }
    }
     printlist(A);
}
void main()
{
    int arr[5] = {1,2,3,4,5};

    static_list_creation(arr,5);

}
