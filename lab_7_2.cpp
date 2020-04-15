// Лабораторная 7, функция расставляющая три числа по порядку


#include <iostream>
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

void setOrder(int& a, int& b, int& c){
   if(a > b) {
     if(a > c) {
       cout << b << c << a;
     } else {
       cout << b << a << c;
     }
   } else {
     if(b > c) {
       cout << a << c << b;
     } else {
       cout << a << b << c;
     }
   }
}

void enterVar(){
  int a, b, c;
  cout << "enter a: \n"; cin >> a;
  cout << "enter b: \n"; cin >> b;
  cout << "enter c: \n"; cin >> c;
  setOrder(a, b, c);
  isEnd();
}

int main() {
  while (true) {
    enterVar();
  }

  return 0;
}
