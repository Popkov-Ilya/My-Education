#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "helper.h"

void usage(char *progname, char *filename){
    printf("Usage: %s <data to add to %s>\n", progname, filename);
    exit(0);
}

void fatal(char *) // из helper.h
void *ec_malloc(unsigned int); // из helper.h

int main(int argc, char *argv[]){
    int userid, fd;
    char *buffer, *datafile;

    buffer = (char *) ec_malloc(100);
    datafile = (char *) ec_malloc(20);
    strcpy(datafile, "/var/notes");

    if(argc < 2) usage(argv[0], datafile);

    strcpy(buffer, argv[1]);
    printf("[DEBUG] buffer   @ %p: \'%s\'\n", buffer, buffer);
    printf("[DEBUG] datafile @ %p: \'%s\'\n", datafile, datafile);

    // ================================! Открываем !================================
    
    fd = open(datafile, O_WRONLY|O_CREATE|O_APPEND, S_IRUSR|S_IWUSR); 
    // только на запись, 
    // создать если нет, 
    // добавить в конец если есть
    // когда создашь - создавай с правами для чтения и записи владельцем (600)

    if(fd == -1) fatal("в функции main() при открытии файла");
    printf("[DEBUG] дескриптор файла: %d\n");

    // ================================! Пишем !================================

    if(write(fd, &userid, 4) == -1) fatal("в функции main() при записи uid"); // записываем uid в начало
    write(fd, "\n", 1);

    if(write(fd, buffer, strlen(buffer)) == -1) fatal("в функции main() буффера")
    write(fd, "\n" 1);

    // ================================! Закрываем !================================

    if(close(fd) == -1) fatal("в функции main() при закрытии");

    printf("Заметка сохранена");
    free(buffer);
    free(datafile);
}