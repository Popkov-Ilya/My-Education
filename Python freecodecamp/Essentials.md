

# Essentials

Сурс – https://youtu.be/rfscVS0vtbw



### Переменные

Вот здесь уже интересно.  Чтобы объявить переменную в питоне не нужно вообще ничего лишнего. Только имя переменной и значение. И ВСЕ!

```python
character_name = "John"
```



### Распространенные возможности

##### len(str)

```python
phrase = "some string"
int_var = len(phrase)
```

##### str(var)

```python
int_var = 5
print("xxx" + str(int_var))
```

##### int(var)

```python
int_var = int(str_var) // если передать число с точкой, питон не сможет
```

##### float(var)

```python
float_var = float(str_var)
```

##### input(str)

```python
name = input("enter your name: ") # переноса строки не будет
```

##### #formatted output

Первый вариант (как в шарпе)

```python
var = 5
print(f"Formatted output the var = {var}") # нужно просто добавить букву  f перед кавычками
```

Второй вариант (как в си)

```python
print("{0:3} | {1}".format(char_sum, key)) # и передаешь все что нужно
```

##### #math

```python
from math import *
```

```python
abs(int_var) # модуль
max(4, 6) # max | min
floor(3.7) # floor | cail
ceil(3.7)
print(round(112.5890, 3)) # выведет 112.59, потому что 0 параметр - это целое число

# примечание ===========================
print(round(112.5890, -1)) # выведет 110
# конец примечания =====================

pow(2, int_var) # 2^int_var

# примечание ==========================================
print(pow(2, 3000)) # работает!
# более того. 
# Если math импортирован, то значение выведется с e+xxx
# а если не интегрирован, то значение выедется целиком
# конец примечания ====================================

sqrt(36) # квадратный корень, очевидно
```



---

##### Индекс символа

```python
phrase = "some string"
STRING_var = phrase[0] # индекс все равно возвращает string
# заметка = отрицательные индексы здесь работают как надо
```



##### Степень числа

```python
print(2**3) # выведет 8
```



---

##### .index(str)

```python
phrase = "some string"
int_var = phrase.index("str") # вернет 5
```

##### .replace(str, str)

```python
phrase = "some string"
str_var = phrase.replace("some", "another")
```



### Списки

В питоне не заморачиваются, я так смотрю, с массивами и сразу юзают списки

```python
list_name = ["first", 7, True]
print(list_var[1] + list_var[-1]) # выведет 9 (отрицательные индесы работают)
print(list_var[1:]) # выведет массив с 1 элемента по последний
```

А еще списки бывают многомерными

```python
list2d = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9],
    [0]
]
print(list2d)
print(list2d[0][0])
```

Но помни, <u>Списки – ссылочные типы</u>. Если их приравнять, то изменения отразятся в обоих списках. Для копирования есть метод copy.

##### .extend(list_var)

Добавляет список в конец списка.

##### .append(var)

Добавляет элемент.

##### .insert(index, var)

Сначала индекс, потом значение.

##### .remove(var)

Удаляет по значению. По индексу смотри ниже. Без аргумента не работает. <u>Если передать несуществующее значение – вызовет ошибку.</u>

##### .pop(index)

Удаляет по индексу (даже отрицательному), так еще и значение возвращает. Золото, а не функция

Поп без аргумента удаляет последний (Очевидно).

##### .clear()

Очищает природу.

##### .index(var, start, stop)

Находит первое значение. Var обязательный, start и stop – нет. <u>Индекс от несуществующего вызовет ошибку.</u>

Потому что здесь минус 1 – последний элемент и возвращать его нельзя. А если ты хочешь проверить наличие – используй буквально count. Ну или contains если ты крутой.

##### .count(var)

Количество

##### .\__contains__(var)

Проверяет наличие.

##### .sort() | .reverse()

Очевидно

##### .copy()

Возвращает копию массива



### Кортежи

Это как список из разных типов данных

```python
coordinates = (4, 5) # так он создается
```

Кортеж нельзя изменить. В методах только индекс и количество.

Более того. В него заходят значения, а не ссылки. Поэтому так вот тоже не изменить.

```python
num1 = 5
tuplex = (3, 4, num1)
print(tuplex) # 3, 4, 5
num1 = 7
print(tuplex) # 3, 4, 5
```



### Словари

##### Задание

