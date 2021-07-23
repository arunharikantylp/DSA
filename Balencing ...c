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
char peek(struct stack *s);
void initstack(struct stack *s);
int isvalid(char exp[]);
int main()
{
char exp[max];
printf("Enter parenthesis expression:");
scanf("%s",exp);
int v=isvalid(exp);
if(v==1)
{
printf("Valid Expression");
}
else
{
printf("Invalid Expression");
}
}
int isvalid(char exp[])
{
struct stack s;
initstack(&s);
int i;
for(i=0;exp[i]!='\0';i++)
{
	if(exp[i]=='{'||exp[i]=='['||exp[i]=='(')
	{
	push(&s,exp[i]);
	}
		else if(exp[i]=='}'||exp[i]==']'||exp[i]==')')
		{
		if(isempty(&s))
		return 0;
		else if(exp[i]=='}'&&peek(&s)!='{')
		return 0;
		else if(exp[i]==']'&&peek(&s)!='[')
		return 0;
		else if(exp[i]==')'&&peek(&s)!='(')
		return 0;
		pop(&s);
		}
}
return isempty(&s);
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
char peek(struct stack *s)
{
	return s->elements[s->top];
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
