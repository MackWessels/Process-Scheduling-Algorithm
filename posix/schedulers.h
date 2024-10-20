#ifndef SCHEDULERS_H
#define SCHEDULERS_H

#include "list.h"

#define MAX_PRIORITY 50
#define MIN_PRIORITY 1

extern struct node *task_list;

void add(char *name, int priority, int burst);
void schedule();

#endif
