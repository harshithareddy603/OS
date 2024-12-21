#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5

// Mutex for chopsticks
pthread_mutex_t chopsticks[NUM_PHILOSOPHERS];

// Philosopher lifecycle function
void* philosopherLifeCycle(void* arg) {
    int id = *((int*)arg);
    int left_chopstick = id;
    int right_chopstick = (id + 1) % NUM_PHILOSOPHERS;

    while (1) {
        // Think
        printf("Philosopher %d is thinking...\n", id);
        sleep(rand() % 3 + 1); // Thinking time

        // Pick up chopsticks
        printf("Philosopher %d is hungry and tries to pick up chopsticks...\n", id);

        pthread_mutex_lock(&chopsticks[left_chopstick]);
        pthread_mutex_lock(&chopsticks[right_chopstick]);

        // Eat
        printf("Philosopher %d is eating...\n", id);
        sleep(rand() % 3 + 1); // Eating time

        // Put down chopsticks
        pthread_mutex_unlock(&chopsticks[left_chopstick]);
        pthread_mutex_unlock(&chopsticks[right_chopstick]);

        // Repeat the cycle
    }
    return NULL;
}

int main() {
    pthread_t philosophers[NUM_PHILOSOPHERS];
    int philosopher_ids[NUM_PHILOSOPHERS];

    // Initialize mutex locks
    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        pthread_mutex_init(&chopsticks[i], NULL);
    }

    // Create philosopher threads
    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        philosopher_ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopherLifeCycle, (void*)&philosopher_ids[i]);
    }

    // Wait for threads to finish (runs indefinitely in this case)
    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        pthread_join(philosophers[i], NULL);
    }

    // Destroy mutex locks (not reachable in this example)
    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        pthread_mutex_destroy(&chopsticks[i]);
    }

    return 0;
}

