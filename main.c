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
  int sixes;
  int fours;
} ba;

typedef struct bowler{
  char name[50];
  int overs;
  int runs_given;
  int wickets_taken;
  float economy;
} bow;

ba bt[11];
bow bo[11];
ba bat[11];
bow bo[11];

int swap(int st, int nst)
{
    int temp;
    temp=st;
    st=nst;
    nst=temp;
    return(st,nst);
}

// void member_input()
// {
//     FILE *fp, *fp1;
//     fp=fopen(team1,"w");
//       if (fp == NULL)
//     {
//         printf("Error opening file!\n");
//         //return 1;
//     }

//     printf("For %s\n",team1);   
//     for (int i = 1; i <= 11; i++) 
//     {
//         printf("enter player %d: ",i,team1);
//         scanf("%s",player);
//         fprintf(fp, "%s\n", player);
//     }
    
    
//     fclose(fp);
//     fp1=fopen(team2,"w");
//       if (fp1 == NULL)
//     {
//         printf("Error opening file!\n");
//         //return 1;
//     }
    
//     printf("For %s\n",team2);  
//     for (int j= 1; j <= 11; j++) 
//     {
//         printf("enter player %d: ",j,team2);
//         scanf("%s",player);
//         fprintf(fp1, "%s\n", player);
//     }
    
    
//     fclose(fp1);
// }
void print()
{
    printf("Name\truns\tballs faced\t6's\t4's\tstrike rate\n");
    for (int i = 0; i < 11; i++)
    {
        printf("%s\t%d\t%d\t%d\t%d\t%.2f\n",bat[i].name,bat[i].runs,bat[i].balls_faced,bat[i].sixes,bat[i].fours,bat[i].strikerate);
    }
    
    printf("%s\t");
}
void match_input(){
    
    int c,d,wicket;
    float runrate;
    int run,score=0;
    int balls=0;
    int sixes=0;
    int fours=0;
    // char bool;
    int st=0, nst=1;
    // bow bo;
   
    for (int i = 0; i < 11; i++)
    {
        printf("Enter Players' details in batting order\n");
        printf("Name:");
        scanf("%s",bat[i].name);
        bat[i].balls_faced=0;
        bat[i].fours=0;
        bat[i].sixes=0;
        bat[i].runs=0;
        bat[i].strikerate=0.00;
        
    }
    printf("Enter the number of bowlers in the team ");
    int n_b;
    scanf("%d",n_b);
    for (int j = 0; j <n_b; j++)
    {
        printf("Enter bowlers' details in opponent's team in bowling order\n");
        printf("Name:");
        scanf("%s",bo[j].name);
        bo[j].runs_given=0;
        bo[j].wickets_taken=0;
        bo[j].economy=0;
    }
    int c_bo=0;
    
    for (int i = 1; i <=3; i++)
    {
        printf("For %dth over\n",i);
        for (int j = 0; j <6; j++)
        {
           
             
            ++bat[st].balls_faced;
            printf("\nEnter the runs scored in %d:",j+1);
            scanf("%d",&run);
            bat[st].runs=run;
            bo[c_bo].runs_given=run;
            if (run==6)
                ++bat[st].sixes;
            if(run==4)
                ++bat[st].fours;
            bat[st].strikerate=((bat[st].runs/bat[st].balls_faced)*100);
            
            score+=run;
            if(run%2!=0){
                 swap(st,nst);
            }
            
        }
    bo[c_bo].overs=i;
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
    // member_input();
}


int main()
{
   
   input();
   printf("For first innings\n");
   match_input();
//    printf("For second innings\n");
//    match_input();
   return 0;
} 
