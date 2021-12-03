#include <stdio.h>
#include <string.h>

int main(){
    char str_a[20];
    char *pointer;
    char *pointer2;
    
    strcpy(str_a, "Hello world!\n");
    pointer = str_a; //приравнивние ставит указатель на начало массива
    printf(pointer); //выведет "Hello world!"
    
    pointer2 = pointer + 2; //ставим его на два байта выше
    printf(pointer2); //выведет "llo world!"
    strcpy(pointer2, "y you guys!\n"); //запишет новый текст начиная с адреса pointer2
    printf(pointer); //выведет "Hey you guys!"   
}