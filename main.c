#include<stdio.h>
#include<string.h>
#include<stdlib.h>


char team1[50],team2[50],t_won[50],t_choose[50],t_lose[50];
int overs,run,nb,score,wickets=0,balls;
int a=0,b=0;
char t1[50],t2[50];
FILE *ptr;

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




void filehandling(int v)
{
fprintf(ptr,"\n");
    fprintf(ptr,"*********************%d Innings Score Card*********************\n",v);
    
    fprintf(ptr,"\n");
    fprintf(ptr,"\t\t\t\t\t\t\t\tBATTING SCORECARD\n");
    fprintf(ptr,"-------------------------------------------------------------------------------------------\n");
    fprintf(ptr,"%-20s %-10s %-20s %-10s %-10s %-10s\n","Name","Runs","Balls_faced","6's","4's","Strike_rate");
    fprintf(ptr,"-------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < 11; i++)
    {
        fprintf(ptr,"%-20s %-10d %-20d %-10d %-10d %-10f\n",bat[i].name,bat[i].runs,bat[i].balls_faced,bat[i].sixes,bat[i].fours,bat[i].strikerate);
        fprintf(ptr,"-------------------------------------------------------------------------------------------------\n");
    }
    fprintf(ptr,"\n");
    fprintf(ptr,"\t\t\t\t\t\t\t\tBOWLING SCORECARD\n");
     fprintf(ptr,"-------------------------------------------------------------------------------------------\n");
    fprintf(ptr,"%-20s %-20s %-10s %-20s %-10s\n","Name","Runs_given","Overs","Wickets_taken","Economy");
     fprintf(ptr,"-------------------------------------------------------------------------------------------\n");
    for (int j= 0; j< nb; j++)
    {
        fprintf(ptr,"%-20s %-20d %-10d %-20d %-10f\n",bo[j].name,bo[j].runs_given,bo[j].overs,bo[j].wickets_taken,bo[j].economy);
        fprintf(ptr,"-------------------------------------------------------------------------------------------------\n");
        
    }
    fprintf(ptr,"Total Score: %d/%d\n",score,wickets);
}





void print()
{   
    printf("\n");
    printf("**************************Match Summary**************************\n");
    printf("\t %s vs %s\n",team1,team2);
    // fprintf(fp,"\t %s vs %s\n",team1,team2);
    printf("Toss won by: %s\t",t_won);
    printf("Elected to: %s\n",t_choose);
    printf("\n");
    printf("\t\t\tBATTING SCORECARD\n");
    printf("-------------------------------------------------------------------------------------------\n");
    printf("%-20s %-10s %-20s %-10s %-10s %-10s\n","Name","Runs","Balls_faced","6's","4's","Strike_rate");
    printf("-------------------------------------------------------------------------------------------\n");
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
   
    printf("Total Score: %d/%d\n",score,wickets);
}




void match_input(){
    score=0;
    wickets=0;
    int st=0, nst=1;
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
    printf("Enter the number of bowlers in the opponent's team\n");
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
        printf("\n******For %dth over******\n",i);
        for (int j = 0; j <6; j++)
        {
            
            
            printf("Enter the runs scored in: %d\n",j+1);
            scanf("%d",&run);
            if (run>6)
            {
                printf("Enter valid runs(0-6)\n");
                --j;
                continue;
            }
            ++balls;
            ++bat[st].balls_faced;
            if (run!=-1)
            {
                 bat[st].runs=bat[st].runs+run;
            bo[c_bo].runs_given=bo[c_bo].runs_given+run;
            if (run==6)
                ++bat[st].sixes;
            if(run==4)
                ++bat[st].fours;
            bat[st].strikerate=(((bat[st].runs)/(bat[st].balls_faced*1.0))*(100));
            
            score+=run;
            if ((b!=a)&&(score>a))
            {
                break;
            }
            
            if(run%2!=0){
                swap(&st,&nst);
            }
            }
            else
            {  bat[st].strikerate=(((bat[st].runs)/(bat[st].balls_faced*1.0))*(100));
                 ++wickets;
                printf("%s is out!\n",bat[st].name);
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
           if(wickets==10)
           {
            printf("***********MATCH ENDED***********\n");
            break;
           }
            
        }
        overs=balls/6 + (balls%6)*0.1;
    bo[c_bo].overs=bo[c_bo].overs+overs;
        bo[c_bo].economy=(bo[c_bo].runs_given*1.0/balls)*6;
        ++c_bo;
    if (nb<overs)
    {
        if ((overs-c_bo)==1)
    {
        c_bo=0;
    }
    }
    
    swap(&st,&nst);
    balls=0;
    }
    printf("***********MATCH ENDED***********\n");
    
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
    printf("What did %s chose to do first?(batting/fielding)\n",t_won);
    scanf("%s",t_choose);
    
    
   if (strcmp(t_won, team1) == 0 || strcmp(t_won, team2) == 0)
    {
        // determine which team lost the toss
        if (strcmp(t_won,team1) == 0)
        {
            strcpy(t_lose,team2);
        }
        else
        {
            strcpy(t_lose,team1);
        }
        
        // determine which team chose to bat or field
        if (strcmp(t_choose,"batting") == 0)
        {
            strcpy(t1,t_won);
            strcpy(t2,t_lose);
        }
        else if (strcmp(t_choose,"fielding") == 0)
        {
            strcpy(t2,t_won);
            strcpy(t1,t_lose);
        }
    }
}




int main()
{
   input();
   char team[50];
   strcpy(team,team1);
   strcat(team,team2);
   ptr=fopen(team,"a"); 
   fprintf(ptr,"\t\t\t\t\t\t\t %s vs %s\n",team1,team2);
    fprintf(ptr,"Toss won by: %s\t\t\t",t_won);
    fprintf(ptr,"Elected to: %s\n",t_choose);
   for(int v=1;v<=2;v++)
   {
   printf("**************%d Innings**************\n",v);
   match_input();
    
    if(v==1)
    {
    
    printf("TARGET: %d runs in %d balls\n",score+1,overs*6);
    a=score;
    filehandling(v);
    fprintf(ptr,"TARGET: %d runs in %d balls\n",score+1,overs*6);
    // fclose(ptr);
    }
    if (v==2)
    {
        b=score;
        filehandling(v);
       if(a>b)
       {
        printf("%s won",t1);
        fprintf(ptr,"%s won",t1);
       }
       else if(a<b)
       {
        printf("%s won",t2);
        fprintf(ptr,"%s won",t2);
       }
        
    }
    
     
   }
   fclose(ptr);
   return 0;
}

  
