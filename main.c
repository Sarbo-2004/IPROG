#include<stdio.h>
#include<string.h>
#include<stdlib.h>


char team1[50],team2[50],t_won[50],t_choose[50],player[50],striker[50],nonstriker[50],bowler[50];
int overs,run,score=0;

typedef struct batsman{
  char name[50];
  int balls_faced;
  int runs;
  float strikerate;
} ba;

typedef struct bowler{
  char name[50];
  int runs_given;
  int wikets_taken;
  float economy;
} bow;

void member_input()
{
    FILE *fp, *fp1;
    fp=fopen(team1,"w");
      if (fp == NULL)
    {
        printf("Error opening file!\n");
        //return 1;
    }

    printf("For %s\n",team1);   
    for (int i = 1; i <= 11; i++) 
    {
        printf("enter player %d: ",i,team1);
        scanf("%s",player);
        fprintf(fp, "%s\n", player);
    }
    
    
    fclose(fp);
    fp1=fopen(team2,"w");
      if (fp1 == NULL)
    {
        printf("Error opening file!\n");
        //return 1;
    }
    
    printf("For %s\n",team2);  
    for (int j= 1; j <= 11; j++) 
    {
        printf("enter player %d: ",j,team2);
        scanf("%s",player);
        fprintf(fp1, "%s\n", player);
    }
    
    
    fclose(fp1);
}

void match_input(){
    int c,d,wicket;
    float runrate;
    printf("Enter Batsman1:\n");
    scanf("%s",striker);
    printf("Enter Batsman2:\n");
    scanf("%s",nonstriker);
    printf("Enter Bowler:\n");
    scanf("%s",bowler);
    for (int i = 1; i <=overs; i++)
    {
        printf("For %dth over",i);
        for (int j = 1; j <=6; j++)
        {
            printf("\nEnter the runs scored in %dth ball: ",j);
            scanf("%d",&run);
            if (run>6)
            {
                printf("Enter Valid Run\n");
                j--;
            }
            score+=run;
        }
        
    }
    printf("The score is %d",score);
}

void input()
{
    

    printf("Enter names of two teams\n");
    scanf("%s",team1);
    scanf("%s",team2);
    printf("Enter the number of overs:-\n");
    scanf("%d",&overs);
    printf("Who won the toss??\n");
    scanf("%s",t_won);
    printf("What did %s chose to do first?(batting/fielding)\n",t_won);
    scanf("%s",t_choose);
    member_input();
}


int main()
{
   ba bt[11];
   bow bo[11];
   input();
   printf("For first innings\n");
   match_input();
   printf("For second innings\n");
   match_input();
   return 0;
}    
