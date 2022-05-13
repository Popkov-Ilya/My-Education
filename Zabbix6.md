# Zabbix всему голова

все просто, когда все просто



## Server + Database

```bash
wget https://repo.zabbix.com/zabbix/6.0/ubuntu/pool/main/z/zabbix-release/zabbix-release_6.0-1+ubuntu20.04_all.deb
sudo dpkg -i zabbix-release_6.0-1+ubuntu20.04_all.deb
sudo apt update

wget https://downloads.mariadb.com/MariaDB/mariadb_repo_setup
sudo chmod +x mariadb_repo_setup
sudo ./mariadb_repo_setup --mariadb-server-version="mariadb-10.6"

sudo apt install mariadb-server
sudo systemctl enable mariadb
sudo systemctl start mariadb

sudo /usr/bin/mariadb-secure-installation #all Yes!

sudo apt install zabbix-server-mysql zabbix-sql-scripts
sudo mysql -u root -p
```



*Там где password не забудь поменять*

```mysql
create database zabbix character set utf8mb4 collate utf8mb4_bin;
create user zabbix@localhost identified by 'password';
grant all privileges on zabbix.* to zabbix@localhost identified by 'password';
flush privileges;
quit
```

```bash
sudo zcat /usr/share/doc/zabbix-sql-scripts/mysql/server.sql.gz | mysql -u zabbix -p zabbix
sudo nano /etc/zabbix/zabbix_server.conf
```

```properties
DBName=zabbix
DBUser=zabbix
DBPassword=password
```

```bash
sudo systemctl enable zabbix-server
sudo systemctl start zabbix-server

sudo tail -f /var/log/zabbix/zabbix_server.log
```



## Zabbix frontend

```bash
sudo apt install zabbix-frontend-php zabbix-apache-conf
sudo systemctl enable apache2
sudo systemctl restart zabbix-server apache2
```



Заходим на http://<ip-address>//zabbix → Прожимаем далее → Авторизуемся

> Стандартный логин: Admin 
>
> Стандартный пароль: zabbix



## Zabbix agent 2

```bash
wget https://repo.zabbix.com/zabbix/6.0/ubuntu/pool/main/z/zabbix-release/zabbix-release_6.0-1+ubuntu20.04_all.deb
sudo dpkg -i zabbix-release_6.0-1+ubuntu20.04_all.deb
sudo apt install zabbix-agent2
```



### Zabbix agent passive mode

```bash
sudo nano /etc/zabbix/zabbix_agent2.conf 
```

```properties
Server=127.0.0.1
Hostname=zabbix
```

```bash
sudo systemctl enable zabbix-agent2
sudo systemctl restart zabbix-agent2
```

Добавляем через UI



### Zabbix agent active mode

```properties
ServerActive=127.0.0.1
```

То же самое, только другой шаблон в UI. А также активный не отображается зеленым индикатором, но все равно шлет данные

Активные агенты слушаются на 10051 порту обычно



## SNMP-V3 monitored Linux host

Не забудь поменять пароли

```bash
# ubuntu
sudo apt install snmp snmpd libsnmp-dev
sudo net-snmp-create-v3-user -ro -a my_authpass -x my_privpass -A SHA -X AES snmpv3user
sudo nano /etc/snmp/snmp.conf
```

```properties
view systemview included .1
```

```bash
sudo systemctl enable snmpd
sudo systemctl start snmpd
```

Шаблон называется Linux SNMP. Пароли надо хранить в макросах.



## Простые проверки

Можно проверять доступность порта (например net.tcp.service[ssh, , 22])

Можно настроить Value mapping - чтобы 0 превращался в Down, а 1 в Up.



## Zabbix Trapper

Настраиваешь тип zabbix trapper, выставляешь key = trap

На тачке:

```bash
sudo apt install zabbix-sender
zabbix_sender -z 10.0.10.10 -s "zabbix" -k trap -o "Some text"
```



## SSH Agent

Теперь так можно!







# Vulners Plugin

