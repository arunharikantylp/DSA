#include<stdio.h>

void swap(int* a,int* b)
{
    int *temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int a[],int low,int high)
{
    int pivot=a[high];

    int i=low-1;
    for(int j=low;j < high;j++)
    {
        if(a[j] < pivot)
            {
                i++;
               swap(&a[i],&a[j]);
            }
    }
    swap(&a[i+1],&a[high]);
    return i+1;
}

void quicksort(int a[],int low,int high)
{

    if(low<high)
    {
        int p=partition(a,low,high);
        quicksort(a,low,p-1);
        quicksort(a,p+1,high);
    }
}

void display(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
}
int main()
{
    int i,n;
    int a[10];
    printf("N==");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    quicksort(a,0,n-1);
    display(a,n);
}

