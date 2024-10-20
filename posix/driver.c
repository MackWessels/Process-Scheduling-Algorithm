#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task.h"
#include "list.h"
#include "schedulers.h"

#define SIZE 100  // Buffer size for reading tasks

int main(int argc, char *argv[]) {
    FILE *in;
    char *temp;
    char task[SIZE];
    char *name;
    int priority, burst;

    in = fopen(argv[1], "r");

    while (fgets(task, SIZE, in) != NULL) {

        // Duplicate the line for manipulation
        temp = strdup(task);                    

        name = strsep(&temp, ",");            
        priority = atoi(strsep(&temp, ","));  
        burst = atoi(strsep(&temp, ","));       

        // Add task to the list
        add(name, priority, burst);             

        //printf("Added task: %s, Priority: %d, Burst: %d\n", name, priority, burst);

        // Free the temporary string
        free(temp);
    }
    fclose(in);


    schedule();


    return 0;
}
