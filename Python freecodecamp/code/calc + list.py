# num1 = input("Enter a number: ")
# num2 = input("Enter another number: ")
num1 = 5
num2 = 6
result = float(num1) + float(num2)
print(f"Your result is {result}")
another_list = [num1, num2]
list_var = ["first", 8, True]
list_var[0] = "second"
print(f"Some sum {list_var[1] + list_var[2]}")
list_var.extend(another_list)
print(list_var)
list_var.pop()
print(list_var)
list_var.append("second")
print(list_var)
index = list_var.index("second")
print(f"Index of second = {index}")
index = list_var.index("second", 1)
print(f"Index of second = {index}")
print(f"IsInPolygon {list_var.__contains__('second')}")
print(f"Count {list_var.count('second')}")
print(f"Count {list_var.count('s')}")

print("----------------")
list_var2 = list_var
print(f"lv {list_var}")
print(f"lv2 {list_var2}")
list_var2[1] = "X"
print(f"lv {list_var}")
print(f"lv2 {list_var2}")







