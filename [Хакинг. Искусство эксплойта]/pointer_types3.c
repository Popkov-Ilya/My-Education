#include <stdio.h>

int main(){

    int i;
    char char_array[5] = {'a', 'b', 'c', 'd', 'e'};
    int int_array[5] = {1, 2, 3, 4, 5};
    char *char_pointer;
    int *int_pointer;
    char_pointer = (char *) int_array; // здесь мы объясняем char_pointer что он все равно остается собой
    int_pointer = (int *) char_array;  // вне зависимости от того, на что он указывает

    for(i=0; i<5; i++){
        printf("[integer pointer] указывает на адрес %p, сожержащий целое число '%c'\n", int_pointer, *int_pointer);
        int_pointer = (int *) ((char *) int_pointer + 1); // прибавляем 1, так как к char pointer прибавляется 1
    }

    for(i=0; i<5; i++){
        printf("[char_pointer] указывает на адрес %p, содержащий символ %d\n", char_pointer, *char_pointer);
        char_pointer = (char *) ((int *) char_pointer + 1); // прибавляем 4, так как привели к int *
    }

}