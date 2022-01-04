print("tuples = кортежи")
num1 = 2
tuplex = (3, 4, num1)


def say_hi(name="Mike"):
    print(f"XXX + {name}")


def say_hi2(age, name="Mike"):
    return f"XXX + {name} + {age}"


bool_var = True

if num1 < 3:
    say_hi(tuplex[1])  # я бунтарь
elif num1 == 3 and not bool_var or 1 < 3:
    say_hi(str(tuplex[0]))
else:
    print(say_hi2("1", "steve"))

print("dog" > "aaaa")
print("dog" > "dr")

print(float(False))

i = 1
while i < 10:
    if i == 5:
        print("5  is the best")
        break
    print(i)
    i += 1

for i in range(1, 10, 2):
    print(i**2)
print("============================")

x = 55
print(x)
