// Лабораторная 7, функция меняющая порядок следования цифр целого числа


#include <iostream>
#include <string>
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

void print_strrev( char * buf ){
    if (*buf) {
        print_strrev(buf + 1);
        std::cout << *buf;
    }
}

void enterVar(){
  int a;
  cout << "enter number: \n"; cin >> a;
  char str[99];
   sprintf(str, "%d", a);

  print_strrev(str);
    std::cout << std::endl;
    isEnd();
}

int main() {
  while (true) {
    enterVar();
  }

  return 0;
}
