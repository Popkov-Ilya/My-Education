#include <stdio.h>
#include <stdlib.h> // сам добавил, так лучше вроде
void usage(char *program_name){
    printf("Usage: %s <message> <# of times to repeat>\n", program_name);
    exit(1);
}

int main(int argc, char *argv[]){
    int i, count;
    
    if(argc < 3) usage(argv[0]);

    count = atoi(argv[2]); // atoi = ASCII to int
    printf("Повторяем %d раза...\n", count);

    for(i=0; i<count; i++){
        printf("%3d - %s\n", i, argv[1]);
    }
}