Если в списке были квадратные скобки,  в кортеже круглые, то в словаре будут фигурные ("кучерявые").

```python
dictionaryX = {
    "Jan": "January",
    "Feb": "February"
}
print(dictionaryX) # принт вообще бессмертный
```

Обрати внимание: нужно двоеточие (без пробела слева и с пробелом справа)

##### Обращение

Есть два способа. Хороший и не очень

```python
print(dictionaryX["Jan"]) # вызовет ошибку, если не найдет
print(dictionaryX.get("Jun")) # вернет None, если не найдет
print(dictionaryX.get("Jun", "Not a valid key")) # вернет "Not a valid key", если не найдет
```

Тип ключа, значения и значения по умолчанию не важен.



### Функции

Синтаксис простой: **def** + **name** + **( )** + **:**

```python
def say_hi(name="Mike"): # можно юзать значения по умолчанию
    print(f"XXX + {name}")
```

Если в параметре юзать значение по умолчанию, что параметру автоматом присвоется тип. Это ни на что не влияет, но подчеркивать будет.

*Кста, тебе <u>Нельзя</u> юзать заглавные буквы в названии функции. А еще перед объявлением функции нужно отступать 2 строки.*

Помимо этого, можно юзать return просто так. (Хотя ты знаешь, что можно и не просто так)

```python
def say_hi(name="Mike"):
	return f"XXX + {name}"
```



### Условия + Циклы

##### if – elif – else

```python
if num1 < 3:
    say_hi(tuplex[1]) # я бунтарь
elif num1 == 3 and not bool_var or 1 < 3:
    say_hi(str(tuplex[0]))
else:
    print(say_hi2("1", "steve"))
```



##### while

```python
i = 1
while i < 10:
    if i == 5:
        print("5  is the best")
        break
    print(i)
    i += 1 # i++ не работает
```



##### for (each)

В python for – это на самом деле foreach.

```python
for var in collection:
    print("do some stuff")
```

Но можно и с цифрами

```python
for i in range(10): # можно и range(1, 10)
    print(i)
```



### Try-Except

```python
try:
    i = int(input())
except:
    print("Error")
```

А еще лучше

```python
try:
    i = int(input())
except ValueError as err:
    print(f"Error: {err}")
except ZeroDivisionError:
    print("Another error")
```

В python не принято делать дефолтные except.



### Работа с файловой системой

##### Чтение

```python
map_file = open("./map.txt", "r") 
'''
путь может быть как полным, так и относительным
r = чтение
w = запись
a = добавление
r+ = чтение и запись
'''
print(map_file.readable()) # bool значение
print(map_file.readline()) # выведет одну строку (ошибку на конце файла не вызывает)
print(map_file.read()) # выведет весь файл (как просто)
print(map_file.readlines()) # выведет все строки в виде массива (как удобно)
# кстати, кажется, что считывает он строку вместе с переносом строки на конце
```



##### Запись

```python
map_file = open("map_2.txt", "w")
print(map_file.writable())
map_file.write("\nsomebody once told me")
map_file.close()
```



### Модули и pip

##### Подключение своего файла

```python
import python_file_name # не нужно добавлять ".py"
from python_file_name import python_function_or_class_or_smthng # так тоже можно
print(python_file_name.function())
```



##### Подключаем что угодно

```bash
pip install module-name
```



### ООП

##### Классы и объекты

Они существуют!

```python
class Student: # задание класса
    def __init__(self, name, major, gpa, is_on_probation): # конструктор
        self.name = name # self.name мы задаем только здесь и оно существует везде, где оно необходимо
        self.major = major
        self.gpa = gpa
        self.is_on_probation = is_on_probation
    
    def is_honor_role(self): # функции
        return self.gpa >= 3.5
```



##### Наследование

Оно тоже!

```python
class BadStudent(Student): # конструктор тоже наследуется
    def make_stuff(self):
        return "some_stuff"
    def is_honor_role(self): # чтобы перезаписать функцию нужно просто написать ее
        return False
```



### Заметки

*В конце проги должна оставаться пустая строка.*

*Если в принт запихнуть деление целых чисел, то он все равно выведет float*

*False = 0, True = 1, bool(3) = True*

*print может выводить вообще все*

*Python не прощает неправильные индексы*

*Коменты в питоне работают следующим образом: <u>Однострочные через \#</u>, <u>Многострочные через \'\'\'</u>*

