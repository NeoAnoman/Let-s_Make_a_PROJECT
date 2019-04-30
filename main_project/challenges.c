#include<time.h>
#include<math.h>
#include<stdio.h>
#include<string.h>
#include"stat.c"
#include"Project.c"
struct free
{
    char h[100];
    char p[2000];
};
struct stat s;
/*void challengesw(struct user u)
{
    int i,j;
    char c;
    FILE *f1=fopen("freestyle.txt","w"),*f2=fopen("input.txt","r");
    struct free sf[10],sf2[10];
    for (i=0;i<10;i++)
    {
        printf("hello\n");
        j=0;
        while(1)
        {
            c=fgetc(f2);
            if(c!='\n')
                sf[i].h[j++]=c;
            else
            {
                sf[i].h[j++]='\0';
                break;
            }
        }
        printf("%s\nhead end\n",sf[i].h);
        j=0;
        while(1)
        {
            c=fgetc(f2);
            if(c!='\n')
                sf[i].p[j++]=c;
            else
            {
                sf[i].p[j++]='\0';
                break;
            }
        }
        printf("%s\npara end\n",sf[i].p);
        printf("%d\n",i);
    }
    printf("loop break%d",i);
    fclose(f2);
    fwrite(sf,sizeof(sf),2,f1);
    //fseek(f1,SEEK_SET,0printf("%s",sf2[9].p););
    //fread(sf2,sizeof(sf2),10,f1);
    fclose(f1);
    printf("\ndone");
    //printf("%s",sf2[9].p);
}
int challengesview(struct user u)
{
    FILE *f1=fopen("freestyle.txt","a+"),*f2=fopen("input.txt","r");
    fseek(f1,SEEK_SET,0);
    struct free sf2[10];
    int i;
    fread(sf2,sizeof(sf2),1,f1);
    for (i=0;i<10;i++)
    {
        printf("\n");
        printf("struct free
{
    char h[100];
    char p[2000];
};%s\n%s\n",sf2[i].h,sf2[i].p);
    }
    //printf("%s\n%s\n",sf2[7].h,sf2[7].p,);
    fclose(f1);
    fclose(f2);
    return i;
}*/
/////
void freestyle(struct user u)
{
    system ("cls");
    gotoxy(30,5);
    FILE *font=fopen("fontfree.txt","r");
    while(!feof(font))
    {
        printf("%c",fgetc(font));
    }
    delay(2);
    SetColor(102);
    clock_t start,end;
    //struct fscore f;
    FILE *f1=fopen("freestyle.txt","r");
    char w[30],c1,c2,str[1500];
    int i=0,j=0,k,l;
    system("cls");
    //printf("****WELCOME TO THE FREESTYLE MOD****\nType the following paragraph\n");
    struct free p[10];
    srand(time(0));
    k=rand()%8;
    //k=6;
    fread(p,sizeof(p),1,f1);
    printf("%s\n%s\n\n",p[k].h,p[k].p);
    FILE *f2=fopen("temp.txt","w+");
    fwrite(p[k].p,sizeof(p[k].p),1,f2);
    fseek(f2,SEEK_SET,0);
    //c1='a';
   // str[0]='\0';
    start=time(NULL);
    c1=' ';
    while(!feof(f2) && c1!='\0')
    {
        fflush(stdin);
        system("cls");
        printf("****WELCOME TO THE FREESTYLE MOD****\nType the following paragraph\n");
        printf("%s\n",p[k].h);
        for(l=0;l<=strlen(p[k].p);l++)
        {
            if(l==i)
                printf("*_*");
            printf("%c",p[k].p[l]);
        }
        c2=getch();
        c1=fgetc(f2);
        //str[i]=c2;
        //str[i+1]='\0';
        //printf("\n%s",str);
        //c2=getch();
        //printf("( %c )  ",c1);
        //printf("%c ",c2=getch());
        i++;
        if(c1==c2)
            j++;
        //if(i==10)
          //  break;
    }
    end=time(NULL);
   // printf("%d\n%d\n",i,j);
    s.f.t=((double)(end-start));
    float i1=i,i2=j;
    s.f.accuracy=((i2/i1)*100);
    system("cls");
    printf("Great You have finished the challenge!!!!\n\nYour accuracy is :- %.2f\nAnd your Time taken is :-%.0f \n PRESS ANY KEY TO CONTINUE",s.f.accuracy,s.f.t);
    s.t.accuracy=0;
    s.t.time_tkn=99999;
    s.t.percent_comp=0;
    s.wscore=0;
    statcmp(u,s);
    getch();
    //****************************************************     xxstatcmp(u,f);
   // printf("%.0f\n%.2f",f.t,f.accuracy);
    //printf("\n%d\n%d",i,j);
}
/*void wgame(struct user u)
{
    printf("wgame called");
}*/
void rules_tattack()
{

    system("cls");
    printf("The folloing are the rules for playing....\n");
    printf("\nIn Time attack as name suggest you have to fight the clock\nYou r given initially 5 sec to write a word\nSuccessful completion of a word will be awarded by \"+2\" time\n");
    printf("for every wrong word typed would have a penalty of \"-2\" So Be CAREFUL");
    printf("\n\n****That's all for now\n Press any key to continue*****");
    getch();
    system("cls");
    char s1[]={"****1.Read Rules****\t2.Start Challenge\t3.Exit"};
    printf("*********************WELCOME TO THE TIME ATTACK CHALLENGE**********************\n");
    puts(s1);
}
void start(struct user u)
{
    SetColor(98);
    system ("cls");
    gotoxy(30,5);
    FILE *font=fopen("warning.txt","r");
    while(!feof(font))
    {
        printf("%c",fgetc(font));
    }
    delay(3);
    SetColor(102);
    system("cls");
    clock_t start,end,s1,e1;
    printf("*****The challenge is started !!!! *****\n\nNow start writing the following paragraph....\n\n");
    FILE *f1=fopen("freestyle.txt","r");
    char w[30],c1,c2,str[1500];
    float i=0,j=0;
    int k,l,chk;
    double d=5,t=0;
    //printf("****WELCOME TO THE FREESTYLE MOD****\nType the following paragraph\n");
    struct free p[10];
    //struct tscore ts;
    srand(time(0));
    k=rand()%8;
    //k=6;
    fread(p,sizeof(p),1,f1);
    printf("%s\n%s\n\n",p[k].h,p[k].p);
    FILE *f2=fopen("temp.txt","w+");
    fwrite(p[k].p,sizeof(p[k].p),1,f2);
    fseek(f2,SEEK_SET,0);
    //c1='a';
   // str[0]='\0';
   c1=' ';
   s1=time(NULL);
    while(!feof(f2) && c1!='\0' && d>0)
    {
        fflush(stdin);
        /*system("cls");
        printf("****WELCOME TO THE TIME ATTACK MOD****\nType the following paragraph\n");
        printf("%s\n",p[k].h);
        for(l=0;l<=strlen(p[k].p);l++)
        {
            if(l==i)
                printf("*_*");
            printf("%c",p[k].p[l]);
        }*/
        chk=1;
        start=time(NULL);
        c2='a';
        printf("\n");
        while(c2!=' ')
        {
            system("cls");
            printf("****WELCOME TO THE TIME ATTACK MOD****\nType the following paragraph\n");
        printf("%s\n",p[k].h);
        for(l=0;l<=strlen(p[k].p);l++)
        {
            if(l==i)
                printf("*_*");
            printf("%c",p[k].p[l]);
        }
            c2=getch();
            c1=fgetc(f2);
            //printf("%c",c2);
        //str[i]=c2;
        //str[i+1]='\0';
        //printf("\n%s",str);
        //c2=getch();
        //printf("( %c )  ",c1);
        //printf("%c ",c2=getch());
            i++;
            if(c1==c2)
                j++;
            else
                chk=0;
        }
        end=time(NULL);
        t=end-start;
        if(chk==1)
            d=d+2;
        else
            d=d-2;
        d=d-t;
        //if(i==10)
          //  break;
    }
    e1=time(NULL);
    s.t.time_tkn=e1-s1;
    s.t.percent_comp=(i/strlen(p[k].p))*100;
    s.t.accuracy=(j/i)*100;
    printf("%.0f\n%.2f\n%.2f\n",s.t.time_tkn,s.t.percent_comp,s.t.accuracy);
    s.f.accuracy=0;
    s.f.t=99999;
    s.wscore=0;
    statcmp(u,s);
    getch();
    fflush(stdin);
}
void tattack(struct user u)
{
    system ("cls");
    gotoxy(30,5);
    FILE *font=fopen("fonttattack.txt","r");
    while(!feof(font))
    {
        printf("%c",fgetc(font));
    }
    delay(2.2);
    SetColor(102);
    int i=1,c;
    system("cls");
    char s1[]={"****1.Read Rules****\t2.Start Challenge\t3.Exit"},s2[]={"1.Read Rules\t****2.Start Challenge****\t3.Exit"},s3[]={"1.Read Rules\t2.Start Challenge\t****3.Exit****"};
    printf("*********************WELCOME TO THE TIME ATTACK CHALLENGE**********************\n");
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
                rules_tattack();
            }
            else if(i==2)
            {
                start(u);
                system("cls");
                printf("*********************WELCOME TO THE TIME ATTACK CHALLENGE**********************\n");
                puts(s2);
                i=2;
            }
            else if(i==3)
            {
                i=0;
            }
            break;
        case 77:
            if(i==2)
            {
                system("cls");
                printf("*********************WELCOME TO THE TIME ATTACK CHALLENGE**********************\n");
                puts(s3);
                i=3;
            }
            else if(i==1)
            {
                system("cls");
                printf("*********************WELCOME TO THE TIME ATTACK CHALLENGE**********************\n");
                puts(s2);
                i=2;
            }
            else if(i==3)
            {
                system("cls");
                printf("*********************WELCOME TO THE TIME ATTACK CHALLENGE**********************\n");
                puts(s1);
                i=1;
            }
            break;
        case 75:
            if(i==2)
            {
                system("cls");
                printf("*********************WELCOME TO THE TIME ATTACK CHALLENGE**********************\n");
                puts(s1);
                i=1;
            }
            else if(i==1)
            {
                system("cls");
                printf("*********************WELCOME TO THE TIME ATTACK CHALLENGE**********************\n");
                puts(s3);
                i=3;
            }
            else if(i==3)
            {
                system("cls");
                printf("*********************WELCOME TO THE TIME ATTACK CHALLENGE**********************\n");
                puts(s2);
                i=2;
            }
            break;
        }
    }
}
void challenges(struct user u)
{
    int i=1;
    system("cls");
    SetColor(100);
    gotoxy(30,5);
    printf("*********************WELCOME**********************\n");
    gotoxy(30,7);
    SetColor(98);
    printf("select from the following challenges\n");
    char s1[]="***1.Time Attack***\n2.FreeStyle\n3.WordGame\n4.Exit";
    puts(s1);
    char s2[]="1.Time Attack\n***2.FreeStyle***\n3.WordGame\n4.Exit";
    char s3[]="1.Time Attack\n2.FreeStyle\n***3.WordGame***\n4.Exit";
    char s4[]="1.Time Attack\n2.FreeStyle\n3.WordGame\n***4.Exit***";
    char c;
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
                    tattack(u);
                    system("cls");
                    SetColor(100);
                    gotoxy(30,5);
                    printf("*********************WELCOME**********************\n");
                    gotoxy(30,7);
                    SetColor(98);
                    printf("select from the following challenges\n");
                    puts(s1);
                }
            else if(i==2)
                {
                    freestyle(u);
                    system("cls");
                    SetColor(100);
                    gotoxy(30,5);
                    printf("*********************WELCOME**********************\n");
                    gotoxy(30,7);
                    SetColor(98);
                    printf("select from the following challenges\n");
                    puts(s2);
                }
            else if(i==3)
            {
                system("cls");
                wgame(u);
                system("cls");
                SetColor(100);
                gotoxy(30,5);
                printf("*********************WELCOME**********************\n");
                gotoxy(30,7);
                SetColor(98);
                printf("select from the following challenges\n");
                puts(s3);
            }
            else if(i==4)
            {
                i=0;
            }
            break;
        case 72:
            if(i==2)
            {
                system("cls");
                SetColor(100);
                gotoxy(30,5);
                printf("*********************WELCOME**********************\n");
                gotoxy(30,7);
                SetColor(98);
                printf("select from the following challenges\n");
                puts(s1);
                i=1;
            }
            else if(i==3)
            {
                system("cls");
                SetColor(100);
                gotoxy(30,5);
                printf("*********************WELCOME**********************\n");
                gotoxy(30,7);
                SetColor(98);
                printf("select from the following challenges\n");
                puts(s2);
                i=2;
            }
            else if(i==1)
            {
                system("cls");
                SetColor(100);
                gotoxy(30,5);
                printf("*********************WELCOME**********************\n");
                gotoxy(30,7);
                SetColor(98);
                printf("select from the following challenges\n");
                puts(s4);
                i=4;
            }
            else if(i==4)
            {
                system("cls");
                SetColor(100);
                gotoxy(30,5);
                printf("*********************WELCOME**********************\n");
                gotoxy(30,7);
                SetColor(98);
                printf("select from the following challenges\n");
                puts(s3);
                i=3;
            }
            break;
        case 80:
            if(i==2)
            {
                system("cls");
                SetColor(100);
                gotoxy(30,5);
                printf("*********************WELCOME**********************\n");
                gotoxy(30,7);
                SetColor(98);
                printf("select from the following challenges\n");
                puts(s3);
                i=3;
            }
            else if(i==1)
            {
                system("cls");
                SetColor(100);
                gotoxy(30,5);
                printf("*********************WELCOME**********************\n");
                gotoxy(30,7);
                SetColor(98);
                printf("select from the following challenges\n");
                puts(s2);
                i=2;
            }
            else if(i==3)
            {
                system("cls");
                SetColor(100);
                gotoxy(30,5);
                printf("*********************WELCOME**********************\n");
                gotoxy(30,7);
                SetColor(98);
                printf("select from the following challenges\n");
                puts(s4);
                i=4;
            }
            else if(i==4)
            {
                system("cls");
                SetColor(100);
                gotoxy(30,5);
                printf("*********************WELCOME**********************\n");
                gotoxy(30,7);
                SetColor(98);
                printf("select from the following challenges\n");
                puts(s1);
                i=1;
            }
        }
    }
}
/*void main()
{
    struct user u;
    //challengesw(u);
    //challengesview(u);
    challenges(u);
}*/
