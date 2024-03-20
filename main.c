#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Task {
    char title[50];
};


void mainMenu();
void addTask(struct Task tasks[], int *totalTasks, int MAX_TASKS, int MAX_TITLE_LENGTH);
void deleteTask(struct Task tasks[], int *totalTasks);
void printAllTasks(struct Task tasks[], int totalTasks);


int main() {

    int MAX_TASKS = 10;
    int MAX_TITLE_LENGTH = 50;

    struct Task tasks[MAX_TASKS];
    int totalTasks = 0;
    
    char choice;

    do {
        mainMenu();

        scanf("%c", &choice);

        switch (choice) {
            case '1':
                addTask(tasks, &totalTasks, MAX_TASKS, MAX_TITLE_LENGTH);
                break;
            case '2':
                deleteTask(tasks, &totalTasks);
                break;
            case '3':
                printAllTasks(tasks, totalTasks);
                break;
            case '4':
                printf("\nExiting program...");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != '4');

    return 0;
}


void mainMenu() {
    char mainMenuText[] = 
        "\n=== To-Do List Menu ===\n"
        "1) Create Task\n"
        "2) Delete Task\n"
        "3) Display Tasks\n"
        "4) Exit\n\n"
        "Enter your option: ";

    printf(" %s", mainMenuText);
}


void addTask(struct Task tasks[], int *totalTasks, int MAX_TASKS, int MAX_TITLE_LENGTH) {
    
    if (*totalTasks >= MAX_TASKS) {
        printf("Task list is full. Can't add more tasks.\n");
        return;
    }
    
    char title[MAX_TITLE_LENGTH];
    printf("\nEnter Title: ");
    scanf(" %s", &title);
    
    strcpy(tasks[*totalTasks].title, title);
    (*totalTasks)++;
    printf("Task added successfully.\n");
}


void deleteTask(struct Task tasks[], int *totalTasks) {
    
    int taskId;
    printf("Enter the task id to remove (0-%d): ", *totalTasks - 1);
    scanf("%d", &taskId);

    if (taskId < 0 || taskId >= *totalTasks) {
        printf("Invalid task id.\n");
        return;
    }

    for (int i = taskId; i < *totalTasks - 1; i++) {
        strcpy(tasks[i].title, tasks[i+1].title);
    }

    (*totalTasks)--;
    printf("Tasks deleted.\n");
}


void printAllTasks(struct Task tasks[], int totalTasks) {
    
    printf("\n\n=== Task List ===\n\n");
    
    for (int i = 0; i < totalTasks; i++) {
        printf("{id: %d, title: %s}\n", i, tasks[i].title);
    }
}