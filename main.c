#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>
#include <string.h>

#define MAX 128

void string_lower(char *userIn);
void concatenate_command(char *dest, char *userIn, char *intermediate);
int built_in_check(char *userIn);

int main() {
    while(1){
        printf("lab1> ");
        //Get user input
        char *userIn = calloc(MAX, sizeof(char));
        if(userIn == NULL){
            printf("Memory Allocation Failure\n");
            exit(1);
        }
        fgets(userIn, MAX, stdin);
        string_lower(userIn);
        printf("User inputted: %s\n", userIn);
        printf("Parent Process %d\n", getpid());

        //Conditional checks if command is built in:
        int commandCheck = built_in_check(userIn);
        int pid;
        switch(commandCheck) {
            case 0:
                //External command entered:
                pid = fork();
                if (!pid) //i.e. child process
                {
                    //Print ID of child process and command:
                    printf("Child process %d will execute command: %s\n", getpid(), userIn);
                    //Use execve to change child to commanded process
                    char dest[50];
                    char intermediate[100][20];
                    concatenate_command(dest, userIn, intermediate);
                    int i = 0;
                    while(intermediate[i][0] != '\0'){
                        i++;
                    }
                    char *args[i];
                    int j = 0;
                    int check = execve(intermediate[0], intermediate, NULL);
                    //If below here, child process has failed, so tell user:
                    printf("Command not found!\n");
                    exit(1);
                }
                //Wait until child process finishes
                wait(NULL);
                break;
            case 1:
                //Greet entered:
                printf("Hello! :D\n");
                break;
            case 2:
                //printid entered:
                printf("The ID of the current process is %d\n", getpid());
                break;
            case 3:
                //Exit entered, end shell
                exit(0);
        }
        free(userIn);
    }
}

void string_lower(char *userIn){
    int i;
    for(i = 0; userIn[i]; i++){
        userIn[i] = tolower(userIn[i]);
    }
}

void concatenate_command(char *dest, char *userIn, char *intermediate){
    memset(dest, '\0', strlen(dest));
    int i;
    for (i = 0; i < 100; i++){
        memset(intermediate[i], '\0', 20);
    }
    char splits[strlen(userIn)];
    strcpy(splits, userIn);
    // Splits string
    char *delim = ' ';
    char *ptr = strtok(splits, delim);
    while(ptr != NULL){
        ptr = strtok(NULL, delim);
    }
    int j = 0;
    for (i = 0; j < strlen(splits); i++){
        int inter_index = 0;
        for(j; splits[j] != '\0';){
            intermediate[i][inter_index] = splits[j];
            inter_index++;
            j++;
        }
        j++;
    }
    strcpy(dest, "/bin/");
    strcat(dest, intermediate[0]);
}

int built_in_check(char *userIn){
    if (!strcmp(userIn, "greet\n")) {
        return 1;
    }
    else if (!strcmp(userIn, "printid\n")) {
        return 2;
    }
    else if (!strcmp(userIn, "exit\n")) {
        return 3;
    }
    return 0;
}
