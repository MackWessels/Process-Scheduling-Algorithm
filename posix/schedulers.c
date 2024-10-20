#include <stdlib.h> 
#include <string.h> 
#include <stdio.h>
#include "list.h"
#include "task.h"

struct node *task_list = NULL;  // Global task list

int global_tid = 0;  // Global task ID counter

// Function to add a task to the task list
void add(char *name, int priority, int burst) {
    Task *new_task = malloc(sizeof(Task));  // Allocate memory for a new task
    new_task->name = strdup(name);  // Duplicate the task name
    new_task->priority = priority;
    new_task->burst = burst;
    new_task->initial_burst = burst;  // Save the initial burst time

    // Assign a unique task ID
    new_task->tid = __sync_fetch_and_add(&global_tid, 1); 

    // Initialize task statistics
    new_task->turnaround_time = 0;
    new_task->waiting_time = 0;
    new_task->response_time = -1;

    // Insert the new task into the task list
    insert(&task_list, new_task);
}

// Function to calculate and print the average turnaround, waiting, and response times
void calculate_averages(struct node *task_list_copy, int num_tasks) {
    int total_turnaround = 0;
    int total_waiting = 0;
    int total_response = 0;

    // Traverse the task list and sum up the statistics
    struct node *temp = task_list_copy;
    while (temp != NULL) {
        total_turnaround += temp->task->turnaround_time;
        total_waiting += temp->task->waiting_time;
        total_response += temp->task->response_time;
        temp = temp->next;
    }

    // Print the average statistics
    printf("Average Turnaround Time: %f\n", (float)total_turnaround / num_tasks);
    printf("Average Waiting Time: %f\n", (float)total_waiting / num_tasks);
    printf("Average Response Time: %f\n", (float)total_response / num_tasks);
}
