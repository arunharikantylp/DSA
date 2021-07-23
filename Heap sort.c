#include<stdio.h>
void heapify(int a[],int n,int i)
{
    int left=2*i+1;
    int right=2*i+2;
    int max=i;
    if(left < n && a[left]> a[max])
        max=left;
    if(right < n &&  a[right]> a[max])
       max= right;
    if(max!=i)
    {
        swap(&a[i],&a[max]);
        heapify(a,n,max);
    }
}
void heapsort(int a[],int n)
{
    int i;
    for(i=(n-1)/2;i>=0;i--)
    {
        heapify(a,n,i);
    }
    for(i=n-1;i>0;i--)
    {
        swap(&a[i],&a[0]);
        heapify(a,i,0);
    }
}
void display(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
}
void swap(int* a,int* b)
{

    int *temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int main()
{
    int i,n;
    int a[10];
    printf("N==");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    display(a,n);
    heapsort(a,n);
    printf("ANS\t");
    display(a,n);
}
