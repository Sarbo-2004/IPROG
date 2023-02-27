#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char team1[50],team2[50],t_won[50],t_choose[50],player[50];
int overs,run,score=0;
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
    for (int i = 1; i <=overs; i++)
    {
        printf("For %dth over",i);
        for (int j = 1; j <=6; j++)
        {
            printf("\nEnter the runs scored in %dth ball: ",j);
            scanf("%d",&run);
            score+=run;
        }
        
    }
    
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
   input();
   match_input();
}    
