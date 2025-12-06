#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Queue implementation
#define SIZE 10

char* queue[SIZE];
int front = -1, rear = -1;

// Enqueue function
void enqueue(char* car) {
    if (rear == SIZE - 1) {
        printf("Queue Overflow! Cannot add %s\n", car);
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = strdup(car);
    printf("%s arrived at the signal.\n", car);
}

// Dequeue function
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! No cars to move.\n");
        return;
    }
    printf("%s passed the intersection.\n", queue[front]);
    free(queue[front]);
    front++;
}

// Display queue
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Cars waiting: ");
    for (int i = front; i <= rear; i++) {
        printf("%s ", queue[i]);
    }
    printf("\n");
}

// Traffic light simulation
void trafficLightSimulation(int cycles) {
    char* states[] = {"Red", "Green", "Yellow"};
    int car_id = 1;

    for (int i = 0; i < cycles; i++) {
        char* state = states[i % 3];
        printf("\nCycle %d: Light is %s\n", i + 1, state);

        // New car arrives each cycle
        char car[10];
        sprintf(car, "Car%d", car_id++);
        enqueue(car);

        display();

        if (strcmp(state, "Green") == 0) {
            dequeue();
            display();
        }
    }
}

int main() {
    int cycles;
    printf("Enter number of cycles to simulate: ");
    scanf("%d", &cycles);

    trafficLightSimulation(cycles);

    return 0;
}


