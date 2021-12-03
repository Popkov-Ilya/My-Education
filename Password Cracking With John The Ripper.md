# Password Cracking With John The Ripper - RAR/ZIP & Linux Passwords

Сурс –  https://youtu.be/XjVYl1Ts6XI

*Важное примечание: John the Ripper не тянет на моей малине :(*

Гайд короткий и простой. Охватывает только самые базовые возможности, но хоть что-то.

##### Сюжет #1

В первую очередь нужно получить парольный хэш

```bash
zip2john pi_arch.zip > pi_arch_pwd_hash.txt
# здесь будет длинная строка с названием файла внутри и хэшом
rar2john pi_arch.rar > pi_arch_pwd_hash.txt
# то же самое но для rar
```

Лучше, конечно, сохранять все выводы в файл, а не выводить в консоль.

```bash
john --format=zip ./pi_arch.zip # будет долго искать пароль
```

Итог - получен пароль (возможно)



##### Сюжет #2

Создаем юзверя

```bash
useradd userX
passwd userX
```

Дальше все просто

```bash
john /etc/shadow # здесь хранятся хэши
```

Итог - получен пароль (возможно)