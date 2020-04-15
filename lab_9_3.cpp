// Лабораторная 9, 3 упражнение
// Очень замороченное задание

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

void handleRequest(string line);
void createTemp(string details);
void deleteTemp(string details);
void showDayInfo(string details);
void showWeekInfo();
void showOverDays(string details);
void deleteDay(string details);

string getKey(string details);
vector<int> getValues(string details);
int getValue(string details);
int getMiddleTemp(vector<int> temps);
vector<string> alphabaticallySort(vector<string> a);
bool mycomp(string a, string b);

map <string, vector<int>> miniDb;

int main()
{
  string smth;
    while (true) {
      cout << "\nВведите что-то\n"; getline(cin, smth);
      handleRequest(smth);
    }
}

void handleRequest(string line){
  int spac = line.find(' ' , 0); // first space position

  string comand = line.substr(0, spac);
  string details = line.substr(spac+1, line.size());

  if(comand == "NEW_TEMP") { // добавление нового значения температуры для конкретного дня недели
    createTemp(details);
  } else if(comand == "DEL_TEMP"){ // удалить значение температуры в определенный день недели
    deleteTemp(details);
  } else if(comand == "DAY_OF_WEEK"){ // вывод всех значений температуры в определенный день недели
    showDayInfo(details);
  } else if(comand == "WEEK"){ // вывод всех значений температуры во все дни
    showWeekInfo();
  } else if(comand == "MEAN"){ // дни недели в которые среднее значение выше средней температуры
    showOverDays(details);
  } else if(comand == "DEL_DAY"){ // удалить целый день
    deleteDay(details);
  } else {
    cout << "Unknown comand";
  }
}

void createTemp(string details){
  string key  = getKey(details);
  vector<int> temps = getValues(details);
  miniDb.find(key);
  if(!miniDb.count(key)) {
    cout << "No temp on this day of the week\n";
  }
  miniDb[key] = temps;
  cout << "Заметка создана\n";
}

void deleteTemp(string details){
  bool notContain = true;
  string key  = getKey(details);
    int int_to_remove = getValue(details);

  if (!miniDb.count(key)){
    cout << "No day of week";
    return;
  }

  vector<int> vec = miniDb[key];
  vector <int>::iterator i = vec.begin ();

   while (i != vec.end ()){
       if(int_to_remove == *i) {
         vec.erase(i);
         notContain = false;
       }
       ++ i;
   }

   if(notContain) {
     cout << "No temp";
   }
   miniDb[key] = vec;
}

void showDayInfo(string details){
  string key = getKey(details);
  cout << "Дневные температуры принимают следующие значения:\n";
  if (!miniDb.count(key)){
    cout << "No day of week";
    return;
  }
  if(miniDb[key].size() == 0){
    cout << "No temp of the week:\n";
    return;
  }
   for (int i: miniDb[key]) {
     cout << i << " ";
   }
   cout << "\n";
}

void showWeekInfo(){
  vector<string> days;
  if(miniDb.size() > 0) {
    for (auto const& x : miniDb)
    {
      days.push_back(x.first);
    }
    days = alphabaticallySort(days);
    for(string day: days) {
      cout << day << ": ";
      for(int i: miniDb[day]) {
        cout << i << " ";
      }
      cout << endl;
    }
  } else {
    cout << "No temp of the week";
  }
}

bool mycomp(string a, string b){
	//returns 1 if string a is alphabetically
	//less than string b
	//quite similar to strcmp operation
	return a<b;
}

vector<string> alphabaticallySort(vector<string> a){
	int n=a.size();
	//mycomp function is the defined function which
	//sorts the strings in alphabatical order
	sort(a.begin(),a.end(),mycomp);
	return a;
}


void showOverDays(string details){
  int value = getValue(details);
  std::map<string, vector<int>>::iterator itr = miniDb.begin();
  while (itr != miniDb.end()) {
    int mid = getMiddleTemp(itr->second);
    if(mid > value){
      cout << itr->first << endl;
      for ( int i: miniDb[itr->first]) {
        cout << i << " ";
      }
    }
    ++itr;
  }
}

void deleteDay(string details) {
  string key = getKey(details);
  if (!miniDb.count(key) || miniDb.size() == 0){
    cout << "No day of week";
    return;
  }
  std::map<string, vector<int>>::iterator itr = miniDb.begin();
  while (itr != miniDb.end()) { // will not work if only 1 element in map
    if (itr->first == key) {
       itr = miniDb.erase(itr);
       cout << "Delete " << key;
    }
    ++itr;
  }
}

string getKey(string details){
  string key = details.substr(0, details.find(' ' , 0));
  return key;
}

// a bit hacky, sorry
vector<int> getValues(string details){ // https://ru.stackoverflow.com/questions/795850/Как-числа-из-строки-записать-в-массив-целых-чисел-Числа-в-строке-разделены-стро
  vector<int> newTemps = {0}; // инициализация массива

  string usefullLine = details.substr(details.find(' ' , 0)+1, details.size()); // отделим ключ от значений

    for (int i = 0; i < (int)usefullLine.size(); ++i) {
        if (usefullLine[i] == ' ') {
            newTemps.push_back(0); // при пробеле, поймем, что началось новое число
        } else {
            newTemps.back() *= 10;
            newTemps.back() += ((int)usefullLine[i] - '0'); // добавили новую цифру числа
        }
    }
    cout << "Набор температур: ";
    for (int element : newTemps) {
        cout << element << " "; // выводим числа из массива через пробел
    }
    cout << "\n";
  return newTemps;
}

int getValue(string details) {
    string usefullLine = details.substr(details.find(' ' , 0)+1, details.size()); // отделим ключ от значений
    return stoi( usefullLine );
}


int getMiddleTemp(vector<int> temps){
  int sum = 0;
  for(int i: temps) {
    sum+=i;
  }
  return sum/temps.size();
}
