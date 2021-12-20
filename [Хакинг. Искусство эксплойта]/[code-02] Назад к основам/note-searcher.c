#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "helper.h"

#define FILENAME "/var/notes"

int print_notes(int, int, char *);// -----→ Функция вывода заметок
int find_user_note(int, int); // ---------→ Функция поиска заметки пользователя
int search_note(char *, char *); // ------→ Функция поиска по ключевым словам
void fatal(char *) // --------------------→ Функция обработки ошибок из helper.h

int main(int argc, char *argv[]){
    int userid, printing = 1, fd;
    char seachingstring[100];

    if(argc > 1) strcpy(seachingstring, argv[1]);
    else seachingstring[0] = 0; // обозначить строку пустой, а то там мусора много

    userid = getuid();
    fd = open(FILENAME, O_RDONLY); // только для чтения
    if(fd == -1) fatal("в функции main() при открытии файла на чтение");

    while(printing) printing = print_notes(fd, userid, seachingstring);
    printf("------[конец данных касающихся заметки]------\n");
    close(fd);
}

int print_notes(int fd, int uid, char *searchstring){
    int note_length;
    char byte = 0, note_buffer[100];
    note_length = find_user_note(fd, uid);
    
    if(note_length == -1) return 0;

    read(fd, note_buffer, note_length);
    note_buffer[note_length] = 0;
}