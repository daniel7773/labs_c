// лабораторная работа 3, упражнение 2
// вычисление таблицы (x, f) значений функции f(x)-ax2+bx+c
#include <string>
#include <iostream>

using namespace std;

int countFunc(int a, int b, int c, int x){
  return (int(a*(x*x) + b*x + c));
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

void countFor(int a, int b, int c, int start, int end, int step){
  cout << "Таблица (x, f) значений функции " << a << "x" << "^2+(" << b << ")" << start
   << "+(" << c <<")\n";
   int sum = 0;
  for (size_t x = start; x <= end; x+=step) {
    cout << "x=" << x << " f(x)=" << countFunc(a, b, c, x) <<"\n";
    if(sum + countFunc(a, b, c, x) < 20){
      sum += countFunc(a, b, c, x);
    }
  }
  cout << "Сумма значений функции, меньших 20: " << sum;
  isEnd();
}

void countWhile(int a, int b, int c, int start, int end, int step){
  cout << "Таблица (x, f) значений функции " << a << "x" << "^2+(" << b << ")" << start
   << "+(" << c <<")\n";
   int x = start;
   int sum = 0;
   while (end >= x) {
     cout << "x=" << x << " f(x)=" << countFunc(a, b, c, x) <<"\n";
     if(sum + countFunc(a, b, c, x) < 20){
       sum += countFunc(a, b, c, x);
     }
     x+=step;
   }
  cout << "Сумма значений функции, меньших 20: " << sum;
  isEnd();
}

void countDoWhile(int a, int b, int c, int start, int end, int step){
  cout << "Таблица (x, f) значений функции " << a << "x" << "^2+(" << b << ")" << start
   << "+(" << c <<")\n";
   int sum = 0;
   int x = start;
   do {
     cout << "x=" << x << " f(x)=" << countFunc(a, b, c, x) <<"\n";
     if(sum + countFunc(a, b, c, x) < 20){
       sum += countFunc(a, b, c, x);
     }
     x+=step;
   } while(end >= x);
  cout << "Сумма значений функции, меньших 20: " << sum;
  isEnd();
}

void enterStep(int a, int b, int c, int start, int end){
  int n;
  cout << "\nВведите шаг изменения x: n "; cin >> n;
  if(n > end - start){
    cout << "n больше допустимого значения, попробуйте снова\n ";
    enterStep(a, b, c, start, end);
  } else {
    countWhile(a, b, c, start, end, n);
  }
}

void enterBorders(int a, int b, int c){
  int y,z;
  cout << "y="; cin >> y;
  cout << "z="; cin >> z;
  if (y <= z) {
    cout << "Введенный диапазон " << "y: " << y <<", z: " << z;
    cout << "\nшаг изменения x должен быть меньше " << z-y;
    enterStep(a, b, c, y, z);
  } else {
    cout << "Введенный диапазон " << "z: " << z <<", y: " << y;
    cout << "\nшаг изменения x должен быть меньше " << y-z;
    enterStep(a, b, c, z, y);
  }

}

void enterVars(){
  int a,b,c;

  cout << "a="; cin >> a;
  cout << "b="; cin >> b;
  cout << "c="; cin >> c;
  cout << "Введенные значения: " << "a: " << a <<", b: " << b << ", c: "
  << c << "\nВведите диапазоны изменения y и z\n";
  enterBorders(a, b, c);
}

int main(){
  while(true) {
    enterVars();
  }
return 0;
}
