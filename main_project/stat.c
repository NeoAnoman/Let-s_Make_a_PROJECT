#include<stdio.h>
struct user{
    int id;
    char name[20];
    char password[20];
    };
/*struct tscore
{
    float accuracy;
    double time_tkn;
    float percent_comp;
};
struct user
{
    int id;
    char name[20];
};
struct fscore
{
    float accuracy;
    double t;//use %f to print this
};*/

struct tscore
{
    float accuracy;
    double time_tkn;
    float percent_comp;
};
struct fscore
{
    float accuracy;
    double t;//use %f to print this
};
struct stat
{int id;
 struct tscore t;
 struct fscore f;
 int wscore;
};
void chstat(struct user u)
{
    system("cls");
    struct stat sts;
    FILE *f1=fopen("stat.txt","r");
    while(fread(&sts,sizeof(sts),1,f1))
    {
        if(sts.id==u.id)
        {
            printf("For User %s The Following Are the stats....\n",u.name);
            printf("\nTime Attack Challenge...\n");
            SetColor(98);
            printf("\nPercentage Completion of paragraph : %.2f\n",sts.t.percent_comp);
            printf("Time Taken to Complete that part of paragraph : ");
            if(sts.t.time_tkn==0)
            {
                printf("No Time Availaible !!!");
            }
            else
            {
                printf("%.2f seconds",sts.t.time_tkn);
            }
            printf("\nThe best accuracy till now is : %.2f\n********************************\n",sts.t.accuracy);
            SetColor(102);
            printf("\n FREESTYLE Challenge\n");
            SetColor(98);
            printf("\nThe best accuracy till now : %.2f\n",sts.f.accuracy);
            printf("The best time taken to complete the challenge is : ");
            if(sts.t.time_tkn==0)
            {
                printf("Time Not available yet\n********************************\n");
            }
            else
            {
                printf("%.2f seconds\n********************************\n",sts.f.t);
            }
            SetColor(102);
            printf("\n WORD GAME");
            SetColor(98);
            printf("\n\nBest score : %d\n********************************\n",sts.wscore);
            break;
        }
    }
    fclose(f1);
    getch();
    fflush(stdin);
}
void rmstat(struct user u)
{
    system("cls");
    struct stat sts;
    FILE *f1;
    if(!(f1=fopen("stat.txt","r+")))
    {
        fclose(f1);
        f1=fopen("stat.txt","w+");
    }
    //fseek(f1,0,SEEK_SET);
    int k=0;
    while(fread(&sts,sizeof(sts),1,f1))
    {
        //printf("%d\n%d\n",sts.id,u.id);
        if(sts.id==u.id)
        {
            sts.t.percent_comp=0;
            sts.t.time_tkn=0;
            sts.t.accuracy=0;
            sts.f.accuracy=0;
            sts.f.t=0;
            sts.wscore=0;
            fseek(f1,(-1)*(sizeof(sts)),SEEK_CUR);
            fwrite(&sts,sizeof(sts),1,f1);
            k=1;
            printf("\nTHE STATS ARE RESET\n");
            break;
        }
    }
    if(k==0)
    {
        sts.t.percent_comp=0;
        sts.t.time_tkn=0;
        sts.t.accuracy=0;
        sts.f.accuracy=0;
        sts.f.t=0;
        sts.wscore=0;
        sts.id=u.id;
        fwrite(&sts,sizeof(sts),1,f1);
        gotoxy(30,15);
        printf("\n*********New User Successfully Created**********\n");
    }
    fclose(f1);
    getch();
    fflush(stdin);
}
void statcmp(struct user u,struct stat s)
{
    system("cls");
    //printf("control in function\n");
    struct stat sts;
    FILE *f1=fopen("stat.txt","r+");
    //fseek(f1,0,SEEK_SET);
    while(fread(&sts,sizeof(sts),1,f1))
    {
        //printf("in while loop");
        if(sts.id==u.id)
        {
            //printf("conditions running");
            if(sts.t.percent_comp<=s.t.percent_comp)
            {
                sts.t.percent_comp=s.t.percent_comp;
                if(sts.t.time_tkn<s.t.time_tkn && s.t.percent_comp!=0)
                {
                    sts.t.time_tkn=s.t.time_tkn;
                }
                if(sts.t.accuracy<s.t.accuracy)
                {
                    sts.t.accuracy=s.t.accuracy;
                }
            }
            if(sts.f.accuracy<s.f.accuracy)
            {
                sts.f.accuracy=s.f.accuracy;
            }
            if(sts.f.t>=s.f.t)
            {
                sts.f.t=s.f.t;
            }
            else if(sts.f.t==0 && s.f.accuracy!=0)
            {
                sts.f.t=s.f.t;
            }
            if(sts.wscore<s.wscore)
            {
             //   printf("\ntrue");
                sts.wscore=s.wscore;
            }
            fseek(f1,(-1)*(sizeof(sts)),SEEK_CUR);
            fwrite(&sts,sizeof(sts),1,f1);
            break;
        }
    }
    fclose(f1);
    printf("\nThe Stats are saved...\n");
    getch();
}
/*void main()
{
    struct stat s;
    s.id=1;
    s.t.accuracy=100;
    s.t.percent_comp=89;
    s.t.time_tkn=55;
    struct user u;
    u.id=1;
    //FILE *f=fopen("stat.txt","w");
    //fwrite(&s,sizeof(s),1,f);
    rmstat(u);
    //fclose(f);
}*/
