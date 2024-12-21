#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid; // Process ID

    // Create a new process
    pid = fork();

    if (pid < 0) {
        // Error occurred
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("Child Process:\n");
        printf("Process ID: %d\n", getpid());
        printf("Parent Process ID: %d\n", getppid());
    } else {
        // Parent process
        printf("Parent Process:\n");
        printf("Process ID: %d\n", getpid());
        printf("Parent Process ID: %d\n", getppid());
    }

    return 0;
}

