/* fileman.c -- A tiny application which demonstrates how to use the
   GNU Readline library.  This application interactively allows users
   to manipulate files and their modes. */

#include <stdio.h>
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
  { "funcc", functionC, "Call Function C" },
  { (char *)NULL, (int *)NULL, (char *)NULL }
};

int main(int argc, char** argv){
    char* line;
    char* s;


}

