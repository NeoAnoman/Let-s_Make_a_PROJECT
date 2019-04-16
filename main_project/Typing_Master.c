#include<stdio.h>
#include "user.c"
#include "Project.c"
int welcome()
{
    char cr[30];
    SetColor(99);
    gotoxy(0,5);
    FILE *fil=fopen("typing.txt","r");
    while(!feof(fil))
    {
        fgets(cr,30,fil);
        printf("%s",cr);
    }
    delay(2);
    SetColor(98);
    system("cls");
    printf("*******Welcome to Typing Master******\nUse arrow keys to navigate and 'enter' to make a selection\n\n");
    int i=1;
    char c;
    char s1[]="1.****New User****\n2.Existing User\n3.Exit",s2[]="1.New User\n2.****Existing User****\n3.Exit",s3[]="1.New User\n2.Existing User\n****3.Exit****";
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
            else if(i==2)
                user();
            else if(i==3)
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
            else if(i==3)
            {
                system("cls");
                printf("*******Welcome to Typing Master******\nUse arrow keys to navigate and 'enter' to make a selection\n\n");
                puts(s2);
                i=2;
            }
            else if(i==1)
            {
                system("cls");
                printf("*******Welcome to Typing Master******\nUse arrow keys to navigate and 'enter' to make a selection\n\n");
                puts(s3);
                i=3;
            }
            break;
        case 80:
            if(i==2)
            {
                system("cls");
                printf("*******Welcome to Typing Master******\nUse arrow keys to navigate and 'enter' to make a selection\n\n");
                puts(s3);
                i=3;
            }
            else if(i==1)
            {
                system("cls");
                printf("*******Welcome to Typing Master******\nUse arrow keys to navigate and 'enter' to make a selection\n\n");
                puts(s2);
                i=2;
            }
            else if(i==3)
            {
                system("cls");
                printf("*******Welcome to Typing Master******\nUse arrow keys to navigate and 'enter' to make a selection\n\n");
                puts(s1);
                i=1;
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
