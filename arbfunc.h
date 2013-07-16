#ifndef __ARBFUNC_H__
#define __ARBFUNC_H__


//names of functions to call
void functionA(void* param);
void functionB(void* param);
void functionC(void* param);

typedef struct command_t {
    char* name;             // readable name of function
    void (*func_p)(void*);  // function to call to do command
    char* doc;              // documentation for this command
} command_t;

#endif
