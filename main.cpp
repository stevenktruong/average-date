#include "Birthday.h"
#include "Person.h"
#include <iostream>
#include <iomanip>
#include <list>
using namespace std;

int main()
{
    Birthday b("/Users/Steven/Documents/GitHub/code-reference/cpp/average-date/bdays.txt");
    list<Person> everyone = b.everyone();
    pair<int, int> avgBirthday = b.average();
    
    int longestName = 0;
    int longestMonth = 0;
    for (list<Person>::iterator i = everyone.begin(); i != everyone.end(); i++)
    {
        string name = i->name;
        string month = b.monthName(i->birthMonth);
        if (name.length() > longestName)
            longestName = name.length();
        if (month.length() > longestMonth)
            longestMonth = month.length();
    }
    
    for (list<Person>::iterator i = everyone.begin(); i != everyone.end(); i++)
    {
        cout << left << setw(longestName+1)  << i->name;
        cout << left << setw(longestMonth+1) << b.monthName(i->birthMonth);
        cout << left << setw(2)              << i->birthDay;
        cout << endl;
    }
    cout << "====================" << endl;
    cout << "The average day is " << b.monthName(avgBirthday.first) << " " << avgBirthday.second << "." <<  endl;
}
