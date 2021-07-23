#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct T
{
    int hours;
    int min;
    int sec;
};
struct T read();
void diff(struct T b,struct T c);
int main()
{
    struct T b,c;
    b=read();
    c=read();
    diff(b,c);
}
struct T read()
{
    struct T n;
    printf("Enter the hour in railway time\t");
    scanf("%d",&n.hours);
    if(n.hours>24 || n.hours<=0)
    {
        printf("\nPlease enter raiway time pattern");
    }
    printf("Enter the minutes in railway time\t");
    scanf("%d",&n.min);
    if(n.min>60 || n.min<=0)
    {
        printf("Please enter raiway time pattern\n");
    }
    printf("Enter the seconds in railway time\t");
    scanf("%d",&n.sec);
    if(n.sec>60 || n.sec<=0)
    {
        printf("Please enter raiway time pattern\n");
    }
    return n;
}
void diff(struct T b,struct T c)
{
    int h,m,s,Ans,Ans1,Ans2;
    if(b.sec>c.sec || b.sec<c.sec || b.sec==c.sec)
    {
     Ans=sqrt(pow((b.sec-c.sec),2));

    }
    if(b.min>c.min || b.min<c.min || b.min==c.min )
    {
     Ans1=sqrt(pow((b.min-c.min),2));
    }
    if(b.hours>c.hours || b.hours<c.hours || b.hours==c.hours  )
    {
     Ans2=sqrt(pow((b.hours-c.hours),2));
    }

    printf("\n\nDifference:%d Hours\n%d Minutes\n%d Seconds\n",Ans2,Ans1,Ans);
}
