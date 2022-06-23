#pragma once

#include <string>
#include <vector>
#include <date.h>

class Booking {
    std::string _pax_name;
    Date _departure_date;
    std::vector<std::string> _itineary; // Airports codes can be char[3] instead of std::string
    
public:
    Booking(const std::string& pax_name, const std::string& _departure_date, std::string_view itineary);

    const std::string& getPaxName() const;
    const Date& getDate() const;
    const std::vector<std::string>& getItineary() const ;

    std::string toString() const;
};
