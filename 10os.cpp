#include <stdio.h>
#include <pthread.h>

// Function executed by each thread
void* threadFunction(void* arg) {
    char* message = (char*)arg;
    printf("%s\n", message);
    return NULL;
}

int main() {
    pthread_t thread1, thread2; // Thread identifiers
    char* message1 = "Hello from Thread 1!";
    char* message2 = "Hello from Thread 2!";

    // Create threads
    if (pthread_create(&thread1, NULL, threadFunction, (void*)message1) != 0) {
        perror("Error creating thread 1");
        return 1;
    }

    if (pthread_create(&thread2, NULL, threadFunction, (void*)message2) != 0) {
        perror("Error creating thread 2");
        return 1;
    }

    // Wait for threads to complete
    if (pthread_join(thread1, NULL) != 0) {
        perror("Error joining thread 1");
        return 1;
    }

    if (pthread_join(thread2, NULL) != 0) {
        perror("Error joining thread 2");
        return 1;
    }

    return 0;
}


