#include <stdio.h>
#include <conio.h>
#include <string.h>
//#include <stdlib.h>

char new_bowler_name[25], non_striker_bat[25], striker_bat[25],current_ball[5];
int total_run=0,ball_count,over_finished,over,total_ball,bat_one_run=0,bat_two_run=0,current_bats=1,bat_one_ball=0,bat_two_ball=0;
char num[256];
float a=0,b=0,run_rate,x,new_ball_count;
int run_count_after=0,run_count_before=0,over_run=0,c=0,over_complete=0;

void final_exit()
{
    system("cls");
    printf("\n     Total Run: %d\n",total_run);
    printf("\n   Total Overs: %d\n",total_ball/6);
    printf("\n     Run Rate: %f\n",run_rate*6);
    printf("\n#####  END OF INNINGS #####\n");
}


void cpu()
{

    printf("\n      Input If run : 0/1/2/3/4/6\n ");
    printf("\  Or Input No_Ball : n/n1/n2/n3/n4/n6\n ");
    printf("\ Or Input Wide_Ball : wd/wd1/wd2/wd3/wd4\n ");
    printf("\         Or Input Wicket : w\n ");



    scanf("     %s",&current_ball);
    //checking for wide or no ball
    if((strcmp(current_ball,"n1")==0)|| (strcmp(current_ball,"n2")==0)|| (strcmp(current_ball,"n3")==0)|| (strcmp(current_ball,"n4")==0)||(strcmp(current_ball,"n6")==0)||(strcmp(current_ball,"wd")==0)||(strcmp(current_ball,"wd1")==0)||(strcmp(current_ball,"wd2")==0)||(strcmp(current_ball,"wd3")==0)||(strcmp(current_ball,"wd4")==0))
        ball_count--;
    //checking for runs
    if((strcmp(current_ball,"0")==0) ||(strcmp(current_ball,"1")==0)|| (strcmp(current_ball,"2")==0) || (strcmp(current_ball,"3")==0)|| (strcmp(current_ball,"4")==0)|| (strcmp(current_ball,"6")==0)|| (strcmp(current_ball,"n1")==0)|| (strcmp(current_ball,"n2")==0)|| (strcmp(current_ball,"n3")==0)|| (strcmp(current_ball,"n4")==0)||(strcmp(current_ball,"n6")==0)||(strcmp(current_ball,"wd")==0)||(strcmp(current_ball,"wd1")==0)||(strcmp(current_ball,"wd2")==0)||(strcmp(current_ball,"wd3")==0)||(strcmp(current_ball,"wd4")==0))

        batsman_cal();
    //if it is out
    else if((strcmp(current_ball,"w")==0))
    {

        if(current_bats==1)
        {
            printf("     New Batsman's Name: ");
            scanf("%s",&striker_bat);
            bat_one_ball=0;
            bat_one_run=0;
        }
        else
        {
            printf("     New Batsman's Name: ");
            scanf("%s",&non_striker_bat);
            bat_two_ball=0;
            bat_two_run=0;
        }
    }


}
void batsman_cal()
{


    if(current_bats == 1)
    {
        if((strcmp(current_ball,"0")==0) || (strcmp(current_ball,"1")==0) || (strcmp(current_ball,"3")==0) || (strcmp(current_ball,"2")==0) || (strcmp(current_ball,"4")==0) || (strcmp(current_ball,"6")==0))
        {
            bat_one_run = bat_one_run + int_convert(current_ball);
            bat_one_ball++;
            total_run=total_run+int_convert(current_ball);

        }

        else if (strcmp(current_ball,"n2")==0) bat_one_run=bat_one_run+2;
        else if (strcmp(current_ball,"n4")==0) bat_one_run=bat_one_run+4;
        else if (strcmp(current_ball,"n6")==0) bat_one_run=bat_one_run+6;
        else if (strcmp(current_ball,"n1")==0) bat_one_run=bat_one_run+1;
        else if (strcmp(current_ball,"n3")==0) bat_one_run=bat_one_run+3;


    }

    if(current_bats == 2)
    {
        if((strcmp(current_ball,"0")==0) ||(strcmp(current_ball,"1")==0) || (strcmp(current_ball,"3")==0) || (strcmp(current_ball,"2")==0) || (strcmp(current_ball,"4")==0) || (strcmp(current_ball,"6")==0))
        {
            bat_two_run = bat_two_run + int_convert(current_ball);
            bat_two_ball++;
            total_run=total_run+int_convert(current_ball);

        }


        else if (strcmp(current_ball,"n1")==0) bat_two_run=bat_two_run+1;
        else if (strcmp(current_ball,"n3")==0) bat_two_run=bat_two_run+3;
        else if (strcmp(current_ball,"n2")==0) bat_two_run=bat_two_run+2;
        else if (strcmp(current_ball,"n4")==0) bat_two_run=bat_two_run+4;
        else if (strcmp(current_ball,"n6")==0) bat_two_run=bat_two_run+6;

    }


    if(((strcmp(current_ball,"1")==0) || (strcmp(current_ball,"3")==0) || (strcmp(current_ball,"n1")==0)|| (strcmp(current_ball,"n3")==0) || (strcmp(current_ball,"wd1")==0) || (strcmp(current_ball,"wd3")==0)))
    {
        if(current_bats == 2) current_bats = 1;
        else current_bats = 2;
    }

    if((strcmp(current_ball,"n")==0)) total_run=total_run+1;
    if((strcmp(current_ball,"n1")==0)) total_run=total_run+2;
    if((strcmp(current_ball,"n2")==0)) total_run=total_run+3;
    if((strcmp(current_ball,"n3")==0)) total_run=total_run+4;
    if((strcmp(current_ball,"n4")==0)) total_run=total_run+5;
    if((strcmp(current_ball,"n6")==0)) total_run=total_run+7;
    if((strcmp(current_ball,"wd")==0)) total_run=total_run+1;
    if((strcmp(current_ball,"wd1")==0)) total_run=total_run+2;
    if((strcmp(current_ball,"wd2")==0)) total_run=total_run+3;
    if((strcmp(current_ball,"wd3")==0)) total_run=total_run+4;
    if((strcmp(current_ball,"wd4")==0)) total_run=total_run+5;
}


