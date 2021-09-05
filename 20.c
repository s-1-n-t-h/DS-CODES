#include<stdio.h>
#include<stdlib.h>


struct node
{
    int data;

    struct node *left;
    struct node *right;
};

struct node *root = NULL;

void insert(int data)
{
    struct node *tempN = (struct node*)malloc(sizeof(struct node));

    struct node *current,*parent;

    tempN->data = data;

    tempN->left = NULL;
    tempN->right = NULL;

    if(root == NULL)
    {
        root = tempN;
    }
    else
    {
        current = root;
        parent = NULL;

        while(1)
        {
            parent = current;
            if(data < parent->data)
            {
                current = current->left;

                if(current == NULL)
                {
                    parent->left = tempN;
                    return;
                }
            }
            else{

                current = current->right;

                if(current==NULL)
                {
                    parent->right = tempN;
                    return;
                }
            }

        }
    }
}

void pre_order(struct node *root)
{

    if(root!=NULL)
    {
        printf("%d ",root->data);
        pre_order(root->left);
        pre_order(root->right);
    }
}

void in_order(struct node *root)
{

    if(root!=NULL)
    {
        in_order(root->left);
        printf("%d ",root->data);
        in_order(root->right);
    }
}

void post_order(struct node *root)
{
    if(root!=NULL)
    {
        post_order(root->left);
        post_order(root->right);
        printf("%d ",root->data);
    }
}
void main()
{

    int data,n;

    printf("No.of elements : ");
    scanf("%d",&n);
    printf("\nElements for the tree:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&data);
        insert(data);
    }

    printf("\nselect 1 - Pre-Order\t2 - In-Order\t3 - Post-Order : ");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
            printf("\nPre-Order Traversal :\n");
            pre_order(root);
            break;
        case 2:
            printf("\nIn-Order Traversal :\n");
            in_order(root);
            break;
        case 3:
            printf("\nPost-Order Traversal :\n");
            post_order(root);
            break;
        default:
            printf("\nInvalid input !!");
            break;
    }
}
