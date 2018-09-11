#ifndef PARSER_INCLUDED
#define PARSER_INCLUDED

#include "Person.h"
#include "Month.h"
#include <fstream>
#include <string>
#include <cctype>
#include <unordered_set>
#include <map>
#include <list>

class Parser
{
public:
    Parser(string separators);
    list<Person> parse(const string& filename) const;
private:
    bool isSeparator(const char& ch) const;
    unordered_set<char> m_separators;
    map<string, int> m_months;
};

Parser::Parser(string separators)
{
    for (int i = 0; i < separators.length(); i++)
        m_separators.emplace(separators[i]);
    m_months.emplace("january",   1);
    m_months.emplace("february",  2);
    m_months.emplace("march",     3);
    m_months.emplace("april",     4);
    m_months.emplace("may",       5);
    m_months.emplace("june",      6);
    m_months.emplace("july",      7);
    m_months.emplace("august",    8);
    m_months.emplace("september", 9);
    m_months.emplace("octomber", 10);
    m_months.emplace("november", 11);
    m_months.emplace("december", 12);
}

// Expect each line to be of the form
//   "Name    Month    Day"
list<Person> Parser::parse(const string& filename) const
{
    list<Person> output;
    
    ifstream infile(filename);
    string line;
    while (getline(infile, line))
    {
        int i = 0;
        string name;
        string month;
        int day = 0;
        for (; !isSeparator(line[i]); i++)
            name += line[i];
        while (isSeparator(line[i]))
            i++;
        for (; !isSeparator(line[i]); i++)
            month += tolower(line[i]);
        while (isSeparator(line[i]))
            i++;
        for (; i < line.length(); i++)
        {
            day *= 10;
            day += line[i] - '0';
        }
        output.push_back(Person(name, m_months.find(month)->second, day));
    }
    return output;
}

bool Parser::isSeparator(const char& ch) const
{
    if (m_separators.find(ch) != m_separators.end())
        return true;
    return false;
}

#endif
