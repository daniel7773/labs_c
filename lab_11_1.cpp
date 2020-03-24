// Лабораторная 11, 1 упражнение
// Создать класс Complex для работы с комплексными числами.


#include <iostream>
#include <cmath>
#define PI 3.14159

using namespace std;

class Complex{ // x — действительная часть комплексного числа;
               //y — мнимая часть комплексного числа.
    public: double x_ =0;
    double y_ =0;

    Complex(double x, double y) {
        x_ = x;
        y_ = y;
    }

    double countMod(double x, double y){
        return sqrt(x*x+y*y);
    }

    double countArg(double x, double y){
        return atan2(y,x);
    }

    void showComplexNumber(){
        cout << "Комплексное число: " << x_ << y_;
    }

    void showModAndArg(){
        cout << "Модуль комплексного числа: " << countMod(x_, y_) << endl;
        cout << "Аргумент комплексного числа (рад): " << countArg(x_, y_) << endl;
    }
};

int main()
{
    double x;
    double y;

    cout << "Введите целую часть: "; cin >> x;
    cout << "Введите мнимую часть: "; cin >> y;
    Complex complex(x, y);
    complex.showModAndArg();
    
}

