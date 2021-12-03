#include <sdtio.h>
#include <string.h>

int main(){
    char message[10];
    int count, i;
    strcpy(message, "Hello, world!\n");
    printf("Сколько раз повторить");
    scanf("%d", &count);

    for(i=0; i<count; i++){
        printf("%3d - %s\n", i, message);
    }
}