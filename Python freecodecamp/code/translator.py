
# all vowels -> *
def translate(phrase):
    translation = ""
    for letter in phrase:
        if letter.lower() in "aeiou":
            translation += "*"
        else:
            translation += letter
    return translation


'''
multiple
line
comments
'''


def translate2(phrase):
    map_file = open("map.txt", "w")
    print(map_file.readable())
    print(map_file.readlines())
    print("=")
    print(map_file.read())
    map_file.close()


def translate3():
    map_file = open("map_2.txt", "w")
    print(map_file.writable())
    map_file.write("\nsomebody once told me")
    map_file.close()


# print(translate(input("Enter a phrase: ")))
# translate2("some stuff")
translate3()

