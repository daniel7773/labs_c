// Лаборатораня 10, упражнение 3
// Создайте структуру в структуре

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

struct RoomStruct
{
  string flatNumber;
  int flatSquare;
  string roomsNumber;

};

struct FlatStruct
{
  string surname;
  string number_floor;
  RoomStruct roomInfo;
};



FlatStruct getFlat(string surname, string flatNumber, int flatSquare, string roomsNumber, string floor);
void showMin(vector<FlatStruct> flats);
void showMax(vector<FlatStruct> flats);
void showFlat(FlatStruct flat, string messege);
// utils
int getArrSize(int arr[]);

int main()
{
  vector<FlatStruct> flats;
  string surname;
  string flatNumber;
  int flatSquare;
  string roomsNumber;
  string floor;
  for(int i = 0; i < 3; i++ ) {
    cout << "Введите данные о квартире: "; cout << endl;
    cout << "Фамилия владельца: "; cin >> surname;
    cout << "Номер квартиры: "; cin >> flatNumber;
    cout << "Площадь квартиры: "; cin >> flatSquare;
    cout << "Число комнат: "; cin >> roomsNumber;
    cout << "Этаж: "; cin >> floor;
    FlatStruct flat = getFlat(surname, flatNumber, flatSquare, roomsNumber, floor);
    flats.push_back(flat);
    cout << endl;
  }
  showMin(flats);
  showMax(flats);
  return 0;
}

FlatStruct getFlat(string surname, string flatNumber, int flatSquare, string roomsNumber, string floor)
{
    FlatStruct flat;
    flat.surname = surname;
    flat.number_floor = floor;
    flat.roomInfo.flatNumber = flatNumber;
    flat.roomInfo.flatSquare = flatSquare;
    flat.roomInfo.roomsNumber = roomsNumber;
    return flat;
}

void showMin(vector<FlatStruct> flats) {
    FlatStruct flat = flats[0];
    for(FlatStruct localFlat: flats){
        if(localFlat.roomInfo.flatSquare < flat.roomInfo.flatSquare){
            flat = localFlat;
        }
    }
    showFlat(flat, "Данные о квартире с самой маленькой площадью:");
}

void showMax(vector<FlatStruct> flats){
FlatStruct flat = flats[0];
    for(FlatStruct localFlat: flats){
        if(localFlat.roomInfo.flatSquare > flat.roomInfo.flatSquare){
            flat = localFlat;
        }
    }
    showFlat(flat, "Данные о квартире с самой большой площадью:");
}

void showFlat(FlatStruct flat, string firstMessege){
    cout << firstMessege << endl;
    cout << "Фамилия владельца: " << flat.surname << endl;
    cout << "Номер квартиры: " << flat.roomInfo.flatNumber << endl;
    cout << "Площадь квартиры: " << flat.roomInfo.flatSquare << endl;
    cout << "Число комнат: " << flat.roomInfo.roomsNumber << endl;
    cout << "Этаж: " << flat.number_floor << endl;
}

void bubbleSort(vector<int>& a)
{
      bool swapp = true;
      while(swapp){
        swapp = false;
        for (size_t i = 0; i < a.size()-1; i++) {
            if (a[i]>a[i+1] ){ // поменять знак с > на < для сортировки по убыванию
                a[i] += a[i+1];
                a[i+1] = a[i] - a[i+1];
                a[i] -=a[i+1];
                swapp = true;
            }
        }
    }
}








