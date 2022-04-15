# OOP in python

Продолжим тему

сурс => https://youtu.be/Ej_02ICOIgs



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



### Методы класса

```python
# вызывается Item.inst_from_csv(), но может вызываться и от экземпляра
class Item:
    @classmethod
    def inst_from_csv(cls):  # cls вместо self
        pass
```



### Статические методы

```python
# вызывается Item.is_integer(), но может вызываться и от экземпляра
class Item:
    @staticmethod
    def is_integer():  # self не требуется
        pass
```



### Приватные методы

```python
class Item:
    def __private_method(self):  # просто добавь два подчеркивания!
        pass
```



### Репрезентация класса (вывод) !! не путай с \_\_str\_\_

```python
class Item:
    def __init__(self, name: str, count: int):
        self.name = name
        
    def __repr__(self):  # не путай с __str__
        return f"Item('{self.name}', {count})"
```



### Наследование (inheritance)

```python
class Phone(Item):
    def __init__(self, name: str, price: int, quantity: int = 0, broken: int = 0):
        super().__init__(name, price, quantity)  # повтори
        self.broken = broken
```



### Readonly свойство (getter)

```python
class Item:
    def __init__(self, name: str, price: int, quantity: int = 0):
        self._name = name # !!!! с одной чертой - выводит уведы при обращении

	@property
    def name(self):
        return self._name
```

```python
class Item:
    def __init__(self, name: str, price: int, quantity: int = 0):
        self.__name = name # !!!! с двумя - запрещает вовсе

	@property
    def name(self):
        return self.__name
```



### Setter

```python
class Item:
    def __init__(self, name: str, price: int, quantity: int = 0):
        self.__name = name # !!!! с двумя - запрещает вовсе

	@property
    def name(self):
        return self.__name
    
    @name.setter
    def name(self, value):
        if len(value) > 10:
            raise Exception("Too long!")
        else:
        	self.__name = value
```





