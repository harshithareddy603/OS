#include <stdio.h>

int main() {
    int i, NOP, sum = 0, count = 0, y, quant, wt = 0, tat = 0;
    int at[10], bt[10], temp[10];
    float avg_wt, avg_tat;

    printf("Total number of processes in the system: ");
    scanf("%d", &NOP);

    y = NOP; // Copy of the number of processes for loop termination

    // Input arrival time and burst time for each process
    for (i = 0; i < NOP; i++) {
        printf("\nEnter the Arrival and Burst time of Process[%d]\n", i + 1);
        printf("Arrival time: ");
        scanf("%d", &at[i]);
        printf("Burst time: ");
        scanf("%d", &bt[i]);
        temp[i] = bt[i]; // Copy burst time to temp array
    }

    printf("Enter the Time Quantum for the process: ");
    scanf("%d", &quant);

    printf("\nProcess No\tBurst Time\tTurnaround Time\tWaiting Time\n");

    // Loop until all processes are completed
    for (sum = 0, i = 0; y != 0;) {
        if (temp[i] <= quant && temp[i] > 0) {
            sum += temp[i]; // Add remaining burst time to total time
            temp[i] = 0;    // Process is completed
            count = 1;
        } else if (temp[i] > 0) {
            temp[i] -= quant; // Deduct quantum time from remaining burst time
            sum += quant;     // Add quantum time to total time
        }

        if (temp[i] == 0 && count == 1) {
            y--; // One process is completed
            printf("Process[%d]\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], sum - at[i], sum - at[i] - bt[i]);
            wt += sum - at[i] - bt[i]; // Waiting time
            tat += sum - at[i];        // Turnaround time
            count = 0;
        }

        if (i == NOP - 1) {
            i = 0; // Start over from the first process
        } else if (at[i + 1] <= sum) {
            i++; // Move to the next process
        } else {
            i = 0; // Reset to the first process if no other process has arrived
        }
    }

    // Calculate average waiting time and turnaround time
    avg_wt = (float)wt / NOP;
    avg_tat = (float)tat / NOP;

    printf("\nAverage Turnaround Time: %f", avg_tat);
    printf("\nAverage Waiting Time: %f\n", avg_wt);

    return 0;
}

