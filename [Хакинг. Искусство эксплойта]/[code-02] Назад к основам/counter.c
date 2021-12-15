#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]){
    if(argc!=2){
        fprintf(stderr, "Usage: %s <word_to_cnt>\n", argv[0]);
        exit(-1);
    }
    else{
        printf("[=] %ld\n", strlen(argv[1]));
    }
}