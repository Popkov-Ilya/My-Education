#include <iostream>
using std::string;

class AbstractEmployee { // можно назвать IEmployee если ты из-за решетки вышел
	virtual void Ask_For_Promotion() = 0;
};

class Employee : AbstractEmployee {
protected:
	string _name;
	string _company;
	int _age;

public:
	void setName(string name) {
		_name = name;
	}
	string getName() {
		return _name;
	}

	Employee(string name, string company, int age) {
		_name = name;
		_company = company;
		_age = age;
	}

	void Introduse_Youself() {
		std::cout << "Name - " << _name << "\tCompany - " << _company << "\tAge - " << _age << std::endl;
	}
	virtual void Work() {
		std::cout << getName() << " check the emails and drik coffee" << std::endl;
	}

	// Унаследовано через AbstractEmployee
	void Ask_For_Promotion() {
		if (_age > 30) std::cout << _name << " is promouted!" << std::endl;
		else std::cout << _name << ", sorry, No promotion for you" << std::endl;
	}

};

class Developer : public Employee {
public:
	string favorite_programming_language;

	Developer(string name, string company, int age, string laguage)
		:Employee(name, company, age) {
		favorite_programming_language = laguage;
	}

	void FixBug() {
		std::cout << getName() << " fix the bug, using " << favorite_programming_language << std::endl;
	}
	void Work() {
		std::cout << getName() << " surf the StackOverflow" << std::endl;
	}
};

class Teacher : public Employee {
public:
	string subject;

	Teacher(string name, string company, int age, string subj)
		:Employee(name, company, age) {
		subject = subj;
	}

	void Prepare_a_Lesson() {
		std::cout << getName() << " prep a lesson for " << subject << std::endl;
	}
	void Work() {
		std::cout << getName() << " just drik coffee" << std::endl;
	}
};

int main()
{
	Developer d("john", "doe", 13, "c++");


	Employee* e = &d; // не ожидал такого кроссовера?
	e->Ask_For_Promotion();
	e->Work();

	Employee* e2 = new Teacher("some", "man", 12, "c--");
	e2->Work();

	Employee* ee[] = { new Teacher("some", "man", 12, "c--"), new Teacher("another", "man", 13, "d--") };
	ee[0]->Introduse_Youself();
	ee[1]->Introduse_Youself();

	Teacher* t = (Teacher*)ee[0];
	t->Introduse_Youself();
	t->Prepare_a_Lesson();
}
