#pragma once

#include <string>
#include <vector>

class Date {
    unsigned char _hours;
    unsigned char _minutes;
    unsigned char _month;
    unsigned char _day;
    unsigned int _year;

    static const std::vector<std::string> _numberToMonth;
    static unsigned char monthToNumber(std::string_view month);
    static const std::string& numberToMonth(unsigned char month);

public:
    Date(std::string_view date);
    std::string toString() const;
    bool operator <(const Date& rhs) const;
};