// Лабораторная 11, 2 упражнение
// Реализуйте класс Person, поддерживающий историю изменений человеком своих
// фамилии и имени.

#include <exception>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Person {
   public:
    void ChangeFirstName(int year, const string& first_name) {
        try {
            firstNameHistory[year].push_back(first_name);
        } catch (exception& err) {
            cout << "Ошибка при обновлении имени";
        }
    }

    void ChangeLastName(int year, const string& last_name) {
        try {
            lastNameHistory[year].push_back(last_name);
        } catch (exception& err) {
            cout << "Ошибка при обновлении фамилии";
        }
    }

    bool hasFirstName(int year) {
        map<int, vector<string>>::iterator itr = firstNameHistory.begin();
        while (itr != firstNameHistory.end()) {
            if (year >= itr->first) {
                return true;
            }
            ++itr;
        }
        return false;
    }

    bool hasLastName(int year) {
        map<int, vector<string>>::iterator itr = lastNameHistory.begin();
        while (itr != lastNameHistory.end()) {
            if (year >= itr->first) {
                return true;
            }
            ++itr;
        }
        return false;
    }

    string getFirstName(int year) {
        try {
            map<int, vector<string>>::iterator itr = firstNameHistory.begin();
            int lastYear = 0;
            string firstName = "with unknown first name";
            while (itr != firstNameHistory.end()) {
                if (year >= itr->first && year > lastYear) {
                    if (!(itr->second.empty())) {
                        firstName = itr->second[0];
                    }
                }
                ++itr;
            }
            return firstName;
        } catch (exception& err) {
            return "Ошибка при получении имени";
        }
    }

    string getLastName(int year) {
        try {
            map<int, vector<string>>::iterator itr = lastNameHistory.begin();
            int lastYear = 0;
            string lastName = " with unknown last name";
            while (itr != lastNameHistory.end()) {
                if (year >= itr->first && year > lastYear) {
                    if (!(itr->second.empty())) {
                        lastName = itr->second[0];
                    }
                }
                ++itr;
            }
            return lastName;
        } catch (exception& err) {
            return "Ошибка при получении фамилии";
        }
    }

    string GetFullName(int year) {
        if (hasFirstName(year) || hasLastName(year)) {
            return getFirstName(year) + " " + getLastName(year);
        } else {
            return "Incognito";
        }
    }

   private:
    map<int, vector<string>> firstNameHistory;
    map<int, vector<string>> lastNameHistory;
};

int main() {
    Person person;
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Marina");

    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");

    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }
    return 0;
}