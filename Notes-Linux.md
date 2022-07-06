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

