# Docker + Kubernetes

Сурс – https://youtu.be/Wf2eSG3owoA



## Докер

*Здесь должна быть условная картинка про КООООРДИНАЛЬНУЮ разницу между виртуализацией и контейнеризацией, но кому она нужна?*

##### Установка

|	Вариант № 1: (мой любимый) с помощью скрипта

```bash
# как пиратская игра - скачать и установить
curl -fsSL https://get.docker.com -o get-docker.sh
sudo sh get-docker.sh
```

|	Вариант № 2: из репозитория

```bash
# удалить старую версию
sudo apt-get remove docker docker-engine docker.io containerd runc
sudo apt-get update
# установить требуемые библиотеки (в ubuntu и так есть)
sudo apt-get install \
    ca-certificates \
    curl \
    gnupg \
    lsb-release
# загрузить сертификат
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo gpg --dearmor -o /usr/share/keyrings/docker-archive-keyring.gpg
# дописать репозиторий
echo \
  "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/docker-archive-keyring.gpg] https://download.docker.com/linux/ubuntu \
  $(lsb_release -cs) stable" | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
# обновиться + установиться
sudo apt-get update
sudo apt-get install docker-ce docker-ce-cli containerd.io
# проверить
sudo docker run hello-world
```



Решение проблемы с root правами (https://docs.docker.com/engine/install/linux-postinstall/).

```bash
sudo groupadd docker
sudo usermod -aG docker $USER
newgrp docker # опционально или перезапуститься (приоритетно)
docker run hello-world # проверка
```



##### Образы

Также известны в узких кругах как *Images*

```bash
docker pull nginx # скачать образ
docker images # просмотреть все скачанные образы
```

Продолжение банкета

```bash
docker run nginx:latest # запустить
docker container ls # посмотреть
docker run -d nginx:latest # запустить в фоне
docker stop contid # остановить контейнер с определенным именем или id
```

