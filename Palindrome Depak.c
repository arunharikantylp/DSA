#include<stdio.h>
#include<stdlib.h>
#define max 100
struct stack
	{
		char elements[max];
		int top;
	};
int isempty(struct stack *s);
void push(struct stack *s,char e);
int isfull(struct stack *s);
char pop(struct stack *s);
void initstack(struct stack *s);
int palindrome(char str[]);
int main()
{
char str[max];
printf("Enter the string:");
scanf("%s",str);
int p=palindrome(str);
if(p==1)
{
printf("Palindrome");
}
else
{
printf("NOT PALINDROME");
}
}
void initstack(struct stack *s)
	{
	s->top=-1;
	}
int isempty(struct stack *s)
{
	if(s->top==-1)
	{
	return 1;
	}
	else
	{
	return 0;
	}
}
void push(struct stack *s,char e)
{
	s->top++;
	s->elements[s->top]=e;
}
int isfull(struct stack *s)
{
	if(s->top==max-1)
	{
	return 1;
	}
	else
	{
	return 0;
	}
}
char pop(struct stack *s)
{
	char e=s->elements[s->top];
	s->top--;
	return e;
}
int palindrome(char str[])
{
	struct stack s;
	initstack(&s);
	int i;
	for(i=0;str[i]!='\0';i++)
	{
	push(&s,str[i]);
	}
	i=0;
while(!isempty(&s))
{
if(str[i]!=pop(&s))
return 0;
i++;
}
return 1;
}
