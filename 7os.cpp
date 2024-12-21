#include <stdio.h>

int main() {
    int at[10], bt[10], pr[10];  
    int n, i, j, temp, time = 0, count, over = 0;
    int sum_wait = 0, sum_turnaround = 0, start;
    float avgwait, avgturn;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
 
    for (i = 0; i < n; i++) {
        printf("Enter the arrival time and execution time for process %d: ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);
        pr[i] = i + 1;  
    }
 
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {
              
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                 
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;
            }
        }
    }

    printf("\n\nProcess\t| Arrival Time\t| Start Time\t| End Time\t| Waiting Time\t| Turnaround Time\n\n");
 
    while (over < n) {
        count = 0;
 
        for (i = over; i < n; i++) {
            if (at[i] <= time) {
                count++;
            } else {
                break;
            }
        }
 
        if (count > 1) {
            for (i = over; i < over + count - 1; i++) {
                for (j = i + 1; j < over + count; j++) {
                    if (bt[i] > bt[j]) {
                         
                        temp = at[i];
                        at[i] = at[j];
                        at[j] = temp;
 
                        temp = bt[i];
                        bt[i] = bt[j];
                        bt[j] = temp;
 
                        temp = pr[i];
                        pr[i] = pr[j];
                        pr[j] = temp;
                    }
                }
            }
        }

        start = time;              
        time += bt[over];          
        int end_time = time;       

        printf("P[%d]\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t\t|\t%d\n", pr[over], at[over], start, end_time, end_time - at[over] - bt[over], end_time - at[over]);
 
        sum_wait += end_time - at[over] - bt[over];
        sum_turnaround += end_time - at[over];
        over++;  
    }

     
    avgwait = (float)sum_wait / n;
    avgturn = (float)sum_turnaround / n;

    printf("\nAverage waiting time: %f", avgwait);
    printf("\nAverage turnaround time: %f\n", avgturn);

    return 0;
}

