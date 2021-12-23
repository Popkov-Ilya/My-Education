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
void fatal(char *); // --------------------→ Функция обработки ошибок из helper.h

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
    note_buffer[note_length] = 0; // ограничиваем мусор

    if(search_note(note_buffer, searchstring)) printf(note_buffer);
    return 1;    
}

// Функция просто определяет длину следующей заметки с нужным uid
int find_user_note(int fd, int user_uid){
    int note_uid = 1;
    unsigned char byte; // лол
    int length;

    while(note_uid != user_uid){
        if(read(fd, &note_uid, 4) != 4) return -1; // Если 4 байта не прочитаны, вернуть конец файла
        if(read(fd, &byte, 1) != 1) return -1; // Если байт не прочитан, вернуть конец файла (непонятный байт)

        byte = length = 0;
        while(byte != '\n'){
            if(read(fd, &byte, 1) != 1) return -1; // Если байт не прочитан, вернуть конец файла
            length++;
        }
    }

    lseek(fd, length * -1, SEEK_CUR); // Сместить позицию считывания на lenth байтов
    printf("[DEBUG] обнаружена заметка длиной %d байтов для id %d\n", length, note_uid);
    return length;
}

int search_note(char* note, char* keyword){
    int i, keyword_length, match=0;

    keyword_length = strlen(keyword);
    if(keyword_length == 0) return 1;

    for(i=0; i<strlen(note); i++){
        if(note[i] == keyword[match]) match++; // совпадение n-го байта
        else {
            if(note[i] == keyword[0]) match = 1; // начать с начала, если не совпадает с n-м байтом, но совпадает с первым
            else match = 0; // обнулить, если ни с кем не совпало
        }
        if(match == keyword_length) return 1; // случай полного совпадения
    }
    return 0;
}