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
#-u (--set-upstream) для того, чтобы в дальнейшем использовать просто git push
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



Смотрим историю коммитов

```bash
git log
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



## BRANCHING

Все еще в VS Code

```bash
git branch #посмотреть ветки
git checkout -b feature-branch #намутить новую ветку
git checkout feature-branch #залететь в новую ветку
#тут происходят какие-то изменения в feature-branch и абсолютли никаких в master
git status #прочекаем
git add changed_file_name #добавим файл в будущий коммит
git commit -m "change file_name"

```



Первый вариант слияния

```bash
git checkout master
git diff feature-branch #сравнить мастер с новой веткой
git merge feature-branch #замерджить фичи в мастер
```



Второй вариант слияния

```bash
git push -u origin feature-branch #закидываем
#а теперь весело скачем на GitHub и делаем pull request и merge
git checkout master
git pull
#well done
```



Ну и в конце

```bash
git branch -d feature-branch #удалить ветку
```



## BRANCHING2

Пришло время настоящих конфликтов

```bash
git checkout -b conflict-branch
#производим изменения в conflict-branch
git commit -am "adding&commiting conflict" # -a значит add

git checkout master
#производим изменение в master
git commit -am "adding&commiting master"

git checkout conflict-branch
git diff master
git merge master
#теперь скачем в VS Code и разгребаем конфликт
git status
gir diff
git commit -am "merged with master"
```



## UNDOING

Поправляем непоправимое

```bash
#мутим [плохой]код
git add . #накидываем этот плохой код на вентилятор
git reset #Галя, у нас отмена
#теперь этот код все еще есть в файле, но нет в репозитории

git add . #снова накидываем
git commit -m "goodcode"
git reset HEAD~1 #типа на один коммит от головного, то есть к предыдущему
#код все еще в файле, но из репозитория изъят

git reset some_commit_hash #где вместо some_commit_hash реально номер коммита
git reset --hard some_commit_hash #вот в этом случае кода не останется ты реально откатишься
```



## FORK

Форк – это когда ты берешь чужой репозиторий и копируешь его к себе, чтоб менять как хочешь
