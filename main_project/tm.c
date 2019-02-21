#include<stdio.h>
#include<string.h>
struct user
{
    char name[20];
};
void chstat(struct user u)
{

}
void challenges(struct user u)
{

}
void rmstat(struct user u)
{

}
void tm(struct user u)
{
    system("cls");
    printf("****Welcome to TYPING MASTER %s %s",u.name,"****\n");
    char s1[]="***1.Check your stats***\n2.Go to the challenges\n3.Reset all your stats\n",s2[]="1.Check your stats\n***2.Go to the challenges***\n3.Reset all your stats\n";
    char s3[]="1.Check your stats\n2.Go to the challenges\n***3.Reset all your stats***\n",c;
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
                chstat(u);
            else if(i==2)
                challenges(u);
            else if(i==3)
                rmstat(u);
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
                puts(s1);
                i=1;
            }
        }
    }
}
void main()
{
    struct user u;
    strcpy (u.name,"ME");
    tm(u);
}
