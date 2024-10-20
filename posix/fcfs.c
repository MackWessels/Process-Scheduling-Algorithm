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

    // Loop through the task list in the order tasks were added (FCFS)
    while (task_list != NULL) {
        temp = task_list;

        // Run the task
        run(temp->task, temp->task->burst);

        // Update statistics
        total_turnaround += temp->task->turnaround_time;
        total_waiting += temp->task->waiting_time;
        total_response += temp->task->response_time;

        // Remove the task after completion
        delete(&task_list, temp->task);
        num_tasks++;  
    }

    // Display average statistics if tasks were processed
    if (num_tasks > 0) {
        printf("Average Turnaround Time: %f\n", (float)total_turnaround / num_tasks);
        printf("Average Waiting Time: %f\n", (float)total_waiting / num_tasks);
        printf("Average Response Time: %f\n", (float)total_response / num_tasks);
    }
}
