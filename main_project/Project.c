#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include <time.h>


void introduction()
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
    printf("\n\t\t|||||||||| ||||||| ||   || |||||          ||||||| ||  || ||      || ||||||  \n ");
    delay(3);
    system("CLS");

}

void rules()
{
    printf("")
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

int starttime,endtime,d=5,checkturns=0;

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
void wgame()
{
     introduction();

   //printf("C programming");
    int flag=1;

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
    if(endtime-starttime>d)
    {
      SetColor(150);
      gotoxy(50,17);
      printf("Time Limit Exceeded!!!");
      printf("\nYour Final Score Is : %d",score);
      exit(0);
    }
    else
    {
        if(checkturns>4)
            d-=1;
    }

    SetColor(150);
    gotoxy(50,17);
    if(strcmpi(s1,s2)==0)
    {
        checkturns++;
        printf("Yippee,Correct Answer!!!!:)");
        score+=100;
        gotoxy(50,18);
        SetColor(300);
        printf("Your Score Is : %d",score);
        delay(2);
        system("CLS");
    }
    else
    {

        printf("Sorry,Wrong Answer!:(");
        gotoxy(50,18);
        SetColor(300);
        printf("Your Final Score Is : %d",score);
        flag=0;
        exit(0);
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
   }while(flag);

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
