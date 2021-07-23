#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct hotel
{
    char name[20];
    float star;
    int no_rooms;
    char city[20];
    int no_emp;
};
void read(struct hotel a[50],int n);
void print(struct hotel a[50],int n);
void min_rooms(struct hotel a[50],int n);
void details(struct hotel a[50],int n);
int main()
{
    int n;
    struct hotel a[50];
    printf("Enter the value of n\t");
    scanf("%d",&n);
    read(a,n);
    print(a,n);
    min_rooms(a,n);
    details(a,n);
}
void read(struct hotel a[50],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%s%f%d%s%d",a[i].name,&a[i].star,&a[i].no_rooms,a[i].city,&a[i].no_emp);
    }
}
void print(struct hotel a[50],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Entered details %d are\n",i+1);
        printf("%s\n%f\n%d\n%s\n%d\n",a[i].name,a[i].star,a[i].no_rooms,a[i].city,a[i].no_emp);
    }
}
void min_rooms(struct hotel a[50],int n)
{
    int i;
    int minimum=a[0].no_rooms;
    for(i=0;i<n;i++)
    {
        if(a[i].no_rooms<minimum)
        {
            minimum=a[i].no_rooms;

        }
        printf("The room %d has minimum rooms and its details are %s\n%f\n%d\n%s\n%d\n",i,a[i].name,a[i].star,a[i].no_rooms,a[i].city,a[i].no_emp);
    }


}

void details(struct hotel a[50],int n)
{
    int i;
    char s1[20];
    printf("Enter the city\t");
     scanf("%s",s1);
    for(i=0;i<n;i++)
    {
    if(strcmp(a[i].city,s1)==0)
        {
            printf("%s\n%f\n%d\n%s\n%d\n",a[i].name,a[i].star,a[i].no_rooms,a[i].city,a[i].no_emp);
        }
    }
}

