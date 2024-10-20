
#include <stdio.h>
#include "list.h"
#include "task.h"
#include "cpu.h"
#include "schedulers.h"

#define TIME_QUANTUM 10

void schedule() {
    int num_tasks = 0;
    int total_turnaround = 0;
    int total_waiting = 0;
    int total_response = 0;

    struct node *temp, *next_task;

    // Process tasks by priority first
    for (int current_priority = MIN_PRIORITY; current_priority <= MAX_PRIORITY; current_priority++) {

        int tasks_remaining = 1; // Flag to check if any tasks remain for this priority level

        while (tasks_remaining) {
            tasks_remaining = 0; // Reset flag

            temp = task_list;
            while (temp != NULL) {
                next_task = temp->next;

                if (temp->task->priority == current_priority) {
                    tasks_remaining = 1; // If we find a task with the current priority

                    if (temp->task->burst > TIME_QUANTUM) {
                        run(temp->task, TIME_QUANTUM);
                        temp->task->burst -= TIME_QUANTUM;
                    } else {
                        run(temp->task, temp->task->burst);

                        // Update stats
                        total_turnaround += temp->task->turnaround_time;
                        total_waiting += temp->task->waiting_time;
                        total_response += temp->task->response_time;

                        // Remove task once complete
                        delete(&task_list, temp->task);
                    }
                }
                temp = next_task;
            }
        }
    }

    // Calculate and print averages 
    if (num_tasks > 0) {
        printf("Average Turnaround Time: %f\n", (float)total_turnaround / num_tasks);
        printf("Average Waiting Time: %f\n", (float)total_waiting / num_tasks);
        printf("Average Response Time: %f\n", (float)total_response / num_tasks);
    }
}
