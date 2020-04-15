// лабораторная работа 6
// Вывод цифры 5
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

void zvezda(){
  cout << "*";
}

void probel6(){
  cout << "      ";
}

void someFunc(){
  int i, j;
  for (j = 0; j < 9; j++)
  {
    for (i = 0; i < 7; i++)
    {
      if (j == 0||j==4|| j==8)
      {
        zvezda();
      }
      if (i == 0 && j > 0 && j < 4)
      {
        zvezda();
      }
      if (i == 6 && j > 4 && j < 8)
      {
        probel6();
        zvezda();
      }
    }
    cout << "\n";
  }
  isEnd();
}

int main()
{
  while (true) {
    someFunc();
  }
  return 0;
}
