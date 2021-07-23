#include<stdio.h>
int main()
{
FILE *fp1,*fp2,*fp3;
char name[20];
int r;
fp1=fopen("name.txt","r");
fp2=fopen("roll.txt","r");
if(fp1==NULL || fp2==NULL)
{
printf("File error\n");

}
fp3=fopen("res.txt","w");
if(fp3==NULL)
{
printf("File error\n");

}
while(!feof(fp1))
{
if(feof(fp1))
break;
fscanf(fp1,"%s",name);
fscanf(fp2,"%d",&r);
fprintf(fp3,"%s:%d\n",name,r);
}
fclose(fp1);
fclose(fp2);
fclose(fp3);
}
