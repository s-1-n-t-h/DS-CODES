#include<stdio.h>
void merge(int arr[],int l,int mid,int r)
{
    int i,j,k;
    int n1 = mid-l+1;
    int n2 = r-mid;
    int a[n1],b[n2];
    for(i=0;i<n1;i++)
    {
        a[i]=arr[l+i];
    }
    for(i=0;i<n2;i++)
    {
        b[i]=arr[mid+1+i];
    }
    i=0;j=0;k=l;
    while(i<n1 && j<n2)
    {
        if(a[i] < b[j])
        {
            arr[k]=a[i];
            k++;i++;
        }
        else
        {
            arr[k]=b[j];
            k++;j++;
        }
    }
    while(i<n1)
    {
        arr[k]=a[i];
        k++;i++;
    }
    while(j<n2)
    {
        arr[k]=b[j];
        k++;j++;
    }
}

void MergeSort(int arr[],int l,int r)
{
    if(l<r)
    {
        int mid = (l+r)/2;
        MergeSort(arr,l,mid);
        MergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}


void main()
{
   int arr[100],l,r,i,n;
   printf("No.of Elements : ");
   scanf("%d",&n);
   printf("\nElements : ");
   for(i=0;i<n;i++)
   {
       scanf("%d",&arr[i]);
   }
   l=0;r=n;
   MergeSort(arr,l,r);
   printf("\nAfter Merge Sort : ");
   for(i=0;i<n;i++)
   {
       printf("%d ",arr[i]);
   }
}
