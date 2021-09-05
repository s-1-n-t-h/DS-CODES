//FIBONACCI SERACH
//PRE-REQUISITES = ARRAY MUST BE SORTED IN ASCENDING ORDER BEFORE GIVING AS INPUT
#include<stdio.h>

void main()
{
    int i,j,a[100],offset,M,M1,M2,key,n;//declaration of necessary variables

    printf("\n\tNo.of Elements : ");
    scanf("%d",&n);  //size of array

    printf("\n\tInput the elements : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);  // elements of array
    }

    M2=0;   // Pre-assignment of fibonacci numbers
    M1=1;
    M=M1+M2;

    printf("\n\tSearch Element : ");
    scanf("%d",&key);  // number to be searched

    while(M<n)  // iterating for finding fibonacci just greater than or equal to 'n'- size of the array
    {
        M2=M1;
        M1=M;
        M=M1+M2;
    }

    offset=0;  // useful variable for keeping notes of index

    while(M>1)
    {
        j=M2+offset;  // for first iteration offset = 0

        if(a[j]==key)
        {
            printf("\n\t%d",j);
            break;
        }

        else if(key>a[j])
        {
            offset=j;
            M=M1;
            M1=M2;
            M2=M-M1;
        }
        else
        {
            offset=j;
            M=M2;
            M1=M1-M2;
            M2=M-M1;
        }

    }

    if(M<=1)
    {
        printf("\nThe number is not found in the given array .");
    }

}
