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
            //External command entered:
            case 0:
                // If the external command is valid, concatenate:
                switch(external_command_check(userIn)){
                    // Unknown command, exit:
                    case 0:
                        printf("Unknown Command entered: %s, exiting.\n", userIn);
                        exit(1);
                        break;
                    // ls entered:
                    case 1:
                        pid = fork();
                        if (pid == 0) //i.e. child process
                        {
                            //Print ID of child process and command:
                            printf("Child process %d will execute command: %s\n", getpid(), userIn);
                            char *args[] = {"ls", NULL};
                            //Use execve to change child to commanded process
                            printf("Executing: %s\n", args[0]);
                            fflush(stdout);
                            if (execve("/bin/ls", args, NULL) == -1){
                                printf("Execve failure\n");
                                fprintf(stderr, "Errno: %d\n", errno);
                                perror("Perror");
                            }
                            //If below here, child process has failed, so tell user:
                            printf("Command not found!\n");
                            exit(1);
                        }
                        wait(NULL);
                        break;
                    // pwd entered
                    case 2:
                        pid = fork();
                        if (pid == 0) //i.e. child process
                        {
                            //Print ID of child process and command:
                            printf("Child process %d will execute command: %s\n", getpid(), userIn);
                            char *args[] = {"pwd", NULL};
                            //Use execve to change child to commanded process
                            printf("Executing: %s\n", args[0]);
                            fflush(stdout);
                            if (execve("/bin/pwd", args, NULL) == -1){
                                printf("Execve failure\n");
                                fprintf(stderr, "Errno: %d\n", errno);
                                perror("Perror");
                            }
                            //If below here, child process has failed, so tell user:
                            printf("Command not found!\n");
                            exit(1);
                        }
                        wait(NULL);
                        break;
                    // ps entered
                    case 3:
                        pid = fork();
                        if (pid == 0) //i.e. child process
                        {
                            //Print ID of child process and command:
                            printf("Child process %d will execute command: %s\n", getpid(), userIn);
                            char *args[] = {"ps", NULL};
                            //Use execve to change child to commanded process
                            printf("Executing: %s\n", args[0]);
                            fflush(stdout);
                            if (execve("/bin/ps", args, NULL) == -1){
                                printf("Execve failure\n");
                                fprintf(stderr, "Errno: %d\n", errno);
                                perror("Perror");
                            }
                            //If below here, child process has failed, so tell user:
                            printf("Command not found!\n");
                            exit(1);
                        }
                        wait(NULL);
                        break;
                    // date entered
                    case 4:
                        pid = fork();
                        if (pid == 0) //i.e. child process
                        {
                            //Print ID of child process and command:
                            printf("Child process %d will execute command: %s\n", getpid(), userIn);
                            char *args[] = {"date", NULL};
                            //Use execve to change child to commanded process
                            printf("Executing: %s\n", args[0]);
                            fflush(stdout);
                            if (execve("/bin/date", args, NULL) == -1){
                                printf("Execve failure\n");
                                fprintf(stderr, "Errno: %d\n", errno);
                                perror("Perror");
                            }
                            //If below here, child process has failed, so tell user:
                            printf("Command not found!\n");
                            exit(1);
                        }
                        wait(NULL);
                        break;
                    // lscpu entered
                    case 5:
                        pid = fork();
                        if (pid == 0) //i.e. child process
                        {
                            //Print ID of child process and command:
                            printf("Child process %d will execute command: %s\n", getpid(), userIn);
                            char *args[] = {"lscpu", NULL};
                            //Use execve to change child to commanded process
                            printf("Executing: %s\n", args[0]);
                            fflush(stdout);
                            if (execve("/bin/lscpu", args, NULL) == -1){
                                printf("Execve failure\n");
                                fprintf(stderr, "Errno: %d\n", errno);
                                perror("Perror");
                            }
                            //If below here, child process has failed, so tell user:
                            printf("Command not found!\n");
                            exit(1);
                        }
                        wait(NULL);
                        break;
                }
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
        return 2;
    }
    else if (!strcmp(userIn, "ps\n")) {
        return 3;
    }
    else if (!strcmp(userIn, "date\n")) {
        return 4;
    }
    else if (!strcmp(userIn, "lscpu\n")) {
        return 5;
    }
    return 0;
}

