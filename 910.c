#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct pb
{
    char name[20];
    char add[20];
    char p_no[20];
    int sim_no;
};
void read(struct pb a[50],int n);
void display(struct pb a[50],int n);
void search(struct pb a[50],int n);
void address(struct pb a[50],int n);
void update(struct pb a[50],int n);
int main()
{
    struct pb a[50];
    int n,ch;
    printf("Enter the value of n\n");
    scanf("%d",&n);
    if(n>0 && n<=50)
    {
        read(a,n);
    display(a,n);
    while(1)
    {
        printf("Enter the operations\n");
        printf("1.Search person enter his phone number\n2.Update the adress give the name\n3.To display based on adress\n4.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:search(a,n);
                   break;
            case 2:update(a,n);
                   break;
            case 3:address(a,n);
                   break;
            case 4:exit(0);
        }
    }
    }
    else
    {
        printf("Enter valid n value\n");
    }
}
void read(struct pb a[50],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Name\nAddress\nPhone Number\nSim slot no.\n");
        scanf("%s%s%s%d",a[i].name,a[i].add,a[i].p_no,&a[i].sim_no);
    }
}
void display(struct pb a[50],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\n%s\n%s\n%s\n%d\n",a[i].name,a[i].add,a[i].p_no,a[i].sim_no);
    }
}
void address(struct pb a[50],int n)
{
    char d[20];
    int c;
    printf("Enter the address\n");
    scanf("%s",d);
     int i;
    for(i=0;i<n;i++)
    {
        c=strcmp(a[i].add,d);
        if(c==0)
        {
        printf("\n%s\n%s\n%s\n%d\n",a[i].name,a[i].add,a[i].p_no,a[i].sim_no);
        }
    }
}
void search(struct pb a[50],int n)
{
     char d[20];
    int c;
    printf("Enter the Phone number\n");
    scanf("%s",d);
     int i;
    for(i=0;i<n;i++)
    {
        c=strcmp(a[i].p_no,d);
        if(c==0)
        {
        printf("\n%s\n%s\n%s\n%d\n",a[i].name,a[i].add,a[i].p_no,a[i].sim_no);
        }
}
}
void update(struct pb a[50],int n)
{
    char b[20],d[20];int c;
    printf("Enter the name\n");
    scanf("%s",b);
     printf("Enter the Adress to be update\n");
    scanf("%s",d);
      int i;
    for(i=0;i<n;i++)
    {
        c=strcmp(a[i].name,b);
        if(c==0)
        {
            strcpy(a[i].add,d);
        printf("\n%s\n%s\n%s\n%d\n",a[i].name,a[i].add,a[i].p_no,a[i].sim_no);
        }
}

}

