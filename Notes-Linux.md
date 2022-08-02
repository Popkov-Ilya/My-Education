# Заметки о Линуксе

### PIP | Python

Если видишь *requirements.txt*

```bash
pip3 install -r requirements.txt
```

Чтобы создать виртуальную среду

```bash
python3 -m venv venv
source /venv/bin/activate
```

### 

### SCP - передача файлов

```bash
scp опции пользователь1@хост1:файл пользователь2@хост2:файл
```



### Systemctl

```bash
systemctl list-units --type service # все процессы
systemctl show servise.service --property=ActiveState # однострочное состояние процесса
```



### /etc/hosts

В файле /etc/hosts/ можно указать локальные доменные имена узлов



###  Interfaces

*/etc/netplan/\**

В этих файлах можно конфижить интерфейсы и добавлять их если что

```bash
sudo netplan apply
```



```bash
ifdown enp0s3
ifconfig enp0s3 down # одно и то же, нижнее работает лучше

/etc/init.d/networking stop # тоже полезно
```



### 





### ssh

```bash
ssh-keygen # сгенерирует ключи в папке ~/.ssh/
ssh-copy-id ignat@host2.test # перенесет публичный ключ на хост
ssh ignat@host2.test # подключится по ключу
```

