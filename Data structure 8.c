#include<stdio.h>
#include<stdlib.h>
struct data
{
    int roll;
    char name[20];
    char depa[20];
    int year;
};
void read(struct data a[10],int n);
void display(struct data a[10],int n);
void year(struct data a[10],int n);
void roll(struct data a[10],int n);
int main()
{
    struct data a[10];
    int n;
    scanf("%d",&n);
    read(a,n);
    display(a,n);
    year(a,n);
    roll(a,n);
}
void read(struct data a[10],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d%s%s%d",&a[i].roll,a[i].name,a[i].depa,&a[i].year);
    }
}
void display(struct data a[10],int n)
{
    int i;
    for (i=0;i<n;i++)
    {
        printf("\n%d\n%s\n%s\n%d\n",a[i].roll,a[i].name,a[i].depa,a[i].year);
}
}
void year(struct data a[10],int n)
{    int i,Y;
printf("Enter the year\t");
scanf("%d",&Y);
    for (i=0;i<n;i++)
    {
        if(a[i].year==Y)
        {
                    printf("\n%d\n%s\n%s\n%d\n",a[i].roll,a[i].name,a[i].depa,a[i].year);

        }
    }
}
void roll(struct data a[10],int n)
{ int i,R;
printf("Enter the roll no,\t");
scanf("%d",R);
for (i=0;i<n;i++)
    {
        if(a[i].roll==R)
        {
                    printf("\n%d\n%s\n%s\n%d\n",a[i].roll,a[i].name,a[i].depa,a[i].year);

        }
    }
}
