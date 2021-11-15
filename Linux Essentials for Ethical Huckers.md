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

\	username ALL=(ALL) /usr/bin/apt-get	= пользователь может использовать из судо только апт-гет

\	%group_name ALL=(ALL:ALL) /usr/bin/apt =группа члены которой могут выполнять эти команды







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

|	[ groups ] – посмотреть все группы?

|	[ cat /etc/group ] – тоже посмотреть все группы

|	[ groups User_name ] – посмотреть группы пользователя

|	[ groupadd group_name ] – создать группу

|	[ usermod -aG group_name user_name ] – добавить юзера в группу

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



## Network

|	[ ifconfig ] – олдовый способ (отворачивающийся дрейк)

|	[ ifconfig | grep inet ] – удобно смотреть на адреса

|	[ ip ] – молодежный способ (кивающий дрейк)

|	[ ip route show ] – показать таблицу маршрутизации

|	[ ip addr ] – посмотреть адреса

|	[ dhclient ] – (dynamic host configuration protocol (dhcp) client)

|	[ service networtk-manager restart ] – вроде как перезагрузить сетевой адаптер для получения нового ip

|	[ systemctl restart network-manager.service ] – то же самое

|	[ netstat -r ] – таблица маршрутизации

|	[ netstat -t ] – таблица tcp подключений

|	[ netstat -l ] – список прослушиваемых портов

|	[ netstat -lt ] – список прослушиваемых tcp портов

|	[ netstat -lu ] – список прослушиваемых udp портов

|	[ netstat -p ] – список процессов слушающих порты

|	[ netdiscover -i interface_name] – сканит сеть с помощью arp

|	[ cat /etc/resolv.conf ] – какая-то инфа про DNS

|	[ systemd-resolve --status ] – еще какая-то инфа про DNS

|	[ vim /etc/hosts ] – инфа про хосты

\	0.0.0.0 google.com = заблочить гугл зачем-то??? + не забыть перезапустить адаптер



## Tor & proxy

|	[ systemctl start tor ] – стартануть тор

|	[ netstat -lt | grep 9050 ] – посмотреть, что тор слушает 9050

|	[ vim /etc/proxychains.conf ] – настроить прокси

\	random_chain

\	proxy_dns

\	socks4    127.0.0.1    9050

\	socks5    127.0.0.1    9050 

|	[ proxychains firefox dnsleaktest.com ] – протестить прокси



## Service & process management

|	[ top ] – обычный менеджер процессов

|	[ htop ] – интерактивный менеджер процессов

|	[ free ] – использование RAM

|	[ free -h ] – "human-readable"

|	[ ps ] – процессы в этом терминале (снапшот)

|	[ ps aux ] – все процессы системы (снапшот)

|	[ kill pid_number ] – убить процесс (9 - это послать в процесс сигнал systemkill, но я хз как его использовать)

|	*Не путай сервис и процесс. Убить процесс - не значит убить сервис*

|	[ systemctl ] – все сервисы

|	[ systemctl start service_name ] – запустить сервис

|	[ systemctl stop service_name ] – остановить сервис

|	[ systemctl reload service_name ] – загрузить новую конфигурацию

|	[ systemctl restart service_name ] – запустить заново со старой конфигурацией

|	[ systemctl is-enable service_name ] – проверить включен ли сервис

|	[ systemctl enable service_name ] – включает сервис и генерирует symlink

|	[ systemctl disable servise_name ] – выключает

|	[ service service_name start/stop/status/restart ] – тоже самое, но почему-то хуже



## SSH

|	*юзаем openssh*

|	*есть клиент, а есть сервер, надо помнить*

|	[ apt install openssh-client ] – можно поставить только клиента

|	[ cat /etc/ssh/ssh_config ] – конфиг ssh клиента

|	[ ssh user_name@host_name ] – подрубиться к серверу

|	[ apt install openssh-server ] – поставить сервер

|	[ sudo vim /etc/ssh/sshd_config ] – настройки ssh сервера

\	PerminRootLogin no	=запретить подключаться к root-пользователю

\	MaxAuthTries 4	=Лимит попыток подключения

\	MaxSession 3	=Лимит сессий

\	PasswordAuthenticarion no	=Закрыть подключение по паролю, только по рса ключу

|	[ systemctl restart sshd.service ] – не забываем перезагрузить

|	[ sudo passwd -l root ] – заблокировать пароль рута (зачем?)

|	[ sudo passwd root ] – снова задать пароль руту

|	[ ssh-keygen -t rsa ] – сгенерировать ключ для ssh

|	[ ssh-copy-id host_name ] – скопировать id сервера 

|	[ ssh -i id_rsa_file user_name@host_name ] – подключение по ключу

|	[ chmod 400 id_rsa ] – важно защищать свои приватные ключи

|	[ scp file_name user_name@host_name:/path/to/directory ]



## CURL

|	[ curl <u>link</u> ] – загрузить сайт

|	[ curl -o /path/to/file.html <u>link</u> ] – сохранить в файл

|	[ curl -o ubuntuIso.iso <u>link</u> ] – скачать файл (убунту)

|	[ curl -O <u>link</u> ] – скачать файл с оригинальным именем 

|	[ curl -L <u>link</u> ] – скачать с переходом по редиректу

|	[ curl -I <u>link</u> ] – ответ от сервера (HTTP-header)

|	[ curl -v <u>link</u> ] – посмотреть на TLS-handshake

|	[ curl --data "log=admin&pwd=password" <u>link</u> ] – послать данные на сайт с помощью POST

