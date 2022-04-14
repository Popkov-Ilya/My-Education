# OOP in python

Продолжим тему



### Задание класса

```python
class Item:
    pass


item1 = Item()
item1.name = "Phone" # добавлять атрибуты можно совершенно не стесняясь
item1.price = 5000

print(item1)
print(item1.name)
```



### Конструктор

```python
class Item:
    # методы с двумя подчеркиваниями называются магическими (magic)
    # дефолтные параментры как обычно в конце
    def __init__(self, name, quantity=0):
        self.name = name
        self.quantity = quantity
```



### Тип параметров метода / конструктора

```python
class Item:
    # если не совпадет тип - выведет предупреждение в IDE
    # если не совпадет assert - выведет ошибку
    def __init__(self, count: int):
        assert count >= 0 # просто AssertionError
        assert count < 1000, "Выведет этот текст после AssertionError!"
```



### Class attributes | Атрибуты класса

Item.pay_rate - общий (статический

self.pay_rate | item1.pay_rate - у каждого свой

```python
class Item:
    pay_rate = 0.8 # у каждого свой, у класса общий

    def some_method(self):
        print(self.pay_rate)
        print(Item.pay_rate)
        Item.pay_rate = 0.9 # это как изменить статическую переменную
        print(self.pay_rate)
        print(Item.pay_rate)

item2 = Item()
item3 = Item()
Item.pay_rate = 0.7 # можно и вне класса
item2.pay_rate = 0.1
item2.some_method()  # 0.1 0.7 0.1 0.9
item3.some_method()  # 0.9 0.9 0.9 0.9

# Бонус
print(Item.__dict__)  # выведет все атрибуты класса
```



Статически можно использовать список, записывая в него все новые элементы

```python
class Item:
    all = []

    def __init__(self, name: str):
        self.name = name
        Item.all.append(self)


items = [
    Item("1"),
    Item("2"),
    Item("3"),
    Item("4"),
    Item("5"),
]

for i in Item.all:
    print(i.name)
```



### Репрезентация класса (вывод) !! не путай с \_\_str\_\_

```python
class Item:
    def __init__(self, name: str, count: int):
        self.name = name
        
    def __repr__(self):  # не путай с __str__
        return f"Item('{self.name}', {count})"
```

