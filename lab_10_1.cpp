// Лаборатораня 10, упражнение 1
// Создайте структуру для хранения дробей.
// Структура должна иметь 2 поля: целочисленный числитель и целочисленный знаменатель.

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct VarStruct
{
  double numerator;
  double denominator;

  string multiply(double var1, double var2)
  {
    if(var2==0 || denominator == 0) {
      return "Знаменатель равен 0";
    }
    ostringstream strs;
    strs << (numerator*var1) / (denominator*var2);
    string str = strs.str();
    return str;
  }

  string division(double var1, double var2)
  {
    if(var2==0 || denominator == 0) {
      return "Знаменатель равен 0";
    }
    ostringstream strs;
    strs << (numerator*var2) / (denominator*var1);
    string str = strs.str();
    return str;
  }

  string addition(double var1, double var2)
  {
    if(var2==0 || denominator == 0) {
      return "Знаменатель равен 0";
    }
    ostringstream strs;
    strs << (numerator*var2 + var1*denominator)/(denominator*var2);
    string str = strs.str();
    return str;
  }

  string subtraction(double var1, double var2)
  {
    if(var2==0 || denominator == 0) {
      return "Знаменатель равен 0";
    }
    ostringstream strs;
    strs << (numerator*var2 - var1*denominator)/(denominator*var2);
    string str = strs.str();
    return str;
  }
};

int main()
{
   VarStruct var1;
   VarStruct var2;

    cout << "\nВведите числитель первой дроби: "; cin >> var1.numerator; cout << endl;
    cout << "\nВведите знаменатель первой дроби: \n"; cin >> var1.denominator; cout << endl;
    cout << "\nВведите числитель второй дроби: "; cin >> var2.numerator; cout << endl;
    cout << "\nВведите знаменатель второй дроби: \n"; cin >> var2.denominator; cout << endl;

    cout << var1.multiply(var2.numerator, var2.denominator) << endl; // лучше бы передавать структуру, но в задании параметры такие
    cout << var1.division(var2.numerator, var2.denominator) << endl;
    cout << var1.addition(var2.numerator, var2.denominator) << endl;
    cout << var1.subtraction(var2.numerator, var2.denominator) << endl;

}
