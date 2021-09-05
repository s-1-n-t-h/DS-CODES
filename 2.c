#include<stdio.h>
int BinarySearch(int arr[],int n,int key)
{
    int s,e,mid;
    s=0;e=n;
    while(s<=e)
    {
        mid = ((s+e)/2);
        if(arr[mid]==key)
        {
            return mid;
        }
        else if(arr[mid]>key)
        {
            e = mid-1;
        }
        else
        {
            s=mid+1;
        }
    }
    return -1;
}
void main()
{
    int n,a[100],key,i;
    printf("\n\tNo.of elements : ");
    scanf("%d",&n);
    printf("\n\tInput the elements : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("\n\tSearch Element : ");
    scanf("%d",&key);
    printf("\n\tThe index in the array is : %d.",BinarySearch(a,n,key));
}
