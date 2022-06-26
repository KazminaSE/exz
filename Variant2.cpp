#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Bird
{
private:
    string Sex;
    string Color;
    int Mass;
    double v; // v - возраст по задаче
    //закрытые переменные
public:

    Bird()
    {
        Mass = 0;
    }// конструктор
    Bird(int m)
    {
        Mass = m;
    }
    virtual ~Bird() {}// диструктор
    int GetM() const
    {
        return Mass;
    }
    string GetSex() const
    {
        return Sex;
    }
    string GetColour() const
    {
        return Color;
    }
    double GetV() const
    {
        return v;
    } // методы Get...

    void Show()// функция вывода из класса
    {
        cout << "Птица: " << "\n"
            << "Возраст = " << v << '\n'
            << "Вес = " << Mass << '\n'
            << "Пол = " << Sex << '\n'
            << "Окрас = " << Color << '\n';// вывод на экран
        ofstream fout("info2.txt");
        fout << "Птица: " << "\n"
            << "Возраст = " << v << '\n'
            << "Вес = " << Mass << '\n'
            << "Пол = " << Sex << '\n'
            << "Окрас = " << Color << '\n';// создание файла и перенос информации в него
    }
    /* void Sum() // перегрузка оператора через функцию
     {
         int s = Mass++;
         cout << s;
     }*/
    Bird operator +(Bird ob) //перегрузка оператора бинарный '+'
    {
        return Mass + ob.Mass;
    };
};

class Info :public Bird //наследование доп. информации от класса птицы
{
protected:
    double Growth;
public:
    Info() :Bird()
    {
    }
    Info(int m, double g) :Bird(m)
    {
        Growth = g;
    }
    ~Info()
    {
    }
    double GetGgrowth() const
    {
        return Growth;
    }
    void Show() { // функция доп. информации
        cout << "Рост = " << Growth << '\n';// вывод на экран
        ofstream fout("info2.txt");
        fout << "Рост = " << Growth << '\n';//создание файла и перенос информации в него
    }

};



int main()
{
    setlocale(LC_ALL, "ru");


    Info a(12, 1);
    a.Show();
    Info a1(11, 3);
    a1.Show();
    Bird b1(5), b2(3);
    Bird b3;
    b3 = b1 + b2;
    b3.Show();

}

