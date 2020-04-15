// лабораторная работа 3, упражнение 1
// программа возврщающая сумму нечетных членов на отрезке от a до b, где a и b - целые числа
#include <string>
#include <iostream>
#include <exception>

using namespace std;

double countVarsFor(int start_value, int end_value){
  int sum = 0;
  for (int i = start_value; i <= end_value; i++) {
    i%2==0 ? sum+=0 : sum+=i;
  }
  return sum;
}

double countVarsWhile(int start_value, int end_value){
  int sum = 0;
  while (start_value <= end_value) {
    start_value%2==0 ? sum+=0 : sum+=start_value;
    start_value++;
  }
  return sum;
}

double countVarsDoWhile(int start_value, int end_value){
  int sum = 0;
  do {
    start_value%2==0 ? sum+=0 : sum+=start_value;
    start_value++;
  } while(start_value <= end_value);
  return sum;
}

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

void showVars(int a, int b){
   a > b ? cout << "Сумма нечетных чисел от " << b << " до " << a << ": " << countVarsDoWhile(b, a):
   cout << "Сумма нечетных чисел от " << a << " до " << b << ": " << countVarsDoWhile(a, b);
   isEnd();
}

void enterVars(){
  int a,b;
  cout << "a="; cin >> a;
  cout << "b="; cin >> b;
  showVars(a,b);
}

int main(){
  while(true) {
    enterVars();
  }
return 0;
}
