#include <stdio.h>
#include "list.h"
#include "task.h"
#include "cpu.h"
#include "schedulers.h"

#define TIME_QUANTUM 10  // Time quantum for Round-Robin

void schedule() {
    int num_tasks = 0;
    int total_turnaround = 0;
    int total_waiting = 0;
    int total_response = 0;

    struct node *temp, *next_task;

    // Loop until the task list is empty
    while (task_list != NULL) {
        temp = task_list;

        // loop through each task
        while (temp != NULL) {
            next_task = temp->next;

            // If task's burst exceeds the quantum, run for the quantum
            if (temp->task->burst > TIME_QUANTUM) {
                run(temp->task, TIME_QUANTUM);
                temp->task->burst -= TIME_QUANTUM;
            } else {
                // Run for the remaining burst and then remove the task
                run(temp->task, temp->task->burst);

                total_turnaround += temp->task->turnaround_time;
                total_waiting += temp->task->waiting_time;
                total_response += temp->task->response_time;

                delete(&task_list, temp->task);
            }

            temp = next_task;
        }

        num_tasks++;
    }

    // Calculate and display the average stats
    if (num_tasks > 0) {
        printf("Average Turnaround Time: %f\n", (float)total_turnaround / num_tasks);
        printf("Average Waiting Time: %f\n", (float)total_waiting / num_tasks);
        printf("Average Response Time: %f\n", (float)total_response / num_tasks);
    }
}
