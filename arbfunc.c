
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/file.h>
#include <sys/stat.h>
#include <sys/errno.h>

#include <readline/readline.h>
#include <readline/history.h>

#include "arbfunc.h"

command_t commands[] = {
    { "funcA", functionA, "Call Function A" },
    { "funcB", functionB, "Call Function B" },
    { "funcC", functionC, "Call Function C" },
    { (char *)NULL, (void *)NULL, (char *)NULL }
};

int main(int argc, char** argv){
    char* input;
    char prompt_buf[100];

    int numCommands;

    numCommands = sizeof(commands) / sizeof(commands[0]);

    // printf("Sizeof commands: %li\nSizeof commands[0]: %li\n", sizeof(commands), sizeof(commands[0]));

    while(1){
        // print shell prompt
        snprintf(prompt_buf, sizeof(prompt_buf), "Stupid Program: ");

        input = readline(prompt_buf);

        // Check for EOF.
        if (input == NULL){
            printf("\n");
            return 0;
        }
        
        printf("Read: %s\n",input);

        // iterate through the command list, compare command name with those
        // in the commands array
        for(int i = 0; i < numCommands-1; i++){

            // if we have a command array match
            if(strcmp(input,commands[i].name) == 0){
                // printf("Hit command: %s\n", commands[i].name);
                // call the function pointed to by that command entry
                (*commands[i].func_p)();
                break;
            }
            // if we made it through the loop entirely, command wasn't found
            if (i == numCommands-2){
                printf("Command not found.\n");
            }
        }

        // Add input to history.
        if (*input != 0) add_history(input);

        free(input);
    }
    
}

void functionA(){
    printf("FunctionA\n");
}
void functionB(){
    printf("FunctionB\n");
}
void functionC(){
    printf("FunctionC\n");
}
