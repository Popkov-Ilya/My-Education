# Linux Essentials for Ethical Hackers

*Ubuntu - дистр от народа*

### base

|	win + t (ctrl + alt + t) – терминал

|	[ pwd ] – print working directory

|	[ ls –l ] – таблица с правами и датой изменения
|	[ ls -lh ] – то же самое, но более по-людски (h - human-readable)
|	[ ls -lR ] – с рекурсией

|	[ touch ] – быстро создать файл
|	[ echo "text" > ] – быстро записать в файл
|	[ cat ] – быстро вывести содержимое файла

|	[ whatis ] – короткий help

|	[ cp file_name dir_name ] – так можно
|	[ mv file_name dir_name ] - так тоже

|	[ rm -R ] - удалить директорию (не путай с rmdir - он для пустых)

### permissions

| owner - owner_group - other

|	[ chmod  a=rwx ] – установить права для всех
|	[ chmod -R ugo-x ]  – убавить права рекурсионно

|	[ chown user_name file_name ] – так вот 
|	[ chgrp group_name file_name ] – вот так вот



### find

|	[ grep -i word /file_path ] - поиск без учета регистра в файле
|	[ cat /file_path | grep -i "some words" ]

|	[ locate word ] - ищет файл по слову
|	[ locate /path --all "word" ] - то же самое
|	[ locate --all -c -i "word" ] - вывести количество совпадений с игнором регистра



### info

|	[ whoami ]  - понятно
|	[ hostname ] - тоже
|	[ sudo vim /etc/hostname ] - а вот такого я не ожидал
|	[ id ] - айдишники пользователя, основной группы, всех групп
|	[ groups ] - группы
|	[ groups user_name ] - группы пользователя
|	[ lsb_release -a ] - инфа про операционку
|	[ cat /etc/issue ] - тоже инфа про операционку
|	[ cat /etc/os-release] - тоже инфа про операционку
|	[ cat /etc/*release] - тоже инфа про операционку





