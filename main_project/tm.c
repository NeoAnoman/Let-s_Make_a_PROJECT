#include<stdio.h>
#include<string.h>
#include"challenges.c"
/*void chstat(struct user u)
{

}
void rmstat(struct user u)
{

}*/
void tm(struct user u)
{
    system("cls");
    SetColor(100);
    FILE *font=fopen("tm.txt","r");
    while(!feof(font))
    {
        printf("%c",fgetc(font));
    }
    delay(2);
    SetColor(102);
    system("cls");
    printf("****Welcome to TYPING MASTER %s %s",u.name,"****\n");
    char s1[]="***1.Check your stats***\n2.Go to the challenges\n3.Reset all your stats\n4.Exit",s2[]="1.Check your stats\n***2.Go to the challenges***\n3.Reset all your stats\n4.Exit";
    char s3[]="1.Check your stats\n2.Go to the challenges\n***3.Reset all your stats***\n4.Exit",c,s4[]="1.Check your stats\n2.Go to the challenges\n3.Reset all your stats\n***4.Exit***";
    puts(s1);
    int i=1;
    while(i!=0)
    {
        c=getch();
        if(c<0)
            c=getch();
        switch(c)
        {
        case 13:
            if(i==1)
                {
                    chstat(u);
                    system("cls");
                    SetColor(102);
                    printf("****Welcome to TYPING MASTER %s %s",u.name,"****\n");
                    puts(s1);
                    i=1;
                }
            else if(i==2)
                {
                    challenges(u);
                    system("cls");
                    SetColor(102);
                    printf("****Welcome to TYPING MASTER %s %s",u.name,"****\n");
                    puts(s2);
                    i=2;
                }
            else if(i==3)
                {
                    rmstat(u);
                    system("cls");
                    SetColor(102);
                    printf("****Welcome to TYPING MASTER %s %s",u.name,"****\n");
                    puts(s3);
                    i=3;
                }
            else if(i==4)
                i=0;
            break;
        case 72:
            if(i==2)
            {
                system("cls");
                printf("****Welcome to TYPING MASTER %s %s",u.name,"****\n");
                puts(s1);
                i=1;
            }
            else if(i==3)
            {
                system("cls");
                printf("****Welcome to TYPING MASTER %s %s",u.name,"****\n");
                puts(s2);
                i=2;
            }
            else if(i==1)
            {
                system("cls");
                printf("****Welcome to TYPING MASTER %s %s",u.name,"****\n");
                puts(s4);
                i=4;
            }
            else if(i==4)
            {
                system("cls");
                printf("****Welcome to TYPING MASTER %s %s",u.name,"****\n");
                puts(s3);
                i=3;
            }
            break;
        case 80:
            if(i==2)
            {
                system("cls");
                printf("****Welcome to TYPING MASTER %s %s",u.name,"****\n");
                puts(s3);
                i=3;
            }
            else if(i==1)
            {
                system("cls");
                printf("****Welcome to TYPING MASTER %s %s",u.name,"****\n");
                puts(s2);
                i=2;
            }
            else if(i==3)
            {
                system("cls");
                printf("****Welcome to TYPING MASTER %s %s",u.name,"****\n");
                puts(s4);
                i=4;
            }
            else if(i==4)
            {
                system("cls");
                printf("****Welcome to TYPING MASTER %s %s",u.name,"****\n");
                puts(s1);
                i=1;
            }
        }
    }
}
/*void main()
{
  //  delay(1);
    struct user u;
    strcpy (u.name,"ME");
    tm(u);
}*/
