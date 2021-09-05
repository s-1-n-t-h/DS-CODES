#include <stdio.h>
void main()
{
  int a[100],n,i,count,temp;
  printf("Enter the no of elements to be entered:");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
     scanf("%d",&a[i]);
  }
  count=1;
  while(count<n)
  {
      for(i=0;i<n-count;i++)
      {
          if(a[i]>a[i+1])
          {
          temp=a[i];
          a[i]=a[i+1];
          a[i+1]=temp;
          }
      }
      count++;
  }
  for(i=0;i<n;i++)
  {
    printf("%d\t",a[i]);
  }
}
