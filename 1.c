#include<stdio.h>

int LinearSearch(int arr[],int x,int k)
{
    for(int i=0;i<x;i++)
    {
        if(arr[i]==k)
        {
            return i;
        }
    }
    return -1;
}

void main()
{
    int n,a[100],i,key;

    printf("\n\tNo.of Elements : ");
    scanf("%d",&n);

    printf("\n\tInput the elements : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n\tSearch Element : ");
    scanf("%d",&key);

    printf("\n\tThe index in the array is : %d.",LinearSearch(a,n,key));


}
