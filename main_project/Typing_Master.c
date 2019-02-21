#include<stdio.h>
#include "user.c"
#include "stat.c"
#include "challenges.c"
#include "tm.c"
int welcome()
{
    printf("*******Welcome to Typing Master******\nUse arrow keys to navigate and 'enter' to make a selection\n\n");
    int i=1;
    char c;
    char s1[]="1.****New User****\n2.Existing User",s2[]="1.New User\n2.****Existing User****";
    puts(s1);
    while(i!=0)
    {
        c=getch();
        if(c<0)
            c=getch();
        switch(c)
        {
        case 13:
            if(i==1)
                newuser();
            else
                user();
            i=0;
            break;
        case 72:
            if(i==2)
            {
                system("cls");
                printf("*******Welcome to Typing Master******\nUse arrow keys to navigate and 'enter' to make a selection\n\n");
                puts(s1);
                i=1;
            }
            else
            {
                system("cls");
                printf("*******Welcome to Typing Master******\nUse arrow keys to navigate and 'enter' to make a selection\n\n");
                puts(s2);
                i=2;
            }
            break;
        case 80:
            if(i==2)
            {
                system("cls");
                printf("*******Welcome to Typing Master******\nUse arrow keys to navigate and 'enter' to make a selection\n\n");
                puts(s1);
                i=1;
            }
            else
            {
                system("cls");
                printf("*******Welcome to Typing Master******\nUse arrow keys to navigate and 'enter' to make a selection\n\n");
                puts(s2);
                i=2;
            }
        }
    }
    return 0;
}
void main()
{
    welcome();
   /* char c;
    while(c!='a')
    {
        fflush(stdin);
        c=getch();
        c=getch();
        printf("\n\n%d\n\n%c",c,c);
    }*/
}
