# Git and GitHub for Beginners - Crash Course

Сурс – https://youtu.be/RGOj5yH7evk

*GitKraken – интерфейсный десктопный гит как и Гитхабовский*

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
```

