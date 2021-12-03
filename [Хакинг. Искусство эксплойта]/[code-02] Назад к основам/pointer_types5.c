#include <stdio.h>

int main(){

    int i;
    char char_array[5] = {'a', 'b', 'c', 'd', 'e'};
    int int_array[5] = {1, 2, 3, 4, 5};
    unsigned int no_pointer;
    no_pointer = (unsigned int) char_array;
    
    for(i=0; i<5; i++){
        printf("[no_pointer] указывает на адрес %p, сожержащий целое число '%c'\n", no_pointer, *((char *) no_pointer));
        no_pointer = no_pointer + sizeof(char); // все проще!
    }

    no_pointer = (unsigned int) int_array;
    for(i=0; i<5; i++){
        printf("[no_pointer] указывает на адрес %p, содержащий символ %d\n", no_pointer, *((int *) no_pointer));
        no_pointer = no_pointer + sizeof(int);
    }

}