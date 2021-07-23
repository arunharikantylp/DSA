#include<stdio.h>
#include<stdlib.h>
struct player
{
    char team_name[20];
    char player_name[20];
    int score;
};
main()
{
    struct player p={"India","Mahendra singh Dhoni",258};
    printf("\n%s\n%s\n%d",p.team_name,p.player_name,p.score);
}
