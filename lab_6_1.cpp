// лабораторная работа 6
// Функция №1 для решения квадратного уравнения вида f(x)=a*x2+b*x+с;
// функцию №2 для возведения числа степень n>0
// функцию №3 для определения факториала числа n.
// функцию №4 для вычисления логарифма произвольного основания logxy= lоg(x)/ lоg(y).
// и вычисление факториала, ну это совсем просто

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

void lineFunc(){
  double a, b, x;
  cout << "Решение линейного уравнения вида f(x)=a*x+b" << '\n';
  cout << "Введите значение a="; cin >> a; cout << '\n';
  cout << "Введите значение b="; cin >> b; cout << '\n';
  cout << "Введите значение x="; cin >> x; cout << '\n';

  cout <<  a * x + b;
}

void quadroFunc(){
  double a, b, c, x;
  cout << "Решение квадратного уравнения вида f(x)=a*x^2+b*x+c" << '\n';
  cout << "Введите значение a="; cin >> a; cout << '\n';
  cout << "Введите значение b="; cin >> b; cout << '\n';
  cout << "Введите значение c="; cin >> c; cout << '\n';
  cout << "Введите значение x="; cin >> x; cout << '\n';

  cout <<  a * x*x + b * x + c;
}

double exp(double x, double n){
  if(n == 0){
    return 1;
  }
  if((((int)n) % 2) == 0){
    return exp(x*x, n / 2);
  }
  return x * exp(x, n - 1);
}

void showExp(){
  double x, n;
  cout << "Возведения числа x в степень n" << '\n';
  cout << "Введите значение x="; cin >> x; cout << '\n';
  cout << "Введите значение n="; cin >> n; cout << '\n';

  cout << exp(x, n);
}

double factorial(double n){
  if (n==0) return  1;
  else return  n*factorial(n-1);
}

void showFactorial(){
  double n;
  cout << "Определение факториала числа" << '\n';
  cout << "Введите значение n="; cin >> n; cout << '\n';

  cout << factorial(n);
}

void log(){
  double a, b, res;
  cout << "Вычисление логарифма произвольного основания" << '\n';
  cout << "Введите значение a="; cin >> a; cout << '\n';
  cout << "Введите значение b="; cin >> b; cout << '\n';

  if (b==1 || b<0)
  {
    cout << "incorrect b value" << '\n';
  } else if (a<0)
  {
    cout << "incorrect a value" << '\n';
  } else  {
    res = log(a) / log(b);
    cout << res;
  }
}

void chooseFunc() {
  int a = 0;

  cout << "Выберите вариант задачи:\n";
  cout << "1-  Решение линейного уравнения;\n";
  cout << "2-  Решение квадратного уравнения;\n";
  cout << "3-  Возведение числа в степень;\n";
  cout << "4-  Вычисление факториала;\n";
  cout << "5-  Вычисление логарифма произвольного основания.\n\n";
  cin >> a;

  switch (a)
  {
    case 1:
    {
      lineFunc();
      break;
    }
    case 2:
    {
      quadroFunc();
      break;
    }
    case 3:
    {
      showExp();
      break;
    }
    case 4:
    {
      showFactorial();
      break;
    }
    case 5:
    {
      log();
      break;
    }

    default:
    {
      cout << "incorrect input, it should be int value on a segment from 1 to 5 : " << a << '\n';
    }
  }
  isEnd();
}


int main()
{
  while (true) {
    chooseFunc();
  }
  return 0;
}
