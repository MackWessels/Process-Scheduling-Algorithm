#include <stdio.h>
#include "task.h"

int system_time = 0; 


void run(Task *task, int slice) {

    // If the task hasn't started yet, set its response time
    if (task->response_time == -1) {
        task->response_time = system_time;
    }

    printf("Running task = [%s] [%d] [%d] for %d units.\n", task->name, task->priority, task->burst, slice);

    system_time += slice;  
    task->turnaround_time = system_time;  
    task->waiting_time = task->turnaround_time - task->initial_burst; 
}
