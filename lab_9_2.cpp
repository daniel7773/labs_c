// Лабораторная 9, 2 упражнение
// Даны значения температуры, наблюдавшиеся в течение N подряд идущих дней.
// Вывести на экран консольного приложения значения минимальной и максимальной температуры.
// Отсортировать введенные пользователем значения температуры по убыванию. Вывести на экран консольного приложения.
// Заменить значения температуры, равные среднему на 0. Вывести результат на экран.

#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& a);


int countAverageTemp(vector<int> temperature_vector){
  int sum = 0; // Сумма температур

  for (int temperature : temperature_vector) {
    sum+=temperature;
  }
  return sum/temperature_vector.size();
}

int main()
{
    vector<int> input_vector;

    int counterDay; // кол-во дней
    int average; // Средняя температура
    int min_temp = 1000; // Минимальная температура
    int max_temp = 0; // Максимальная температура
    int valueTemperature;
    vector<int> sorted_vector;

    cout << "Введите количество дней: " << endl;
    cin >> counterDay;

    cout << "Теперь введите значение температуры для каждого дня" << endl;
    for (int i = 1; i <= counterDay; i++)
    {
        cout << "Введите значение температуры для " << i << " дня: ";
        cin >> valueTemperature;
        if(min_temp > valueTemperature){
          min_temp = valueTemperature;
        }
        if(max_temp < valueTemperature){
          max_temp = valueTemperature;
        }
        input_vector.push_back(valueTemperature);
    }

    cout << "Минимальная температура " << min_temp << "\n";
    cout << "Максимальная температура " << max_temp << "\n\n";

    average = countAverageTemp(input_vector);
    sorted_vector = input_vector;
    bubbleSort(sorted_vector);

    for(int i: sorted_vector) {
      cout << i << " ";
    }

    int daysCounter = 0;
    for (int i = 0; i < sorted_vector.size(); i++) {
      if(input_vector[i] == average) {
        input_vector[i] = 0;
        daysCounter++;
      }
    }
    cout << "Всего дней в которые температура равна средней: " << daysCounter << endl;
    cout << "\n\n";

    cout << "После замены температуры на нули" << endl;
    for (int i = 0; i < input_vector.size(); i++) {
      cout << "Температура в " << i+1 << " день ";
      cout << input_vector[i] << endl;
    }
}

void bubbleSort(vector<int>& a)
{
      bool swapp = true;
      while(swapp){
        swapp = false;
        for (size_t i = 0; i < a.size()-1; i++) {
            if (a[i]<a[i+1] ){ // поменять знак с < на > для сортировки по возрастанию
                a[i] += a[i+1];
                a[i+1] = a[i] - a[i+1];
                a[i] -=a[i+1];
                swapp = true;
            }
        }
    }
}
