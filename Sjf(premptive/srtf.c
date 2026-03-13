#include<stdio.h>
int main()
{
    int n;
    printf("Enter number of processors \n");
    scanf("%d",&n);
    printf("Enter arrival time and burst time of the processors \n");
    int at[n],bt[n],rt[n];
    int ct[n],tat[n],wt[n];
    int finished[10]={0};
    for(int i=0;i<n;i++)
    {
        printf("Process [%d] \n",i+1);
        printf("Enter AT ");
        scanf("%d",&at[i]);
        printf("Enter Bt");
        scanf("%d",&bt[i]);
        rt[i]=bt[i];

    }
    int curr_time=0;
    int comp=0;
    while(comp<n)
    {
        int idx=-1;
        int min=9999;
        for(int i=0;i<n;i++)
        {
            if(at[i]<=curr_time && finished[i]==0)
            {
                if(rt[i]<min && rt[i]>0)
                {
                    min=rt[i];
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
            rt[idx]--;
            curr_time++;
            if(rt[idx]==0)
            {
                ct[idx]=curr_time;
                tat[idx]=ct[idx]-at[idx];
                wt[idx]=tat[idx]-bt[idx];
                finished[idx]=1;
                comp++;
            }
        }
    }
    float total_tat=0,total_wt=0;
//    avg_tat=total_tat/n;
//    avg_wt=total_wt/n;


    printf("Process  At Bt Ct Tat Wt \n");
    for(int i=0;i<n;i++)
    {
        printf("%d       %d  %d  %d  %d  %d \n",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
        total_tat+=tat[i];
        total_wt+=wt[i];
    }
        printf(" Average tat= %.2f  Average Wt=%.2f",total_tat/n,total_wt/n);



}

