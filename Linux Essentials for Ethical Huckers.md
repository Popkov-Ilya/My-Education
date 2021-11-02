# Linux Essentials for Ethical Hackers

https://youtu.be/1hvVcEhcbLM

*Ubuntu - дистр от народа*

## BASE

|	win + t (ctrl + alt + t) – терминал



|	[ pwd ] – print working directory



|	[ ls –l ] – таблица с правами и датой изменения

|	[ ls -lh ] – то же самое, но более по-людски (h - human-readable)

|	[ ls -lR ] – с рекурсией

|	[ ls -alpsh ] – удобно



|	[ touch ] – быстро создать файл

|	[ echo "text" > ] – быстро записать в файл

|	[ cat ] – быстро вывести содержимое файла



|	[ whatis ] – короткий help



|	[ cp file_name dir_name ] – так можно

|	[ mv file_name dir_name ] - так тоже



|	[ rm -R ] - удалить директорию (не путай с rmdir - он для пустых)



## PERMISSIONS

| owner - owner_group - other



|	[ chmod  a=rwx ] – установить права для всех

|	[ chmod -R ugo-x ]  – убавить права рекурсионно



|	[ chown user_name file_name ] – так вот 

|	[ chgrp group_name file_name ] – вот так вот



## FIND

|	[ grep -i word /file_path ] – поиск без учета регистра в файле

|	[ cat /file_path | grep -i "some words" ]



|	[ locate word ] – ищет файл по слову

|	[ locate /path --all "word" ] – то же самое

|	[ locate --all -c -i "word" ] – вывести количество совпадений с игнором регистра



|	[ find /dir_name -type f  -name "file_name" ] – найти файл (d - директорию)

|	[ find /dir_name  -name "file_name"  -size +1M ] – так тоже можно

|	[ find /dir_name  -type f -perm 400 ] – так тоже можно

|	[ find . -type f | xargs file ] – говорит что внутри файлов (данные, аски текст и тд)

|	[ find . type f -size 1033c ! -executable | xargs file ] – вывести инфу о неисполняемом файле нужного размера 

|	[ find -user user_name -group group_name ] – найти файл определенного пользователя и группы



## INFO

|	[ whoami ]  – понятно

|	[ who ] – текущий пользователь поподробней

|	[ hostname ] – тоже

|	[ sudo vim /etc/hostname ] – а вот такого я не ожидал

|	[ id ] – айдишники пользователя, основной группы, всех групп

|	[ groups ] – группы

|	[ groups user_name ] – группы пользователя

|	[ lsb_release -a ] – инфа про операционку

|	[ cat /etc/issue ] – тоже инфа про операционку

|	[ cat /etc/os-release] – тоже инфа про операционку

|	[ cat /etc/*release] – тоже инфа про операционку



|	[ lscpu ] – инфа про процессор

|	[ uname -a ] – инфа про систему

|	[ uname -s ] – операционка

|	[ uname -o ] – операционку

|	[ uname -r ] – инфа про версию

|	[ uname -i  ] || [ uname -p ] – инфа про разрядность процессора



## SHELL | BASH

|	[ cat /etc/shells ] – показывает какие оболочки у тебя есть

|	[ sh ] – перейти в оболочку shell

|	[ zsh ] || [ dash ] и тд – в другие оболочки

|	[ echo $SHELL ] – посмотреть оболочку по умолчанию

|	[ cat /etc/passwd | grep user_name ] – там в конце стоит оболочка по умолчанию для каждого юзера

|	[ chsh ] – изменить оболочку по умолчанию

|	[ vim .bashrc ] – настройки цветов, разверов и других параметров bash

|	[ cat /dev/null > ~/.bash_history ] – почистить историю как мужик!



## DISK

|	[ du ] – использование диска в рабочей директории

|	[ du -shc * ] – тоже самое но с суммированием (s) и по-человечески (h) и с подведением общей суммы (c)

|	[ df  -h] – использование диска, размер разделов, примонтированные директории

|	[ df -h | grep sd ] - хороший финт

|	[ df -ht ext4 ] - вывести только нужный тип



## Compressions

