#include <date.h>
#include <charconv>
#include <sstream>
#include <iomanip>

const std::vector<std::string> Date::_numberToMonth = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

unsigned char Date::monthToNumber(std::string_view month) {
    for(unsigned char i = 0; i < _numberToMonth.size(); ++i) {
        if (_numberToMonth[i] == month) {
            return i;
        }
    }
    return -1;
}

const std::string& Date::numberToMonth(unsigned char month) {
    return _numberToMonth[month];
}

Date::Date(std::string_view date) {
    _month = monthToNumber(date.substr(0, 3));
    std::from_chars<unsigned char>(date.data() + 4, date.data() + 4 + 2, _day);
    std::from_chars<unsigned char>(date.data() + 7, date.data() + 7 + 2, _hours);
    std::from_chars<unsigned char>(date.data() + 10, date.data() + 10 + 2, _minutes);
    std::from_chars<unsigned int>(date.data() + 13, date.data() + 13 + 4, _year);
}

std::string Date::toString() const {
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(2) << numberToMonth(_month) << '-' << 
            std::setfill('0') << std::setw(2) << (unsigned int)_day << ' ' << 
            std::setfill('0') << std::setw(2) << (unsigned int)_hours << ':' << 
            std::setfill('0') << std::setw(2) << (unsigned int)_minutes << ' '  << 
            std::setfill('0') << std::setw(4) << _year;
    return ss.str();
}

bool Date::operator <(const Date& rhs) const {
    return (_year < rhs._year) || (_year == rhs._year) && (
                (_month < rhs._month) || (_month == rhs._month) && (
                    (_day < rhs._day) || (_day == rhs._day) && (
                        (_hours < rhs._hours) || (_hours == rhs._hours) && (
                            (_minutes < rhs._minutes)
                        )
                    )
                )
            );
}