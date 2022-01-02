

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



### Заметки

*В конце проги должна оставаться пустая строка.*

*Если в принт запихнуть деление целых чисел, то он все равно выведет float*
