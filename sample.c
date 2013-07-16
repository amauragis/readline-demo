

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include <readline/readline.h>
#include <readline/history.h>

int main(){
    char* input;
    char shell_prompt[100];
 
    // Configure readline to auto-complete paths when the tab key is hit.
    rl_bind_key('\t', rl_complete);
 
    while(1) {
        // Create prompt string from user name
        snprintf(shell_prompt, sizeof(shell_prompt), "%s$ ", getenv("USER"));
 
        // Display prompt and read input (n.b. input must be freed after use)...
        input = readline(shell_prompt);
 
        // Check for EOF.
        if (input == NULL)
            return 0;
 
        // Add input to history.
        if (*input != 0) add_history(input);
 
        // Do stuff...
 
        // Free input.
        free(input);
    }
    return -1;
}