int int_convert(num)
{

    int i;
    i = atoi (num);
    return i;
}
void printing()
{
    a=(bat_one_run*100)/bat_one_ball;

    if(bat_two_ball != 0 && bat_two_run != 0)
        b=(bat_two_run*100)/bat_two_ball;
    run_rate=(run_count_after/new_ball_count);
    c=run_count_after-run_count_before;
    over_run=over_run+c;
    system("cls");
    //printf("\n\n%s\t\t%d %d %d %d %d \n\n",striker_bat,bat_one_run,bat_two_run,bat_one_ball,bat_two_ball,total_run);
    printf("               #####  SCORE BOARD  #####");
    printf("\n\n       Batsman name\t \tRun(ball)\tS.R.(%%)\n\n");
    printf("           %s \t\t%d(%d)\t \t%f",striker_bat,bat_one_run,bat_one_ball,a);
    printf("\n           %s \t\t%d(%d)\t  \t%f",non_striker_bat,bat_two_run,bat_two_ball,b);
    printf("\n\n\n\n     Bowler name: %s\t\t\tRun This Over: %d\n",new_bowler_name,over_run);
    printf("\n              Innings Run Rate : %f\n",run_rate*6);
    printf("\n                    Over Running: %d\n",over_complete+1);
    printf("\n                       Total Run: %d\n\n\n",total_run);


}
void main()
{
    system("COLOR FC");
    printf("      #####        Welcome          #####                            \n");
    printf("      #####         To My           #####                            \n");
    printf("      #####   Cricket Score-Board   #####                            \n\n");
    int over;

    printf("              Input total over:--");
    scanf("%d",&over);

    total_ball=6*over;
    over_finished=0;

    printf("\n        Input Striker batsman name:--");
    scanf("%s",&striker_bat);

    printf("\n      Input non Striker batsman name:--");
    scanf("%s",&non_striker_bat);

    printf("\n       Input New Bowler's name:----");
    scanf("%s",&new_bowler_name);

    for(ball_count=1; ball_count<=total_ball+1; ball_count++)
    {
        new_ball_count = ball_count;
        run_count_before=total_run;
        if(ball_count==(total_ball+1))
        {
            final_exit();
        }
        if(ball_count<=(total_ball))
        {



            if((ball_count == 7 || ball_count == 13 || ball_count == 19 || ball_count == 25 || ball_count == 31 || ball_count == 37 || ball_count == 43 || ball_count == 49 || ball_count == 55 ) && ball_count!=total_ball)
            {
                over_complete++;
                printf("Input new bowler's name: ");
                scanf("%s",new_bowler_name);
                over_run = 0;
                cpu();
                run_count_after=total_run;
                x=total_run;
                printing();
            }



            else
            {
                cpu();
                run_count_after=total_run;
                x=total_run;
                printing();
            }
        }
    }


}
