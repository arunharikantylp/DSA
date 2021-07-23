#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
struct stack
{
    int a[MAX];
    int top;
};
void initstack(struct stack *s);
void push(struct stack *s,char e);
int size(struct stack *s);
char peek(struct stack *s);
int isoperand(char t);
int isoperator(char t);
char pop(struct stack *s);
int isempty(struct stack *s);
int isfull(struct stack *s);
void convert_postfix(char infix[MAX],char postfix[MAX]);
main()
{
    char infix[MAX];
     char postfix[MAX];
     printf("Enter the infix\n\n");
     gets(infix);
     convert_postfix(infix,postfix);
    puts(postfix);
}
void initstack(struct stack *s)
{
    s->top=-1;
}
void push(struct stack *s,char e)
{
    s->top++;
    s->a[s->top]=e;
}

char pop(struct stack *s)
{
    char e=s->a[s->top];
    (s->top)--;
    return e;
}
int isempty(struct stack *s)
{
    if(s->top==-1)
        return 1;
    else
        return 0;
}
int isfull(struct stack *s)
{
    if(s->top>=(4-1))
        return 1;
    else
        return 0;
}
int size(struct stack *s)
{
    return s->top+1;
}
char peek(struct stack *s)
{
    return s->a[s->top];
}
int isoperand(char t)
{
    if(t>='A' && t<='Z')
    {
        return 1;
    }
     else if(t>='a' && t<='z')
    {
        return 1;
    }
      else if(t>='0' && t<='9')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isoperator(char t)
{
    if(t=='(' || t=='+' || t=='-' || t=='*' || t=='/'|| t=='$')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int prec(char t)
{
    int p;
    switch(t)
    {
        case '$':p=3;
                break;

        case '*':
        case '/':p=2;
                break;

         case '+':
         case '-':p=1;
                  break;

         default:p=-1;
    }
    return p;
}
 void convert_postfix(char infix[MAX],char postfix[MAX])
 {
     struct stack s;
     initstack(&s);
     int i,j=0;
     for(i=0;infix[i]!='\0';i++)
     {
         if(isoperand(infix[i]))
         {
             postfix[j]=infix[i];
             j++;
         }
         else if(isoperator(infix[i]))
         {
             if(isempty(&s) || infix[i]=='(')
             {
                 push(&s,infix[i]);
             }
             else
             {


                while(!isempty(&s) && prec(infix[i]) <= prec(peek(&s)))
             {
                 postfix[j]=pop(&s);
                 j++;
             }
             push(&s,infix[i]);
             }

         }
         else if(infix[i]==')')
         {
             while(!isempty(&s) && peek(&s)!='(')
             {
                 postfix[j]=pop(&s);
                 j++;
             }
             pop(&s);
         }


     }
      while(!isempty(&s))
         {
             postfix[j]=pop(&s);
             j++;
         }
         postfix[j]='\0';
 }

