#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>
#include <string.h>

#define MAX 128

void string_lower(char *userIn);
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
