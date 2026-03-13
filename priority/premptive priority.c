#include <stdio.h>

int main() {
    int n;
    printf("USN 1BM24CS004 \n");

    printf("Enter number of processes: ");
    scanf("%d",&n);

    int  at[n], bt[n], pr[n];
    int rt[n], ct[n], tat[n], wt[n];

    for(int i=0;i<n;i++){

        printf("Arrival Time: ");
        scanf("%d",&at[i]);

        printf("Burst Time: ");
        scanf("%d",&bt[i]);

        printf("Priority: ");
        scanf("%d",&pr[i]);

        rt[i] = bt[i];
    }

    int current_time = 0;
    int completed = 0;

    while(completed < n){

        int highest_priority = 9999;
        int selected_process = -1;

        for(int i=0;i<n;i++){
            if(at[i] <= current_time && rt[i] > 0){
                if(pr[i] < highest_priority){
                    highest_priority = pr[i];
                    selected_process = i;
                }
            }
        }

        if(selected_process == -1){
            current_time++;
        }
        else{
            rt[selected_process]--;
            current_time++;

            if(rt[selected_process] == 0){

                ct[selected_process] = current_time;

                tat[selected_process] =
                    ct[selected_process] - at[selected_process];

                wt[selected_process] =
                    tat[selected_process] - bt[selected_process];

                completed++;
            }
        }
    }

        float total_tat=0,total_wt=0;



    printf("Process  At Bt Pr Ct Tat Wt \n");
    for(int i=0;i<n;i++)
    {
        printf("%d       %d  %d  %d %d %d  %d \n",i+1,at[i],bt[i],pr[i],ct[i],tat[i],wt[i]);
        total_tat+=tat[i];
        total_wt+=wt[i];
    }
        printf(" Average tat= %.2f  Average Wt=%.2f",total_tat/n,total_wt/n);
        return 0;

    return 0;
}
