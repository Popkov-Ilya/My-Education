# Essentials of OOP in CPP

Сурс – https://youtu.be/wN0x9eZLix4

### Начало

1 – В [С++] нужно ставить (;) после класса.

```c++
class Employee{
    std::string Name; // std как я понял - это нечто вроде System. и т.д.
    std::string Company;
}; // ← ← ← ты только глянь на это
```

2 – Можно заменить постоянное объявление *std::string*, если использовать *using*

```c++
using std::string;
class Employee{
    string Name; // std как я понял - это нечто вроде System. и т.д.
    string Company;
};
```

