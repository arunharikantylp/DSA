#include<stdio.h>
#include<stdlib.h>
struct diff
{
    int hours;
    int minutes;
};
struct diff read();
void display(struct diff h,struct diff m);
void sub(struct diff h,struct diff m);
int main()
{
    struct diff h,m,H;
    printf("Enter the value of hours and minutes");
    h=read();
    m=read();
    sub(h,m);
}
struct diff read()
{
    struct diff a;
    scanf("%d%d",&a.hours,&a.minutes);
    return a;
};
void sub(struct diff h,struct diff m)
{
    int ans,sub;
    ans=h.hours+h.minutes;
    printf("%d.%d hours\n",h.hours,h.minutes);
    sub=m.hours+m.minutes;
    printf("%d.%d hours",m.hours,m.minutes);
    if (ans>sub)
        printf("%d-%d",ans,sub);
    else
     printf("%d-%d",sub,ans);

}
