#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
#include "task.h"

// Function to insert a new task into the linked list
void insert(struct node **head, Task *newTask) {
    struct node *newNode = malloc(sizeof(struct node));  // Allocate memory for a new node
    newNode->task = newTask;  // Assign the task to the new node
    newNode->next = NULL;  // Set the next pointer to NULL

    // If the list is empty, set the new node as the head
    if (*head == NULL) {
        *head = newNode;
    } else {
        // Traverse to the end of the list and append the new node
        struct node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete a task from the linked list
void delete(struct node **head, Task *task) {
    struct node *temp = *head;
    struct node *prev = NULL;

    // Traverse the list to find the task to delete
    while (temp != NULL) {
        // Check if the current node's task matches the task to delete
        if (strcmp(task->name, temp->task->name) == 0) {
            // If the task to delete is the head, adjust the head pointer
            if (prev == NULL) {
                *head = temp->next; 
            } else {
                // Otherwise, unlink the current node from the list
                prev->next = temp->next; 
            }
            // Free the task and the node
            free(temp->task); 
            free(temp);  
            return;
        }
        prev = temp;  // Move to the next node
        temp = temp->next;
    }
}
