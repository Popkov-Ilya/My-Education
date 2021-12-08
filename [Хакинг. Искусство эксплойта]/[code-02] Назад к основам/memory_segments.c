#include <stdio.h>

int global_var;
int global_initialized_var = 5;

void function(){
    int stack_var;
    printf("0x%08x: stack_var (function)\n", &stack_var);
}

int main(){
    int stack_var;
    int stack_var2 = 5;
    static int static_initialized_var = 5;
    static int static_var;
    int *heap_var_ptr;

    heap_var_ptr = (int *)malloc(4); // malloc возвращает void*

    printf("0x%08x: global_initialized_var\n", &global_initialized_var);
    printf("0x%08x: static_initialized_var\n", &static_initialized_var);
    printf("0x%08x: global_var\n", &global_var);
    printf("0x%08x: static_var\n", &static_var);
    printf("0x%08x: heap_var_ptr\n", heap_var_ptr);
    printf("0x%08x: stack_var\n", stack_var);
    printf("0x%08x: stack_var2\n", stack_var2);
    function();

}