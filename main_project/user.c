#include <stdio.h>
#include<string.h>
#include"tm.c"
int newuser()
    {
        int i=0;
        system("cls");
        struct user u;
        u.id=0;
        FILE *f= fopen("user.dat","ab+");
        //fseek(f,0,SEEK_SET);
        while(!feof(f))
        {
         fread(&u,sizeof(u),1,f);
        }
        u.id+=1;
        printf("Enter username\n");
        gets(u.name);
        printf("enter password\n");
        u.password[i]=getch();
        printf("*");
        while(u.password[i]!=13)
        {
            u.password[++i]=getch();
            if(u.password[i]!=13)
                printf("*");
        }
        u.password[i]='\0';
        //scanf("%s",&u.password);
        fwrite(&u,sizeof(u),1,f);
        //fseek(f,(-1)*sizeof(u),SEEK_SET);
        //fread(&u,sizeof(u),1,f);
        //printf("%s",u.password);
        fclose(f);
        printf("\nYour credentials have been saved \nand your USER ID IS :-\n%d\nYour password is :-\n%s\nYour UserName is :-\n%s\n",u.id,u.password,u.name);
        getch();
        rmstat(u);
        fflush(stdin);
    /*    FILE *f1= fopen("user.bin","rb");
        fread(&u,sizeof(u),1,f1);
        printf("%s",u.name);
        fclose(f1);
        getch();*/
    }
/*void main()
{
    struct user u;
    u.id=0;
    user();
}*/
void uremove()
{
    system("cls");
    int chk=0;
    FILE *d= fopen("user2.dat","wb+");
    FILE *f= fopen("user.dat","rb+");
    struct user u;
    char username[20];
    char pass[20];
    int uid;
    printf("enter the id number\n");
    scanf("%d",&uid);
    fflush(stdin);
    printf("username to be deleted\n");
    gets(username);
    printf("enter the password for the above username\n");
    fflush(stdin);
    scanf("%s",&pass);
    while(fread(&u,sizeof(u),1,f))
    {
        //printf("%d",u.id);
        if(u.id!=uid)
        {
            fwrite(&u,sizeof(u),1,d);
        }
        else
        {
            if(strcmp(u.name,username)==0&&strcmp(u.password,pass)==0)
            {
                printf("\nID DELETED!!!!");
                chk=1;
                break;
                //rmstat(u);
            }
            else
            {
                fwrite(&u,sizeof(u),1,d);
            }
        }
    }
    //fseek(d,0,SEEK_SET);
    /*while(fread(&u,sizeof(u),1,d))
    {
        printf("\nadskjkdasjas\n%d",u.id);
    }*/
    fclose(f);
    fclose(d);
    remove("user.dat");
    rename("user2.dat","user.dat");
    if(chk==0)
    {
        printf("WRONG CREDENTIALS !!!!");
    }
    getch();
    fflush(stdin);
}
void login()
{
    system("cls");
    int i=0;
    char u[20];
    char PA[20];
    int ui;
    SetColor(98);
    printf("ENTER USERNAME\n");
    gets(u);
    fflush(stdin);
    printf("ENTER PASSWORD\n");
    PA[i]=getch();
        printf("*");
        while(PA[i]!=13)
        {
            PA[++i]=getch();
            if(PA[i]!=13)
                printf("*");
        }
        PA[i]='\0';
    fflush(stdin);
    printf("\nENTER USER ID\n");
    scanf("%d",&ui);
    FILE *f= fopen("user.dat","ab+");
    struct user ull;
    int a=0;
    while(fread(&ull,sizeof(ull),1,f))
    {
        if(strcmp(ull.name,u)==0&&strcmp(ull.password,PA)==0&&ull.id==ui)
            {
                //printf("You Have logged in");
                tm(ull);
                fflush(stdin);
                //getch();
                //tmp(yaha jaao);
                a=1;
                break;
            }
    }
    if(a==0)
    {
        printf("Wrong Credentials");
        fflush(stdin);
        getch();
    }
}
int user()
{
    char c;
    SetColor(98);
    int i=1;
    system("cls");
    char s1[]="Enter Your Choice\n****1.LOGIN****\n2.DELETE A USER\n3.Exit",s2[]="Enter Your Choice\n1.LOGIN\n****2.DELETE A USER****\n3.Exit",s3[]="Enter Your Choice\n1.LOGIN\n2.DELETE A USER\n****3.Exit****";
    gotoxy(30,7);
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
                {
                    login();
                    system("cls");
                    gotoxy(30,7);
                    SetColor(98);
                    puts(s1);
                }
            else if(i==2)
                {
                    uremove();
                    system("cls");
                    gotoxy(30,7);
                    SetColor(98);
                    puts(s2);
                }
            else if(i==3)
                {
                    i=0;
                }
            break;
        case 72:
            if(i==2)
            {
                system("cls");
                gotoxy(30,7);
                SetColor(98);
                puts(s1);
                i=1;
            }
            else if(i==3)
            {
                system("cls");
                gotoxy(30,7);
                SetColor(98);
                puts(s2);
                i=2;
            }
            else if(i==1)
            {
                system("cls");
                gotoxy(30,7);
                SetColor(98);
                puts(s3);
                i=3;
            }
            break;
        case 80:
            if(i==2)
            {
                system("cls");
                gotoxy(30,7);
                SetColor(98);
                puts(s3);
                i=3;
            }
            else if(i==1)
            {
                system("cls");
                gotoxy(30,7);
                SetColor(98);
                puts(s2);
                i=2;
            }
            else if(i==3)
            {
                system("cls");
                gotoxy(30,7);
                SetColor(98);
                puts(s1);
                i=1;
            }
        }
    }
}
