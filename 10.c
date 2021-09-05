#include <stdio.h>
#include <stdlib.h>
#define N 5

// A Linked List Node
struct Node
{
    int data;
    struct Node* next;
};

struct Node node[N];

// Helper function to print a given linked list
void printList(struct Node* head)
{
    struct Node* curr = head;
    while (curr)
    {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL");
}

struct Node* createStaticList(int arr[])
{
    for (int i = 0; i < N; i++)
    {
        node[i].data = arr[i];
        node[i].next = NULL;

        if (i > 0) {
            node[i - 1].next = &node[i];
        }
    }
    return node;
}

int main(void)
{
    int arr[N] = { 6,7,8,9,10};
    struct Node* root = createStaticList(arr);

    printList(root);

    return 0;
}



