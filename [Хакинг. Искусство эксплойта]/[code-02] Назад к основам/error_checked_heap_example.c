#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *error_checked_malloc(unsigned int); // Прототип функции ?????????

int main(int argc, char *argv[]){
    char *char_ptr;
    int *int_ptr;
    int mem_size;

    if(argc<2) mem_size = 50;
    else mem_size = atoi(argv[1]); // atoi = ascii to int

    // ================================! 1 итерация !================================
    printf("===! act 1 !===\n");
    printf("\t[+] выделяется %d байтов в куче для char_ptr\n", mem_size);
    char_ptr = (char *) error_checked_malloc(mem_size);

    strcpy(char_ptr, "Эта память находится в куче.\n"); // 29 символов = 23*2+6=53 байта?
    printf("char_ptr (%p) → %s\n", char_ptr, char_ptr); // %s тоже съедает указатель
    
    // ================================! 2 итерация !================================
    printf("===! act 2 !===\n");
    printf("\t[+] выделяется 12 байтов в куче для переменной int_ptr\n");
    int_ptr = (int *) error_checked_malloc(12);

    *int_ptr = 31337; //  0x7A69
    printf("int_ptr (%p) → %d\n", int_ptr, *int_ptr); // для %d уже нужен оператор (*)

    // ================================! 3 итерация !================================
    printf("===! act 3 !===\n");
    printf("\t[-] освобождается память, занятая char_ptr\n");
    free(char_ptr);

    // ================================! 4 итерация !================================
    printf("===! act 4 !===\n");
    printf("\t[+] выделяется еще 15 байтов для переменной char_ptr\n");
    char_ptr = (char *) error_checked_malloc(15);

    strcpy(char_ptr, "новая память"); // 12 символов = 11*2+1=23 байта?
    printf("char_ptr (%p) → %s\n", char_ptr, char_ptr);

    // ================================! 5 итерация !================================
    printf("===! act 5 !===\n");
    printf("\t[-] освобождается память, занятая int_ptr\n");
    free(int_ptr);
    printf("\t[-] освобождается память, занятая char_ptr\n");
    free(char_ptr);
}

void *error_checked_malloc(unsigned int size){
    void *ptr;
    ptr = malloc(size);
    if(ptr == NULL){
        fprintf(stderr, "Ошибка, невозможно выделить память в куче.\n");
        exit(-1);
    }
    return ptr;
}