// лабораторная работа 3, упражнение 3
// нахождение НОД по алгоритму Евклида
#include <string>
#include <iostream>

using namespace std;

void findRemainder(int a, int b);
void compareValues(int a, int b);

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

void findRemainder(int a, int b)
{
  if(a==0 || b ==0) {
    cout << "НОД: 0" << '\n';
    isEnd();
    return;
  }
  if(a%b==0) {
    cout << "НОД: " << abs(b) << '\n';
    isEnd();
  } else {
    compareValues(a%b, b);
  }
}

void compareValues(int a, int b)
{
  if(a > b) {
    findRemainder(a, b);
  } else {
    findRemainder(b, a);
  }
}

void enterVars()
{
  int a,b;

  cout << "Введите 2 числа: " << '\n';
  cout << "a="; cin >> a;
  cout << "b="; cin >> b;
  cout << "Введенные значения: " << "a: " << a <<", b: " << b << '\n';
  compareValues(a, b);
}

int main()
{
  while(true) {
    enterVars();
  }
return 0;
}
