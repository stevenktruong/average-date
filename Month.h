#ifndef MONTH_INCLUDED
#define MONTH_INCLUDED

struct Month
{
    Month(string name, int number, int days) : name(name), number(number), days(days) {}
    string name;
    int number;
    int days;
};

#endif
