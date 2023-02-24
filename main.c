#include<stdio.h>
#include<stdlib.h>

char team1,team2,t_won,t_choose;
void member_input()
{
    printf("%s %s",team1,team2);
}
void input()
{
    // char team1,team2,t_won,t_choose;
    int overs;
    printf("Enter names of two teams\n");
    scanf("%s",team1);
    scanf("%s",team2);
    printf("Enter the number of overs:-");
    scanf("%d",overs);
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
