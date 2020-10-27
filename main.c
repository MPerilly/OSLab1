#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>

#define MAX 128

extern int errno;

void string_lower(char *userIn);
int built_in_check(char *userIn);
int external_command_check(char *userIn);

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
        char *temp = NULL;
        temp = malloc(5 + strlen(userIn) + 1);
        if (temp == NULL){
            printf("Malloc failure line 36\n");
            exit(1);
        }
        strcpy(temp, "/bin/");
        switch(commandCheck) {
            case 0:
                //External command entered:
                if (external_command_check(userIn)) {
                    strcat(temp, userIn);
                }
                else {
                    // Unknown command, exit:
                    printf("Unknown Command entered: %s, exiting.\n", userIn);
                    exit(1);
                }
                char *args[] = {temp, 0};
                char *envp[] = {0};
                pid = fork();
                if (pid == 0) //i.e. child process
                {
                    //Print ID of child process and command:
                    printf("Child process %d will execute command: %s\n", getpid(), userIn);
                    //Use execve to change child to commanded process
                    printf("Executing: %s\n", args[0]);
                    fflush(stdout);
                    if (execve(args[0], args, envp) < 0){
                        printf("Execve failure\n");
                        fprintf(stderr, "Errno: %d\n", errno);
                        perror("Perror");
                    }
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

int external_command_check(char *userIn){
    if (!strcmp(userIn, "ls\n")) {
        return 1;
    }
    else if (!strcmp(userIn, "pwd\n")) {
        return 1;
    }
    else if (!strcmp(userIn, "ps\n")) {
        return 1;
    }
    else if (!strcmp(userIn, "date\n")) {
        return 1;
    }
    else if (!strcmp(userIn, "lscpu\n")) {
        return 1;
    }
    return 0;
}

