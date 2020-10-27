#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>

int main(){
    char * temp[] = {"ls", NULL};
    execve("/bin/ls", temp, NULL);
    return 0;
}