#include <stdio.h>

int main(){
    int int_var = 5;
    int *int_ptr;

    int_ptr = &int_var; //Оператор (&) передает в указатель адрес переменной int_var

    printf("int_ptr = 0x%08x\n", int_ptr);      # выведется 0xbffff834
    printf("&int_ptr = 0x%08x\n", &int_ptr);    # выведется 0xbffff830
    printf("*int_ptr = 0x%08x\n", *int_ptr);    # выведется 0x00000005

    printf("int_var находится по адресу 0x%08x и содержит значение %d\n", &int_var, int_var);
    # выведется int_var находится по адресу 0xbffff834 и содержит значение 5
    printf("int_ptr находится по адресу 0x%08x, содержит значение 0x%08x и указывает на значение %d\n", &int_ptr, int_ptr, *int_ptr);
    # выведется int_ptr находится по адресу 0xbffff830, содержит значение 0xbffff834 и указывает на значение 5
}