#include<stdio.h>

void main()
{
    int n,a[50],temp;
    printf("No.of Elements : ");
    scanf("%d",&n);
    printf("\nElements : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<a[i])
            {
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
    printf("\n");
    printf("After Selection Sort : ");

    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }

}
