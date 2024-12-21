#include <stdio.h>

// Best Fit memory allocation
void bestfit(int mp[], int p[], int m, int n) {
    int allocated[n];
    for (int i = 0; i < n; i++) {
        allocated[i] = -1; // Initialize allocation array
    }

    for (int i = 0; i < m; i++) {
        int best_idx = -1;
        for (int j = 0; j < n; j++) {
            if (mp[j] >= p[i]) {
                if (best_idx == -1 || mp[j] < mp[best_idx]) {
                    best_idx = j;
                }
            }
        }

        if (best_idx != -1) {
            allocated[i] = best_idx;
            mp[best_idx] -= p[i];
        }
    }

    // Output allocation details
    printf("\nProcess Allocation for Best Fit:\n");
    for (int i = 0; i < m; i++) {
        if (allocated[i] != -1) {
            printf("Process %d -> Partition %d\n", i + 1, allocated[i] + 1);
        } else {
            printf("Process %d -> Not allocated\n", i + 1);
        }
    }
}

// Sort in ascending order
void sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}

// Sort in descending order
void rsort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] < a[j + 1]) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}

// First Fit memory allocation
void firstfit(int mp[], int p[], int m, int n) {
    for (int i = 0; i < m; i++) {
        int allocated = 0;
        for (int j = 0; j < n; j++) {
            if (mp[j] >= p[i]) {
                printf("Process %d -> Partition %d\n", i + 1, j + 1);
                mp[j] -= p[i];
                allocated = 1;
                break;
            }
        }
        if (!allocated) {
            printf("Process %d -> Not allocated\n", i + 1);
        }
    }
}

// Worst Fit memory allocation
void worstfit(int mp[], int p[], int m, int n) {
    for (int i = 0; i < m; i++) {
        int worst_idx = -1;
        for (int j = 0; j < n; j++) {
            if (mp[j] >= p[i]) {
                if (worst_idx == -1 || mp[j] > mp[worst_idx]) {
                    worst_idx = j;
                }
            }
        }

        if (worst_idx != -1) {
            printf("Process %d -> Partition %d\n", i + 1, worst_idx + 1);
            mp[worst_idx] -= p[i];
        } else {
            printf("Process %d -> Not allocated\n", i + 1);
        }
    }
}

int main() {
    int m, n, mp[20], p[20], ch;

    // Input number of memory partitions and processes
    printf("Number of memory partitions: ");
    scanf("%d", &n);
    printf("Number of processes: ");
    scanf("%d", &m);

    // Input memory partitions
    printf("Enter the memory partitions:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &mp[i]);
    }

    // Input process sizes
    printf("Enter process sizes:\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &p[i]);
    }

    // Menu for memory allocation strategies
    printf("1. First Fit\n2. Best Fit\n3. Worst Fit\nEnter your choice: ");
    scanf("%d", &ch);

    switch (ch) {
        case 1:
            firstfit(mp, p, m, n);
            break;
        case 2:
            bestfit(mp, p, m, n);
            break;
        case 3:
            worstfit(mp, p, m, n);
            break;
        default:
            printf("Invalid choice\n");
    }

    return 0;
}

