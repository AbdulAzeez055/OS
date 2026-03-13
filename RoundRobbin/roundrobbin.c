#include<stdio.h>

int main() {
    int n, tq;
    printf("USN 1BM24CS004 \n");
    printf("Enter number of processes \n");
    scanf("%d", &n);
    printf("Enter time quantum \n");
    scanf("%d", &tq);

    int at[n], bt[n], rt[n];
    int ct[n], tat[n], wt[n];
    int q[100], front = 0, rear = 0;
    int visited[n];

    for (int i = 0; i < n; i++) {
        printf("Process [%d] \n", i + 1);
        printf("Enter AT: ");
        scanf("%d", &at[i]);
        printf("Enter BT: ");
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
        wt[i] = tat[i] = 0;
        visited[i] = 0;
    }

    int curr_time = 0;
    int comp = 0;

    while (comp < n) {
        for (int i = 0; i < n; i++) {
            if (at[i] <= curr_time && visited[i] == 0) {
                q[rear++] = i;
                visited[i] = 1;
            }
        }

        if (front == rear) {
            curr_time++;
            continue;
        }

        int p = q[front++];
        if (rt[p] > tq) {
            curr_time += tq;
            rt[p] -= tq;

            for (int i = 0; i < n; i++) {
                if (at[i] <= curr_time && visited[i] == 0) {
                    q[rear++] = i;
                    visited[i] = 1;
                }
            }
            q[rear++] = p;
        } else {
            curr_time += rt[p];
            rt[p] = 0;
            tat[p] = curr_time - at[p];
            ct[p] = curr_time;
            wt[p] = tat[p] - bt[p];
            comp++;
        }
    }

    float total_tat = 0, total_wt = 0;

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
        total_tat += tat[i];
        total_wt += wt[i];
    }

    printf("\nAverage TAT = %.2f\n", total_tat / n);
    printf("Average WT = %.2f\n", total_wt / n);

    return 0;
}
