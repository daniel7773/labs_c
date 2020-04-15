// Лабораторная 7, функция нахождения синуса и косинуса угла


#include <iostream>
#include <math.h>
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

void getSinCos(int& a){
  cout << "sin: " << sin(a) << "\n";
  cout << "cos: " << cos(a) << "\n";
}

void enterVar(){
  int a;
  cout << "Рассчитать синус и косинус угла, введите угол:\n";
  cout << "enter a: \n"; cin >> a;
  getSinCos(a);
  isEnd();
}

int main() {
  while (true) {
    enterVar();
  }

  return 0;
}
