#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct song
{
    struct song *prev;
    char name[20];
    char s_name[20];
    int id;
    float time;
    struct song *next;
};
typedef struct song *node;
node getnode();
node insert_front(node head,char name[20],char s_name[20],int id,float time);
node del_song_id(node head,int id);
void spec_singer(node head,char sname[20]);
void dis_len(node head);
void dis_prev_next(node head,char name[20]);
void display(node head);
int main()
{
    int ch;node head=NULL;
     char name[20];
    char s_name[20];char sname[20];
    int id;
    float time;
    while(1)
    {
        printf("Enter the operations\n");
        printf("1.insert front\n2.Display\n3.Delete song based on ID\n4.Display the song based on Singer\n5.Display details of song which has maximum Duration\n6.Display Pre and Next\n7.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the details of the song\n");
                   printf("Name_song\tSinger name\tID\tDuration in minutes\n");
                   scanf("%s%s%d%f",name,s_name,&id,&time);
                   head=insert_front(head,name,s_name,id,time);
                   break;
            case 2:display(head);
                   break;
            case 3:printf("Enter the ID of the song\n");
                   scanf("%d",&id);
                   head=del_song_id(head,id);
                   break;
            case 4:printf("Enter the Name of the Singer \n");
                   scanf("%s",sname);
                  spec_singer(head,sname);
                  break;
            case 5:dis_len(head);
                   break;
            case 6:printf("Enter the Name of the Song \n");
                   scanf("%s",name);
                   dis_prev_next(head,name);
                   break;
            case 7:exit(0);
        }
    }

}
node getnode()
{
    node t;
    t=(struct song*)malloc(sizeof(struct song));
    if(t==NULL)
    {
        printf("Node is not created\n");
        exit(0);
    }
    t->prev=NULL;
    t->next=NULL;
    return t;
}
node insert_front(node head,char name[20],char s_name[20],int id,float time)
{
    node t;node c=head;
    t=getnode();
    strcpy(t->name,name);
    strcpy(t->s_name,s_name);
    t->id=id;
    t->time=time;
    if(head==NULL)
    {
        return t;
    }
    t->next=c;
    c->prev=t;
    head=t;
    return head;
}
void display(node head)
{
    node t;
    t=head;
     if(head==NULL)
    {
        printf("Empty list\n");
        return;

    }
    while(t!=NULL)
    {
        printf("\n");
        printf("%s\n%s\n%d\n%f\n",t->name,t->s_name,t->id,t->time);
        printf("\n");
        t=t->next;
    }
}
node del_song_id(node head,int id)
{
    node cur,follow;
    cur=follow=head;
     if(head==NULL)
    {
        printf("Empty list\n");
        return 0;
     }
     while(cur!=NULL)
    {
        if(cur->id==id)
        {
            follow->next=cur->next;
            (cur->next)->prev=follow;
                free(cur);
        }
        cur=cur->next;
    }
    return head;
}
void spec_singer(node head,char sname[20])
{
    node t;int c;
    t=head;
     if(head==NULL)
    {
        printf("Empty list\n");

     }
     while(t!=NULL)
    {
        if(strcmp(sname,t->s_name)==0)
        {
            printf("%s\n%s\n%d\n%f\n",t->name,t->s_name,t->id,t->time);
        }
        t=t->next;
    }

}
void dis_len(node head)
{
    node t,m;int c;
    t=head;int k=0;
     if(head==NULL)
    {
        printf("Empty list\n");

     }
     while(t!=NULL)
    {
        if((t->time) > k)
        {
            k=t->time;
            m=t;

        }
        t=t->next;
    }
   printf("%s\n%s\n%d\n%f\n",m->name,m->s_name,m->id,m->time);

}
void dis_prev_next(node head,char name[20])
{
    node cur,follow;
    cur=follow=head;
     if(head==NULL)
    {
        printf("Empty list\n");

     }
     while(cur!=NULL)
    {
        if(strcmp(name,cur->name)==0)
        {
           printf("%s\n%s\n%d\n%f\n",(cur->next)->name,(cur->next)->s_name,(cur->next)->id,(cur->next)->time);
           printf("%s\n%s\n%d\n%f\n",(cur->prev)->name,(cur->prev)->s_name,(cur->prev)->id,(cur->prev)->time);
        }
        cur=cur->next;
    }

}


