#include <iostream>
#include <string>
using namespace std;

class Animals {
private:
	string animal;
	string gender;
	string colour;
	string age;
	string name;
	string number;
public:
	Animals();
	Animals(string gender, string colour, string age, string name, string number );
	~Animals() {}; 
	void Display(void) {};
	void GetAnimals(string gender, string colour, string age, string name, string number);
	void SetAnimals(string gender, string colour, string age, string name, string number);
};
class Animals :public Animals {
	Animals();
	Animals(string gender, string colour, string age, string name);
	~Animals(); 
	void GetAnimals(string gender, string colour, string age, string name, string number);
	void SetAnimals(string gender, string colour, string age, string name, string number);
	void Display(void) 
	{
		cout << "Животное:"<< endl;
		cout << "Пол:"<< endl;
		cout << "Цвет:"<< endl;
		cout << "Возраст:"<< endl;
		cout << "Количество:"<< endl;

	};
};

void Animals::GetAnimals(string gender, string colour, string age, string name, string number)
{
	gender= gender;
	colour = colour;
	age = age;
	name = name;
	number = number;
}
void Animals::SetAnimals(string gender, string colour, string age, string name, string number)
{
	gender = gender;
	colour = colour;
	age = age;
	name = name;
	number = number;
}
int main()
{
	setlocale(LC_ALL, "ru");
	string gender, age, colour, name, number;
	void GetAnimals(string gender, string colour, string age, string name, string number);
	void Display();
	return 0;
};
