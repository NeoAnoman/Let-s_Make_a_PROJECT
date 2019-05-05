#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include <time.h>

int introduction()
{
    //gotoxy(00,00);
    //SetColor(500);
    printf("\n\t||      || ||||||| ||      ||||||  |||||| ||||| ||||| |||||||           |||||||| |||||||     ");
    printf("\n\t||      || ||      ||      ||      ||  || ||  | |  || ||                   ||    ||   ||      ");
    printf("\n\t||  ||  || ||||||  ||      ||      ||  || ||   |   || |||||                ||    ||   ||    ");
    printf("\n\t||  ||  || ||      ||      ||      ||  || ||       || ||                   ||    ||   ||    ");
    printf("\n\t|||||||||| ||||||| ||||||| ||||||  |||||| ||       || |||||||              ||    |||||||   \n ");
    printf("\n\t\t||      || ||||||| ||||||  |||||          ||||||  |||||| |||    ||| ||||||       ");
    printf("\n\t\t||      || ||   || ||  ||  ||  ||         ||      ||  || || |||| || ||        ");
    printf("\n\t\t||  ||  || ||   || ||||    ||  ||         ||  ||| |||||| ||  ||  || |||   ");
    printf("\n\t\t||  ||  || ||   || ||  ||  ||  ||         ||  ||| ||  || ||      || ||         ");
    printf("\n\t\t|||||||||| ||||||| ||   || |||||          ||||||| ||  || ||      || ||||||  \n\n\n ");
    delay(3);

    printf("\n\nPress ENTER to Continue  Or SPACEBAR to Exit: ");
    int ch=getch();
    if(ch==13)
    {
        system("CLS");
//    print
        rules();
    }
    else if(ch==32)
        return ch;

}

void rules()
{
    printf("\n\tRules of the game are as following :");
    printf("\n\t* A random word will appear on the screen.");
    printf("\n\t* You have to write the word below it within specified time limit.");
    printf("\n\t* You have initial time limit of 6 seconds.");
    printf("\n\t* Time limit will decrease on subsequent levels by 0.5 seconds until limit has reached 1.5 seconds.");
    printf("\n\t* You will be awarded 5 Points on every correct response.");
    printf("\n\t* For every incorrect response your Lives will decrease by 1.");
    printf("\n\t* You have initially 5 Lives.");
    printf("\n\t* For every two correct answers your Level will increase.");
    delay(1);
    printf("\n\nPress ENTER to Continue  Or SPACEBAR to go Back : ");
    int ch=getch();
    if(ch==13)
    {
        system("CLS");
    }
    else
    {
        system("CLS");
        introduction();
    }
}
/*void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Stroing start time
    clock_t start_time = clock();

    // looping till required time is not acheived
    while (clock() < start_time + milli_seconds)
        ;
}*/

int starttime,endtime,checkturns=1,Lives=5,Levels=1;;
float timeLimit=5;

void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);
}



