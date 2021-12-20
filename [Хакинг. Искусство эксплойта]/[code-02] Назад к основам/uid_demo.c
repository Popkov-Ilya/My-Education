#include <stdio.h>

int main(){
    printf("реальный uid => %d\n", getuid());
    printf("эффективный uid => %d\n", geteuid());
}