#include <stdio.h>

int main(){

    int i;
    char char_array[5] = {'a', 'b', 'c', 'd', 'e'};
    int int_array[5] = {1, 2, 3, 4, 5};
    char *char_pointer;
    int *int_pointer;
    char_pointer = int_array; //здесь все наоборот
    int_pointer = char_array; //и здесь

    for(i=0; i<5; i++){
        printf("[integer pointer] указывает на адрес %p, сожержащий целое число '%c'\n", int_pointer, *int_pointer);
        int_pointer = int_pointer + 1; //не знаю почему не инкремент
    }

    for(i=0; i<5; i++){
        printf("[char_pointer] указывает на адрес %p, содержащий символ %d\n", char_pointer, *char_pointer);
        char_pointer = char_pointer + 1;
    }

}