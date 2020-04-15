// Лаборатораня 10, упражнение 2
// Создайте структуру с именем STUDENT, содержащую следующие поля:
// NAME – фамилия;
// GROUP – номер группы;
// SES - успеваемость (массив из четырех элементов).

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct StudentStruct
{
  string name;
  string group;
  int ses[4];

  void fillArr(vector<int> vec){
    for(int i = 0; i < (sizeof( ses ) / sizeof( *ses )); i++){
      ses[i] = vec[i];
    }
  }
};

StudentStruct handleInputInfo(string info);
string getGroup(string details);
string getName(string details);
vector<int> getValues(string details);
int studentMean(StudentStruct student);
int studentsMean(vector<StudentStruct> students);
void printVedomost(vector<StudentStruct> students);
void printVedomost4(vector<StudentStruct> students);

// utils
int getArrSize(int arr[]);
vector<int> bubbleSort(vector<StudentStruct> vec);

int main()
{
  vector<StudentStruct> students;
  string smth;
  for(size_t i = 0; i < 5; i++ ) {
    cout << "Введите данные для студента №: "; getline(cin, smth); cout << endl;
    students.push_back(handleInputInfo(smth));
  }

  printVedomost(students);
  printVedomost4(students);

  return 0;
}

StudentStruct handleInputInfo(string info)
{
  StudentStruct student;
  student.name = getName(info);
  student.group = getGroup(info);
  student.fillArr(getValues(info));
  return student;
}

string getName(string details){
  string key = details.substr(0, details.find(' ' , 0));
  return key;
}

string getGroup(string details){
  int spac = details.find(' ' , 0);
  string util = details.substr(spac+1, details.size());
  string group = util.substr(0,  util.find(' ' , 0));
  return group;
}

string getVars(string details){
  int firstSpacePos = details.find(" " , details.find(" " , 0));
  string vars = details.substr(firstSpacePos, details.length());
  return vars;
}


vector<int> getValues(string details){ // https://ru.stackoverflow.com/questions/795850/Как-числа-из-строки-записать-в-массив-целых-чисел-Числа-в-строке-разделены-стро
  vector<int> newTemps = {0};

  int firstSpacePos = details.find(" " , details.find(" " , 0)+1);
  string usefullLine = details.substr(firstSpacePos+1, details.find(" " , firstSpacePos) +1);

    for (int i = 0; i < (int)usefullLine.size(); ++i) {
        if (usefullLine[i] == ' ') {
            newTemps.push_back(0); // при пробеле, поймем, что началось новое число
        } else {
            newTemps.back() *= 10;
            newTemps.back() += ((int)usefullLine[i] - '0'); // добавили новую цифру числа
        }
    }
    cout << "\n";
  return newTemps;
}

int studentMean(StudentStruct student){
  int sum = 0;
  for(int i: student.ses) {
    sum+= i;
  }
  return sum/(sizeof( student.ses ) / sizeof( *student.ses ));
}

int studentsMean(vector<StudentStruct> students){
  int totalSum = 0;
  int marksCounter = 0;
  for(int i = 0; i < students.size(); i++) {
    for(int j = 0; j < (sizeof( students[i].ses ) / sizeof( *students[i].ses )); j++) {
        totalSum += students[i].ses[j];
      marksCounter += 1;
    }
  }
  return totalSum/marksCounter;
}

vector<int> bubbleSort(vector<StudentStruct> students)
{
     bool swapp = true;
  vector<int> a;
  for(int i = 0; i < students.size(); i++) {
    a.push_back(stoi( students[i].group));
  }
      while(swapp){
        swapp = false;
        for (size_t i = 0; i <  a.size()-1; i++) {
            if (a[i]>a[i+1] ){ // поменять знак с > на < для сортировки по убыванию
                a[i] += a[i+1];
                a[i+1] = a[i] - a[i+1];
                a[i] -=a[i+1];
                swapp = true;
            }
        }
    }
    return a;
}

void printVedomost(vector<StudentStruct> students){
  vector<int> sorted = bubbleSort(students);

  int iterator = 0;
  int counter = 0;
  while(counter < sorted.size()) {
    if(sorted[counter] == stoi(students[iterator].group)) {
      cout << students[iterator].name << " " << students[iterator].group;
      for(int i =0; i < (sizeof( students[iterator].ses ) / sizeof( *students[iterator].ses )); i++) {
        cout << " " << students[iterator].ses[i];
      }
      counter++;
      cout << endl;
    } else {
      iterator++;
    }
    if(iterator >= students.size()) {
      iterator = 0;
    }
  }
}

void printVedomost4(vector<StudentStruct> students){
  vector<int> sorted = bubbleSort(students);

  int iterator = 0;
  int counter = 0;
  bool nothingShown = true;
  while(counter < sorted.size()) {
    if(sorted[counter] == stoi(students[iterator].group)) {
      if(studentMean(students[iterator]) > 4) {
        cout << students[iterator].name << " " << students[iterator].group;
        nothingShown = false;
        for(int i =0; i < (sizeof( students[iterator].ses ) / sizeof( *students[iterator].ses )); i++) {
          cout << " " << students[iterator].ses[i];
        }
      } 
      if(nothingShown) {
        cout << "Нет студентов со средней оценкой больше 4";
      }
      counter++;
      cout << endl;
    } else {
      iterator++;
    }
    if(iterator >= students.size()) {
      iterator = 0;
    }
  }
}