void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//char* word()
int wgame(struct user u)
{
    checkturns=1;
    Levels=1;
    Lives=5;
     int val=introduction();

     if(val==32)
        return 0;

   //printf("C programming");
    int flag=1;
    int sco=0;
    int i,j,num;
    srand(time(NULL));
    //for(i=1;i<=5;i++)
   //{
    //num=rand()%100 + 1;
      //printf("%d\n",num);
   //}


   char *rword[102]={"Hello","Country","Rules","House","Unwell","Foreign","Presence",//7
                "Permit","Landed","Construction","Court","Religion","Official",//6
                "Office","Policy","Security","Seniority","Administrative","Premises",//6
                "Summer","Monsoon","Winter","Government","Seasons","Weather","Switch",//7
                "Supply","Clothes","Pronunciation","Evaluate","Electrical","Appliances",//6
                "Building","Disabled","Immediately","Women","Children","Bouquet","Channels",//7
                "Extravaganza","Exotic","Persuasive","Espionage","Obnoxious","Traitor",//6
                "Evidence","Innovative","Conference","Climbed","Alphanumerical","Procedure",//6
                "Session","Obsession","Objection","Opposition","Tender","Inspector",//6
                "Questions","Critical","Eviction","Civilian","Matrix","Mobility",//6
                "Currency","Encryption","Financial","Business","Instantly","Friends","Theory",//7
                "Document","Rehearsal","Organization","Debugging","Development","Programming",//6
                "Scrutiny","Management","Extradited","Commander","Soldier","Souvenir","Memento",//7 83
                "International","Professional","Disciplining","Accusation","Institution","Diplomatic",//6 89
                "Traditional","Cultural","Cultivating","Lauding","Escalation","Wantonly","Provocation",//7
                "Sharpen","Electorate","Connections","Convenience","Generation","Preparation"};//6

do
   {

    SetColor(110);
    gotoxy(45,5);
    printf("LEVEL : %d",Levels);

    SetColor(100);
    static int score=0;
    int i=0;
    char s1[30],s2[30];


    num=rand()%100 + 1;

    gotoxy(30,13);
    printf("Given Word  ");
    gotoxy(50,13);
    printf(" : ");

    for(j=0;*(rword[num]+j)!='\0';j++)
       printf("%c",*(rword[num]+j));
    for(j=0;*(rword[num]+j)!='\0';j++)
       s1[j]=*(rword[num]+j);
    s1[j]='\0';


    gotoxy(30,15);
    SetColor(50);
    printf("Write the word here ");
    gotoxy(50,15);
    printf(" : ");

    starttime=time(NULL);
    //delay(5);
    gets(s2);
    endtime=time(NULL);

    if(endtime-starttime>timeLimit)
    {
      Lives--;
      SetColor(150);
      gotoxy(50,18);
      printf("Time Limit Exceeded!!!");

      if(Lives)
        {
            gotoxy(50,19);
            printf("You have %d Lives left",Lives);
            delay(2);
            system("CLS");
            continue;
        }
      if(!Lives)
        {
            delay(2);
            system("CLS");
            SetColor(110);
            gotoxy(45,5);
            printf("\nYour Final Score Is : %d",score);
            //goto startAgain;
            flag=0;
           // exit(0);
           break;
        }
    }
    else
    {
        if(checkturns>1)
        {
            Levels+=1;
            gotoxy(50,17);
            timeLimit-=0.5;
            checkturns=0;
            printf("Now your time limit is %0.1fs",timeLimit);
          //delay(1);
        }
    }

    SetColor(150);
    gotoxy(50,18);
    if(strcmpi(s1,s2)==0)
    {
        checkturns++;
        printf("Yippee,Correct Answer!!!!:)");
        score+=5;
        gotoxy(50,19);
        SetColor(300);
        printf("Your Score Is : %d",score);
        delay(2);
        system("CLS");
    }
    else
    {

        printf("Sorry,Wrong Answer!:(");
        Lives--;

        gotoxy(50,19);
        SetColor(300);

        if(Lives)
        {
            if(Lives==1)
              printf("You have %d Live left",Lives);
            else
                printf("You have %d Lives left",Lives);
        }

        delay(2);
        system("CLS");

        if(!Lives)
        {
            SetColor(110);
            gotoxy(45,5);
            printf("\nYour Final Score Is : %d",score);
            flag=0;
            //SetColor(0);
            //goto startAgain;
            //exit(0);
            break;
        }
    }

    /*for(j=0;*(rword[num]+j)!='\0';j++)
       {
           scanf("%c",&ch);
           if(ch!=*(rword[num]+j))
           {
                gotoxy(50,17);
                printf("Opps Wrong Answer!!!");
                flag=0;
                exit(0);
           }
           else
           {
               printf("Correct Answer");
               system("CLS");
           }
       }*/
       sco=score;
   }while(flag);
struct stat s;
s.f.accuracy=0;
s.f.t=999990;
s.t.accuracy=0;
s.wscore=sco;
s.t.percent_comp=0;
s.t.time_tkn=0;
s.id=u.id;
//printf("%d",s.wscore);
//getch();
//fflush(stdin);
statcmp(u,s);
}


void SetColor(int ForgC)
{
     WORD wColor;
     //This handle is needed to get the current background attribute

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     //csbi is used for wAttributes word

     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          //To mask out all but the background attribute, and to add the color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}
