#include<stdio.h>
#include<stdlib.h>

char team1[50],team2[50],t_won[50],t_choose[50],player[50];
void member_input()
{
    FILE *fp, *fp1;
    fp=fopen(team1,"w");
      if (fp == NULL)
    {
        printf("Error opening file!\n");
        //return 1;
    }
    
    for (int i = 1; i <= 11; i++) 
    {
        printf("enter player %d",i);
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
    
    for (int j= 1; j <= 11; j++) 
    {
        printf("enter player %d",j);
        scanf("%s",player);
        fprintf(fp1, "%s\n", player);
    }
    
    
    fclose(fp1);
}

void input()
{
    
    int overs;
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
}    
