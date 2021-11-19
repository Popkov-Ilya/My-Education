# Git and GitHub for Beginners - Crash Course

Сурс – https://youtu.be/RGOj5yH7evk

*GitKraken – интерфейсный десктопный гит как и Гитхабовский*

## BASE

Создаем новый репозиторий

```bash
echo "# repo-header" >> README.md
git init
git add README.md
git commmit -m "commit name"
git remote add origin git@github.com:user-name/repo-name.git
git push -u origin master
```



Открываем репозиторий из VS Code

```bash
git clone git@github.com:user-name/repo-name.git
cd repo-name #чтобы войти непосредственно в репозиторий и мутить воду там
la #сокращение в vs code от ls -la
```



Коммитим в VS Code

```bash
git status #покажет что с репозиторием вообще происходит
git add . #добавить все
git status #проверяем
git commit -m "messege" -m "description" #записываем (да, там два раза -m)
git push
```



## SSH KEYS

В терминале создаем ключики

```bash
ssh-keygen -t rsa -b 4096 -C "mailofgithub@example.com"
key_name #кейген попросит ввести имя (или путь) сохранения ключа
passphrase #можно ввести парольную фразу, а можно и скипнуть
ls | grep key_name #посмотреть созданные ключи
pbcopy < /path/to/key_name.pub #опционально можно скопировать вот так или же вручную
```

Вставляем публичный ключ в GitHub>Настройки>SSH and GPG keys>New SSH key



## PUSH

