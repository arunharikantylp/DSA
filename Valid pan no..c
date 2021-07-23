#include<stdio.h>
#include<string.h>
int main()
{
    char a[10];
    printf("Enter the PAN number\n");
    scanf("%s",a);
    int i;
 for(i=0;i<5;i++)
    {
        if(a[i] >= 'a' && a[i] <= 'z' || a[i] >= 'A' && a[i] <= 'Z')
        {
            i++;
        }

    }

    for(i=5;i<9;i++)
    {
        if(a[i] >= 0 && a[i] <= 9)
        {
            i++;
        }

    }

    if(a[i] >= 'a' && a[i] <= 'z' || a[i] >= 'A' && a[i] <= 'Z')
    {
        printf("Entered PAN card number is valid\n");
    }
    else
        {
            printf("Sorry\n");
        }


}

