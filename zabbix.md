# Zabbix всему голова

все просто, когда все просто



## Server + Database

```bash
wget https://repo.zabbix.com/zabbix/6.0/ubuntu/pool/main/z/zabbix-release/zabbix-release_6.0-1+ubuntu20.04_all.deb
dpkg -i zabbix-release_6.0-1+ubuntu20.04_all.deb
apt update

wget https://downloads.mariadb.com/MariaDB/mariadb_repo_setup
chmod +x mariadb_repo_setup
./mariadb_repo_setup

apt install mariadb-server
systemctl enable mariadb
systemctl start mariadb

/usr/bin/mariadb-secure-installation #all Yes!

apt install zabbix-server-mysql zabbix-sql-scripts
mysql -u root -p
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
zcat /usr/share/doc/zabbix-sql-scripts/mysql/server.sql.gz | mysql -u zabbix -p zabbix
nano /etc/zabbix/zabbix_server.conf
```

```properties
DBName=zabbix
DBUser=zabbix
DBPassword=password
```

```bash
systemctl enable zabbix-server
systemctl start zabbix-server

tail -f /var/log/zabbix/zabbix_server.log
```

