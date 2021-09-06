#include<stdio.h>

int min(int x,int y)
{
	return(x<=y)?x:y;
}

int Search(int arr[],int x,int n)
{
	int m2=0;
	int m1=1;
	int m=m2+m1;

	while(m<n)
	{
		m2=m1;
		m1=m;
		m=m2+m1;
	}
	int s=-1;
	while(m>1)
	{
		int i =min(s+m2,n-1);
		if(arr[i]<x)
		{
			m=m1;
			m1=m2;
			m2=m-m1;
			s=i;
		}
		else if(arr[i]>x)
		{
			m=m2;
			m1=m1-m2;
			m2=m-m1;
		}
		else
		{
			return i;
		}
		if(m&&arr[s+1]==x)
		{
		    return s+1;
		}
		return -1;
	}
}

int main(void)
{
	int arr[10]={11,12,13,14,15};
	int n=sizeof(arr)/sizeof(arr[0]);
	int x=15;
	int d=Search(arr,x,n);
	if(d>=0)
	printf("Element is found at position %d",d);
	else
	printf("Number not found",x);
	return 0;
}
