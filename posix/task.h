#ifndef TASK_H
#define TASK_H

typedef struct task {
    char *name;
    int tid;
    int priority;
    int burst;
    int initial_burst;
    int turnaround_time;
    int waiting_time;
    int response_time;
} Task;

#endif
