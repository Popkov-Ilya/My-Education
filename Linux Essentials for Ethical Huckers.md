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



|	[ useradd user_name ] – намутить пользователя

|	[ useradd -m -c "comment" -s /bin/bash user_name ] – (m=домашняя дирректория; c = comment)

|	[ passwd ] – изменить свой пароль

|	[ passwd user_name ] – изменить кому-то другому 

|	[ userdel -r user_name ] – выпилить пользователя

|	[ usermod -aG user_name group_name ] – добавить пользователя в рок-группу (возможно в группу admin)

|	[ visudo ] – только от имени рута или админа можно редачить пользователей

\	username ALL=(ALL:ALL) ALL	= пользователь может из любой сессии(1) для всех юзеров(2) для всех групп(3) применять любые команды(4)

\ username ALL=(ALL) /usr/bin/apt-get	= пользователь может использовать из судо только апт-гет



## FIND

|	[ grep -i word /file_path ] – поиск без учета регистра в файле

|	[ cat /file_path | grep -i "some words" ]

|	[ file file_name ] – тип файла



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

|	[ tar -cf tar_name directory_path ] – создать архив директории

|	[ tar -cvf tar_name directory_path ] – (v=verbose)

|	[ tar -cvzf tar.gz_name directory_path ] – (z=gzip)

|	[ tar -xvf tar_name ] – распаковывает с объяснениями и перезаписью автоматом

|	[ tar -xvzf tar.gz_name ] – распаковывает tar.gz 

|	[ bzip2 ] – сам разберешься :)

