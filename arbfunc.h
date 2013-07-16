#ifndef __ARBFUNC_H__
#define __ARBFUNC_H__


//names of functions to call
void functionA();
void functionB();
void functionC();

typedef struct command_t {
    char* name;             // readable name of function
    void (*func_p)();             // function to call to do command
    char* doc;              // documentation for this command
} command_t;

#endif
