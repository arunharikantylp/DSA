#include<stdio.h>
#include<stdlib.h>
struct player
{
    char team_name[20];
    char player_name[20];
    int score;
};
struct player read();
void display(struct player p1);
int main()
{
    struct player p2;
    p2=read();
    display(p2);
}
struct player read()
{
    struct player p1;
    printf("Read team name\n player\n score\n");
    scanf("%s\n%s\n%d\n",p1.team_name,p1.player_name,&p1.score);
    return p1;
};
void display(struct player p1)
{
    printf("%s\n%s\n%d\n",p1.team_name,p1.player_name,p1.score);
}

