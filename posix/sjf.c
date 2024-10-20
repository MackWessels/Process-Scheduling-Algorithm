#include <stdio.h>
#include "list.h"
#include "task.h"
#include "cpu.h"
#include "schedulers.h"

void schedule() {
    int num_tasks = 0;
    int total_turnaround = 0;
    int total_waiting = 0;
    int total_response = 0;

    struct node *temp;

    // Loop until the task list is empty
    while (task_list != NULL) {
        struct node *shortest = task_list;
        temp = task_list;

        // Find the task with the shortest burst time
        while (temp != NULL) {
            if (temp->task->burst < shortest->task->burst) {
                shortest = temp;
            }
            temp = temp->next;
        }

        // Run the task with the shortest burst time
        run(shortest->task, shortest->task->burst);

        // Update statistics
        total_turnaround += shortest->task->turnaround_time;
        total_waiting += shortest->task->waiting_time;
        total_response += shortest->task->response_time;

        // Remove the completed task
        delete(&task_list, shortest->task);
        num_tasks++; 
    }

    // Display average statistics if tasks were processed
    if (num_tasks > 0) {
        printf("Average Turnaround Time: %f\n", (float)total_turnaround / num_tasks);
        printf("Average Waiting Time: %f\n", (float)total_waiting / num_tasks);
        printf("Average Response Time: %f\n", (float)total_response / num_tasks);
    }
}
