#include<stdio.h>
#include<string.h>
#include<stdlib.h>


char team1[50],team2[50],t_won[50],t_choose[50],player[50],striker[50],nonstriker[50],bowler[50],t_lose[50];
int overs=2,run,nb,score,wickets=0;

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


ba bat[11];
bow bo[11];

int swap(int *st, int *nst)
{
    int temp;
    temp=*st;
    *st=*nst;
    *nst=temp;
    
}

void print()
{   
    printf("\n");
    printf("**************************Match Summary**************************");
    printf("\t %s vs %s\n",team1,team2);
    printf("Toss won by: %s\t",t_won);
    printf("Elected to: %s\n",t_choose);
    printf("\n");
    printf("\t\t\tBATTING SCORECARD\n");
    printf("-------------------------------------------------------------------------------------------\n");
    printf("%-20s %-10s %-20s %-10s %-10s %-10s\n","Name","Runs","Balls_faced","6's","4's","Strike_rate");
    for (int i = 0; i < 11; i++)
    {
        printf("%-20s %-10d %-20d %-10d %-10d %-10f\n",bat[i].name,bat[i].runs,bat[i].balls_faced,bat[i].sixes,bat[i].fours,bat[i].strikerate);
        printf("-------------------------------------------------------------------------------------------------\n");
    }
    printf("\n");
    printf("\t\t\tBOWLING SCORECARD\n");
     printf("-------------------------------------------------------------------------------------------\n");
    printf("%-20s %-20s %-10s %-20s %-10s\n","Name","Runs_given","Overs","Wickets_taken","Economy");
    for (int j= 0; j< nb; j++)
    {
        printf("%-20s %-20d %-10d %-20d %-10f\n",bo[j].name,bo[j].runs_given,bo[j].overs,bo[j].wickets_taken,bo[j].economy);
        printf("-------------------------------------------------------------------------------------------------\n");
    }
    printf("Total Score: %d/%d",score,wickets);
    printf("%s has to chase %d runs in %d balls",t_lose,score+1,overs*6);
}
void match_input(){
    
    int c,d,wicket;
    float runrate;
    int run=0;
    int balls=0;
    int sixes=0;
    int fours=0;
    // char bool;
    int st=0, nst=1;
    // bow bo;
   printf("Enter Players' details in batting order\n");
    for (int i = 0; i < 11; i++)
    {
        
        printf("Player %d Name:-",i+1);
        scanf("%s",bat[i].name);
        bat[i].balls_faced=0;
        bat[i].fours=0;
        bat[i].sixes=0;
        bat[i].runs=0;
        bat[i].strikerate=0.00;
        
    }
    printf("Enter the number of bowlers in the team\n");
    int j=0;
    scanf("%d",&nb);
    printf("Enter bowlers' details in opponent's team in bowling order\n");
    for (j = 0; j<nb; j++)
    {
        
        printf("Bowler %d:-",j+1);
        scanf("%s",bo[j].name);
        bo[j].runs_given=0;
        bo[j].wickets_taken=0;
        bo[j].economy=0;
        bo[j].overs=0;
    }
    int c_bo=0;
    
    for (int i = 1; i <=overs; i++)
    {
        printf("For %dth over\n",i);
        for (int j = 0; j <6; j++)
        {
           
             
            ++bat[st].balls_faced;
            printf("\nEnter the runs scored in %d:",j+1);
            scanf("%d",&run);
            if (run!=-1)
            {
                 bat[st].runs=bat[st].runs+run;
            bo[c_bo].runs_given=bo[c_bo].runs_given+run;
            if (run==6)
                ++bat[st].sixes;
            if(run==4)
                ++bat[st].fours;
            bat[st].strikerate=((bat[st].runs/bat[st].balls_faced)*100);
            
            score+=run;
            if(run%2!=0){
                swap(&st,&nst);
            }
            }
            else
            {   ++wickets;
                printf("%s is out!",bat[st].name);
                ++bo[c_bo].wickets_taken;
                if (st>nst)
                {
                    st=st+1;
                }
                else
                {
                    st=nst+1;
                }
                
            }
           
            
        }
    ++bo[c_bo].overs;
    ++c_bo;
    swap(&st,&nst);
    }
    print();  
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
    if (strcmp(t_won,team1))
    {
        strcpy(t_lose,team2);
    }
    else
    {
        strcpy(t_lose,team1);
    }
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
