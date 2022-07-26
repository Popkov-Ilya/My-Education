# Modsecurity

## Apache

```bash
apt-get update
apt-get install libapache2-mod-security2
apt-cache show libapache2-mod-security2
systemctl restart apache2

cd /etc/modsecurity
cp modsecurity.conf-recommended modsecurity.conf

nano modsecurity.conf
```

```properties
SecRuleEngine On
```

```bash
systemctl restart apache2
cd etc/modsecurity/crs
git clone https://github.com/coreruleset/coreruleset
cd coreruleset
mv rules /etc/modsecurity/
nano /etc/apache2/mods-enabled/security2.conf
```

```properties
SecDataDir /var/cahce/modsecurity
Include /etc/modsecurity/modsecurity.conf
Include /etc/modsecurity/crs/*.conf
Include /etc/modsecurity/rules/*.conf
# остальные закоментировать
```

```bash
systemctl restart apache2
```



## Nginx

Правила находятся в директории 

```properties
/etc/nginx/modsec/rules
```

Параметры Include находятся в файле

```properties
/etc/nginx/modsec/main.conf
```

* Ранее правила брались из репозитория - https://github.com/SpiderLabs/owasp-modsecurity-crs

* Уязвимость текущей конфигурации правил - https://github.com/SpiderLabs/owasp-modsecurity-crs/issues/1359

* Текущий репозиторий правил - https://github.com/coreruleset/coreruleset



## Nginx

#### Prep

```bash
# Все под root
apt install libxslt-dev bison build-essential ca-certificates curl dh-autoreconf doxygen \
  flex gawk git iputils-ping libcurl4-gnutls-dev libexpat1-dev libgeoip-dev liblmdb-dev \
  libpcre3-dev libpcre++-dev libssl-dev libtool libxml2 libxml2-dev libyajl-dev locales \
  lua5.3-dev pkg-config wget zlib1g-dev zlibc libgd-dev

```



### ModSecurity

```bash
cd /opt && sudo git clone https://github.com/SpiderLabs/ModSecurity
cd ModSecurity
git submodule init
git submodule update
./build.sh
./configure
make
make install
```

#### ModSecurity-Nginx Connector

```bash
cd /opt && git clone --depth 1 https://github.com/SpiderLabs/ModSecurity-nginx.git
nginx -v
cd /opt && wget http://nginx.org/download/nginx-1.14.0.tar.gz
tar -xzvf nginx-1.14.0.tar.gz
cd nginx-1.14.0
nginx -V
./configure --add-dynamic-module=../ModSecurity-nginx <Configure Arguments>
make modules
mkdir /etc/nginx/modules
cp objs/ngx_http_modsecurity_module.so /etc/nginx/modules
nano /etc/nginx/nginx.conf


# альтернатива после ./configure
make modules
# в папке objs лежит модуль modsecurity если что
make
sudo checkinstall --pkgname=nginx --pkgversion=1.14.0 --nodoc # name - ?
# собрался deb-пакет
```

```properties
user www-data;
worker_processes auto;
pid /run/nginx.pid;
include /etc/nginx/modules-enabled/*.conf;
load_module /etc/nginx/modules/ngx_http_modsecurity_module.so;
```



#### SetUP

```bash
rm -rf /usr/share/modsecurity-crs
git clone https://github.com/coreruleset/coreruleset /usr/local/modsecurity-crs
mv /usr/local/modsecurity-crs/crs-setup.conf.example /usr/local/modsecurity-crs/crs-setup.conf
mv /usr/local/modsecurity-crs/rules/REQUEST-900-EXCLUSION-RULES-BEFORE-CRS.conf.example /usr/local/modsecurity-crs/rules/REQUEST-900-EXCLUSION-RULES-BEFORE-CRS.conf
```



#### Configure

```bash
mkdir -p /etc/nginx/modsec
cp /opt/ModSecurity/unicode.mapping /etc/nginx/modsec
cp /opt/ModSecurity/modsecurity.conf-recommended /etc/nginx/modsec/modsecurity.conf
cp /etc/modsecurity/modsecurity.conf-recommended /etc/modsecurity/modsecurity.conf
nano /etc/modsecurity/modsecurity.conf
```

```properties
SecRuleEngine On
```

```bash
nano /etc/nginx/modsec/main.conf
```

```properties
Include /etc/nginx/modsec/modsecurity.conf
Include /usr/local/modsecurity-crs/crs-setup.conf
Include /usr/local/modsecurity-crs/rules/*.conf
```

```bash
nano /etc/nginx/sites-available/default
```



#### Test

```bash
curl http://<SERVER-IP/DOMAIN>/index.html?exec=/bin/bash
```





# альтернатива
```bash
apt-get install -y apt-utils autoconf automake build-essential git libcurl4-openssl-dev libgeoip-dev liblmdb-dev libpcre++-dev libtool libxml2-dev libyajl-dev pkgconf wget zlib1g-dev

git clone --depth 1 -b v3/master --single-branch https://github.com/SpiderLabs/ModSecurity
cd ModSecurity
git submodule init
git submodule update
./build.sh
./configure
make
make install
cd ..


git clone --depth 1 https://github.com/SpiderLabs/ModSecurity-nginx.git

```





### Сурсы

https://github.com/perryk/ansible-role-nginx-modsec3-crs3

https://www.youtube.com/watch?v=XzeO2EL4sLU
