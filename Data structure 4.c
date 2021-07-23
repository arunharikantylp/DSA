#include<stdio.h>
#include<stdlib.h>
struct player
{
    char team_name[20];
    char player_name[20];
    int score;
};
struct player read();
void display(struct player );
int main()
{
    struct player p1;
    struct player p2;
    printf("1st player details");
    p=read();
    printf("2nd player details");
    p2=read();
     printf("1st player informations are");
     display(p1);
     printf("2nd player informations are");
     display(p2);
}
struct player read()
{
    struct player p;
    printf("Read team name\n player\n score\n");
    scanf("%s\n%s\n%d\n",p.team_name,p.player_name,&p.score);
    return p;
};
void display(struct player p)
{
    printf("%s\n%s\n%d\n",p.team_name,p.player_name,p.score);
}


