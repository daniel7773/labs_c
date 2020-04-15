// лабораторная работа 6
// Рекурсивные функции
// сумма чисел в интервале(я сделал на отрезке, т.к. думаю что имелся ввиду отрезок, а не интервал)
// возведение числа в указанную степень
// нахождение n-го элемента ряда Фибоначи
#include <iostream>
#include <cmath>

using namespace std;

void isEnd()
{
  cin.clear();
  string s;
  s = "";
  cout << "\ncontinue? y/n\n"; cin >> s;
  if(s == "y") {
     cout << "\n\n";
  } else if( s == "n") {
    cout << "Bye!";
    exit(0);
  } else {
    isEnd();
  }
}

int sum (int a, int b) // сумма чисел на отрезке от a до b
{
  return a > b? 0 : a + sum(a + 1, b);
}

void showSum(){
  int a, b;

  cout << "Вы выбрали нахождение суммы ряда чисел:\n";
  cout << "Введите число a:\n"; cin >> a;
  cout << "Введите число b:\n"; cin >> b;
  cout << "Сумма ряда от " << a << " до " << b << " будет: " << sum(a, b);
}

int pow(int base, int power) // возведение в степень
{
    return power == 1 ? base : base * pow(base, power - 1);
}

void showPow(){
int x, n;

cout << "Вы выбрали n-ой степени числа x:\n";
cout << "Введите число x:\n"; cin >> x;
cout << "Введите степень числа x - n:\n"; cin >> n;
cout << x << " в степени " << n << " это " << pow(x, n);
}

int fib(int a, int b, int counter, int elementNumber)
{
  if(elementNumber <= 0) {
    cout << "element number should be more then zero";
    return -1;
  }
  if(elementNumber == 1 || elementNumber == 2) {
    return 1;
  }
  return (counter < elementNumber-3) ? fib(b, b+a, counter+1, elementNumber) : b; // вычитаем два т.к. первые два члена ряда(единицы) в рассчете не учитываются
}

void showFib(){
int x;

cout << "Вы выбрали вычисление n-го эл-та ряда Фибоначи:\n";
cout << "Введите номер желаемого эл-та:\n"; cin >> x;
cout <<  x << "-ый элемент: " << fib(1, 2, 0, x);
}

void enterVar() {
  int a = 0;

  cout << "Выберите вариант функции:\n";
  cout << "1-  сумма ряда;\n";
  cout << "2-  возведение в степень;\n";
  cout << "3-  нахождение n-го числа в ряде Фибоначи;\n";
  cin >> a;

  switch (a)
  {
    case 1:
    {
      showSum();
      break;
    }
    case 2:
    {
      showPow();
      break;
    }
    case 3:
    {
      showFib();
      break;
    }
    default:
    {
      cout << "incorrect input, it should be int value on a segment from 1 to 3 : " << a << '\n';
      break;
    }
  }
  isEnd();
}

int main()
{
  while (true) {
    enterVar();
  }
  return 0;
}
