#include<stdio.h>

int parent(int i)
{
    return((i-1)/2);
}

int left(int i)
{
    return(2*i+1);
}
int right(int i)
{
    return(2*i+2);
}

void maxheapify(int arr[] , int n , int i)
{
    int l,r,largest,temp;
    l = left(i);
    r = right(i);

    if(l<n && arr[l] > arr[i])
        largest = l;
    else
        largest = i;

    if(r<n && arr[r] > arr[largest])
        largest  = r;
    if(largest!=i)
    {
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxheapify(arr , n , largest);
    }
}

void deleteRoot(int arr[] , int n)
{
    int lastelement = arr[n-1];
    arr[0] = lastelement;
    n = n-1;
    maxheapify(arr , n , 0);

    printf("\nAfter deletion Root node \n heap is : ");
    for(int i=0;i<n;i++)
    {
        printf("%d " , arr[i]);
    }

}




void main()
{
    int size , i;
    printf("Enter the size of array : ");
    scanf("%d" , &size);
    int arr[size];
    printf("Enter %d element in array : " , size);
    for(i=0;i<size;i++)
    {
        scanf("%d" , &arr[i]);
    }
    printf("Given array is : ");
    for(i=0;i<size;i++)
    {
        printf("%d " , arr[i]);
    }

    for(i=(size-1)/2;i>=0;i--)
        maxheapify(arr,size,i);
    printf("\n\n");
    printf("\nHeap is : ");
    for(i=0;i<size;i++)
    {
        printf("%d " , arr[i]);
    }

    deleteRoot(arr , size);




}









