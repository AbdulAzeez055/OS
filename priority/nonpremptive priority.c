#include<stdio.h>
int main()
{
    int n;
    printf("Enter number of processors \n");
    scanf("%d",&n);
    printf("Enter arrival time and burst time of the processors \n");
    int at[n],bt[n],pr[n];
    int ct[n],tat[n],wt[n];
    int completed[10]={0};
    for(int i=0;i<n;i++)
    {
        printf("Process [%d] \n",i+1);
        printf("Enter AT ");
        scanf("%d",&at[i]);
        printf("Enter Bt");
        scanf("%d",&bt[i]);
        printf("Enter priority ");
        scanf("%d",&pr[i]);
    }
    int curr_time=0;
    int comp=0;
    while(comp<n)
    {
        int idx=-1;
        int high=9999;
        for(int i=0;i<n;i++)
        {
            if(at[i]<=curr_time && completed[i]==0)
            {
                if(pr[i]<high)
                {
                    high=pr[i];
                    idx=i;
                }

            }
        }
        if(idx==-1)
        {
            curr_time++;
        }
        else
        {
            int start=curr_time;
            ct[idx]=start+bt[idx];
            tat[idx]=ct[idx]-at[idx];
            wt[idx]=tat[idx]-bt[idx];
            curr_time=ct[idx];
            completed[idx]=1;
            comp++;

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




}
