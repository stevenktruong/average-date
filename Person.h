#ifndef PERSON_INCLUDED
#define PERSON_INCLUDED

#include <string>
using namespace std;

struct Person
{
    Person() {};
    Person(string name, int month, int day) : name(name), birthMonth(month), birthDay(day) {}
    string name;
    int birthMonth;
    int birthDay;
};

#endif
