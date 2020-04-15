// Лабораторная 9, 1 упражнение
// Даны значения температуры, наблюдавшиеся в течение N подряд идущих дней.
// Найдите номера дней (в нумерации с нуля) со значением температуры выше среднего арифметического за все N дней.

#include <iostream>
#include <vector>

using namespace std;


int countAverageTemp(vector<int> temperature_vector){
  int sum = 0; // Сумма температур

  for (int temperature : temperature_vector) {
    sum+=temperature;
  }
  return sum/temperature_vector.size();
}

int main()
{
    vector<int> temperature; // температура во все дни
    vector<int> highTemperature; // температура в дни превышающая среднюю
    vector<int> dayNumbers; // номера дней в которые температура превышала заданную, да это можно сделать через hashmap

    int counterDay;
    int valueTemperature;

    int average; // Средняя температура

    cout << "Введите количество дней: " << endl;
    cin >> counterDay;

    cout << "Теперь введите значение температуры для каждого дня" << endl;
    for (int i = 1; i <= counterDay; i++)
    {
        cout << "Введите значение температуры для " << i << " дня: ";
        cin >> valueTemperature;
        temperature.push_back(valueTemperature);
    }

    average = countAverageTemp(temperature);

    for (int i = 0; i < temperature.size(); i++) {
      if(temperature[i] > average) {
        highTemperature.push_back(temperature[i]);
        dayNumbers.push_back(i+1);
      }
    }

    for (int day = 0; day < dayNumbers.size(); day++) {
      cout << "номер дня: " << dayNumbers[day] << " ";
      cout << " температура в этот день - " << highTemperature[day] << endl;
      counterDay++;
    }
}
