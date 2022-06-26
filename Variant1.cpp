#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Animal
{
protected:
	float Vozr;
	int Height;
	double Mass;
	string Name;
	string Gender;
	string Type;
	string Color;
public:

	Animal(); //конструктор
	Animal(float Vozr, int Height, double Mass, string Name, string Gender, string Type, string Color); //альтернативный(с параметром)
	~Animal() { cout <<"\n"<<"End"; }; //деструктор
	void Getter(float v, int& h, double& m, string& n, string& g, string& t, string& c);
	void Getter(float v, int& h, string& n, string& g, string& t, string& c);
	double GetMass(double& m); //получение массы
	void Setter(float v, int h, double m, string n, string g, string t, string c);
	void Show() // метод вывода
	{
		ofstream fout("info.txt"); //создание файла
		cout << "Животное: " << "\n"
			<< "Возраст = " << Vozr << '\n'
			<< "Рост = " << Height << '\n'
			<< "Вес = " << Mass << '\n'
			<< "Имя = " << Name << '\n'
			<< "Пол = " << Gender << '\n'
			<< "Вид = " << Type << '\n'
			<< "Цвет = " << Color << '\n';
		fout << "Животное: " << "\n" // вывод файла
			<< "Возраст = " << Vozr << '\n'
			<< "Рост = " << Height << '\n'
			<< "Вес = " << Mass << '\n'
			<< "Имя = " << Name << '\n'
			<< "Пол = " << Gender << '\n'
			<< "Вид = " << Type << '\n'
			<< "Цвет = " << Color << '\n';

	}
};
class Human :protected Animal // создание класса наследник
{
public:
	Human(); //конструктор
	Human(float Vozr, int Height, double Massa, string Name, string Gender, string Type, string Color) //алтернативный(с параметром)
	{}

	void Getter(float& v, double& m, int& h, string& n, string& g);
	void Getter(float& v, string& n, string& g);
	double GetMass(double& m);
	int GetHeight(int& h); //метод для получения роста
	void Setter(float v, int h, double m, string n, string g);
	void Show()
	{
		cout << "Человек: " << "\n"
			<< "Возраст = " << Vozr << '\n'
			<< "Рост = " << Height << '\n'
			<< "Вес = " << Mass << '\n'
			<< "Имя = " << Name << '\n'
			<< "Пол = " <<  Gender << '\n';
		ofstream fout("info2.txt");
		fout << "Человек: " << "\n"
			<< "Возраст = " << Vozr << '\n'
			<< "Рост = " << Height << '\n'
			<< "Вес = " << Mass << '\n'
			<< "Имя = " << Name << '\n'
			<< "Пол = " << Gender << '\n';
	}
};
double Animal::GetMass(double& m) //описание методов
{
	m = Mass;
	return m;
}
void Animal::Getter(float v, int& h, string& n, string& g, string& t, string& c)
{
	v = Vozr;
	h = Height;
	n = Name;
	g = Gender;
	t = Type;
	c = Color;
}
void Animal::Setter(float v, int h, double m, string n, string g, string t, string c)
{
	Vozr = v;
	Height = h;
	Mass = m;
	Name = n;
	Gender = g;
	Type = t;
	Color = c;
}
void Human::Getter(float& v, string& n, string& g)
{
	v = Vozr;
	n = Name;
	g = Gender;
}
int Human::GetHeight(int& h)
{
	h = Height;
	return h;
}
double Human::GetMass(double& m)
{
	m = Mass;
	return m;
}
void Human::Setter(float v, int h, double m, string n, string g)
{
	Vozr = v;
	Height = h;
	Mass = m;
	Name = n;
	Gender = g;
}
Human::Human()
{
	Setter(15, 167, 60, "Kaneki", "Male");
}
Animal::Animal()
{
	Setter(5, 50, 10, "Yantarik", "Male", "Pomeranian", "Orange");
}
double operator+(Human FirstHuman, Animal FirstAnimal)
{
	double m;
	double mas[2];
	mas[0] = FirstHuman.GetMass(m);
	mas[1] = FirstAnimal.GetMass(m);
	double s = mas[1] + mas[0];
	return s;
};
int main()
{
	double m;
	setlocale(LC_ALL, "ru");
	Human FirstHuman;
	Animal FirstAnimal;
	double mas[2];
	mas[0] = FirstHuman.GetMass(m); //создание массива с массой
	mas[1] = FirstAnimal.GetMass(m);
	FirstAnimal.Show();
	FirstHuman.Show();
	if (mas[0] < mas[1])
		cout << "Животное весит больше";
	if (mas[1] < mas[0])
		cout << "Человек весит больше";
}