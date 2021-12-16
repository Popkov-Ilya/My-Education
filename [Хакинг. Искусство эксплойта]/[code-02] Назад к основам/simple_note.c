#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h> // file control
#include <sys/stat.h>

void usage(char *prog_name, char *file_name){
    printf("Usage: %s <data to add to %s>\n", prog_name, file_name);
    exit(0);
}

void fatal(char *); // Прототип функции обработки критических ошибок
void *ec_malloc(unsigned int); // Прототип функции malloc с обработкой ошибок

int main(int argc, char *argv[]){
    int fd; // FILE DESCRIPTOR
    char *buffer, *data_file; // так объявляют у нас в бостоне

    // ================================! Подготовка !================================
    buffer = (char *) ec_malloc(100);
    data_file = (char *) ec_malloc(20);
    strcpy(data_file, "/tmp/notes");

    if(argc < 2) usage(argv[0], data_file);

    strcpy(buffer, argv[1]);
    printf("[DEBUG] buffer @ %p: \'%s\'\n", buffer, buffer); // %s ест указатель как %p
    printf("[DEBUG] datafile @ %p: \'%s\'\n", data_file, data_file);

    strncat(buffer, "\n", 1); // Добавление новой строки

    // ================================! Запись в файл !================================
    fd = open(data_file, O_WRONLY|O_CREATE|O_APPEND, S_IRUSR|S_IWUSR);
    
    if(fd == -1) fatal("в функции main при открытии файла");
    printf("[DEBUG] дескриптор файла %d\n", fd);

    if(write(fd, buffer, strlen(buffer)) == -1) fatal("в функции main при записи");
    if(close(fd) == -1) fatal("в функции main при закрытии");

    printf("Заметка сохранена\n");
    free(buffer);
    free(data_file);
}

void fatal(char* message){
    char error_message[100];

    strcpy(error_message, "[!!] Критическая ошибка ");
    strncat(error_message, message, 83); // ??
    perror(error_message);
    exit(-1);
}

void *ec_malloc(unsigned int size){
    void *ptr;
    ptr = malloc(size);
    if(ptr == NULL) fatal("в функции ec_malloc при выделении памяти");
    return ptr;
}