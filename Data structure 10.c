#include<stdio.h>
void read(int a[10],int n);
void display(int a[10],int n);
void sort(int a[10],int n);
int main()
{
    int a[10];
    int n;
    printf("Enter the value of n");
    scanf("%d",&n);
    read(a,n);
    display(a,n);
    sort(a,n);
    display(a,n);

}
void read(int a[10],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void display(int a[10],int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}
void sort(int a[10],int n)
{
    int i,j;
    int temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }

}
