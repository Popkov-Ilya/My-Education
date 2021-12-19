# Essentials of OOP in CPP

Сурс – https://youtu.be/wN0x9eZLix4



1 – В [С++] нужно ставить (;) после класса.

```c++
class Employee{
    std::string name; // std как я понял - это нечто вроде System. и т.д.
    std::string company;
}; // ← ← ← ты только глянь на это
```

2 – Можно заменить постоянное объявление *std::string*, если использовать *using*

```c++
using std::string;
class Employee{
    string name; // std как я понял - это нечто вроде System. и т.д.
    string company;
};
```

3 – В [C++] есть только 3 гендера – public, private, protected. Private по умолчанию.

```c++
class Employee {
public: // ← ← ← этот public распространяется на все что находится под ним
    string name;
    string company;
    int age;
};
```

4 – Вывод в консоль выглядит совсем странно

```c++
void Introduse_Youself() {
	std::cout << "Name – " << Name << std::endl; // cout = console out && endl = end line
}
```

5 – Стандартные значения

| Тип данных | Значение   |
| ---------- | ---------- |
| int        | -858993460 |
| string     | ""         |

6 – Конструкторы

```c++
Employee employee0 = Employee("Saldina0", "youtube0", 0); // это норма. Просто без new.
Employee employee1("Saldina", "youtube", 25); // это - не норма. Я сделал это случайно. Но оно работает
```

7 – Держу в курсе – в [C++] нет свойств. Им приходится писать два отдельных метода для set и get. Они зовут это <u>Инкапсуляция</u>.

```c++
private:
	string _name;
public:
	void setName(string name) {
		_name = name;
	}
	string getName() {
		return _name;
	}
```

8 – Продолжаю держать в курсе. В [C++] нет интерфейсов. Им приходится пользоваться абстрактными классами. Да и те не совсем абстрактные, просто содержат виртуальные функции и только то. Они зовут это <u>Абстракция</u>.

```c++
class AbstractEmployee { // можно назвать IEmployee если ты из-за решетки вышел
	virtual void Ask_For_Promotion() = 0;
};

class Employee : AbstractEmployee {
	void Ask_For_Promotion() { }
}
```

9 – Очевидно, что <u>Наследование</u> хотя бы работает нормально.

```c++
class Developer : Employee {
public:
	string favorite_programming_language;

	Developer(string name, string company, int age, string laguage)
		:Employee(name, company, age) {
		favorite_programming_language = laguage;
	}
}
```

10 – Нюанс наследования – унаследованные методы и поля (public и protected) работают внутри класса, но не работают в экземпляре.

11 – Чтобы унаследованные методы и поля работали в экземпляре – нужно публично унаследоваться

```c++
class Developer : public Employee {
    // some stuff
}
```

12 – Кроссовер века – <u>Полиморфизм</u>

```c++
Developer d("john", "doe", 13, "c++");
Employee* e = &d; // не ожидал такого кроссовера?
e->Work(); // у указателей вместо точки стрела
// если Work был виртуальным сработает Work от Developer, а если не был, то Work от Employee

Employee* e2 = new Teacher("some", "man", 12, "c--"); // так тоже можноы
e2->Work();
```

13 – Приведение типов работает кста так же как в [C]. Только для классов нужно использовать указатели.