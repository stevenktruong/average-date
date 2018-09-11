#ifndef BIRTHDAY_INCLUDED
#define BIRTHDAY_INCLUDED

#include "Person.h"
#include "Parser.h"
#include <list>
#include <string>
#include <iostream>
using namespace std;

class Birthday
{
public:
    Birthday(const string& filename);
    pair<int, int> average();
    list<Person> everyone();
    string monthName(int number) { return m_months[number]; }
private:
    Parser m_parser;
    list<Person> m_people;
    map<int, string> m_months;
    map<int, int> m_days;
};

Birthday::Birthday(const string& filename)
: m_parser(" ")
{
    m_people = m_parser.parse(filename);
    
    // Map from month number to its name
    m_months.emplace(1,  "January");
    m_months.emplace(2,  "February");
    m_months.emplace(3,  "March");
    m_months.emplace(4,  "April");
    m_months.emplace(5,  "May");
    m_months.emplace(6,  "June");
    m_months.emplace(7,  "July");
    m_months.emplace(8,  "August");
    m_months.emplace(9,  "September");
    m_months.emplace(10, "October");
    m_months.emplace(11, "November");
    m_months.emplace(12, "December");
    
    // Days in each month
    m_days.emplace(1, 31);
    m_days.emplace(2, 28);
    m_days.emplace(3, 31);
    m_days.emplace(4, 30);
    m_days.emplace(5, 31);
    m_days.emplace(6, 30);
    m_days.emplace(7, 31);
    m_days.emplace(8, 31);
    m_days.emplace(9, 30);
    m_days.emplace(10, 31);
    m_days.emplace(11, 30);
    m_days.emplace(12, 31);
}

pair<int, int> Birthday::average()
{
    // January 1st = 1
    // January 2nd = 2
    // etc.
    double total = 0;
    for (list<Person>::iterator i = m_people.begin(); i != m_people.end(); i++)
    {
        for (int j = 1; j < i->birthMonth; j++)
            total += m_days[j];
        total += i->birthDay;
    }
    
    double average = total / m_people.size();
    int current = 1; // Start at January
    while (average - m_days[current] > 0)
    {
        average -= m_days[current];
        current++; // Increment month
    }
    
    int avgMonth = current;
    int avgDay = average;
    if (avgDay == 0)
        avgDay = 1;
    return pair<int,  int>(avgMonth, avgDay);
}

list<Person> Birthday::everyone()
{
    list<Person> copy = m_people;
    return copy;
}

#endif
