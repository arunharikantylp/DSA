#include<stdio.h>
#include<stdlib.h>
int sum(int n);
main()
{
    int n,s;
    scanf("%d",&n);
    s=sum(n);
    printf("%d",s);
}
int sum(int n)
{
    if(n==1)
        return 1;
    else
    {
        return n+sum(n-1);
    }
}
