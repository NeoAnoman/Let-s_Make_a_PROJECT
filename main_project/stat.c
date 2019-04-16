/*struct user
{
    char name[20];
};*/
void rmstat(struct user u)
{struct statistics
{int ID;
 struct tscore t;
 struct fscore f;
 int wscore;
}sts;
 f1=FILE*rms=fopen("score.txt","r");
 while(!feof(f1))
 {fread(sts,size of(sts),1,f);
  if(sts.id==u.id)
  {printf("TIME ATTACK");
   printf("\n%f",sts.t.percent_comp);
   printf("\n %mm",sts.t.time_tkn);
   printf("\n %f",sts.t.accuracy);
   printf("\n FREESTYLE");
   printf("\n %f",sts.f.accuracy);
   printf("\n %lf",sts.f.t1);
   printf("\n WORD GAME");
   printf("%d",wscore);
  } 
}
void chstat(struct user u)
{

}
void statcmp(struct user u)
{

}
