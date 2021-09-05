#include<stdio.h>
int main()
{
	int a[50],i,j,n,t;
	printf("Enter number of elements\n");
	scanf("%d",&n);
	printf("\nEnter the elements:\n ");
	for(i=0;i<n;i++)
	{
	scanf("%d",&a[i]);
    }
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	printf("Sorted array in ascending order\n");
	for(i=0;i<n;i++)
	{
		printf("%d \t",a[i]);
	}
	printf("\n");
	return 0;
}
