from Student import Student
from Student import BadStudent

student1 = Student("Jim", "business", 3.1, False)
student2 = Student("Jim", "business", 3.6, False)
print(student1.is_honor_role())
print(student2.is_honor_role())

student3 = BadStudent("Bim", "business", 3.1, False)
print(student3.name)





