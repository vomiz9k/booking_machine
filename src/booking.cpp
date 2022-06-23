#include <booking.h>


Booking::Booking(const std::string& pax_name, const std::string& _departure_date, std::string_view itineary)
: _pax_name(pax_name), _departure_date(_departure_date) {
    static const std::string delimiter = "->";

    size_t pos = 0;
    std::string token;
    while ((pos = itineary.find(delimiter)) != std::string::npos) {
        token = itineary.substr(0, pos);
        _itineary.push_back(token);
        
        itineary = itineary.substr(pos + delimiter.length());
    }
    _itineary.push_back(itineary.data());
}

const std::string& Booking::getPaxName() const {
    return _pax_name;
}
const Date& Booking::getDate() const {
    return _departure_date;
}

const std::vector<std::string>& Booking::getItineary() const {
    return _itineary;
}

std::string Booking::toString() const {
    std::string result =  _pax_name + " " + _departure_date.toString() + " " + _itineary[0];
    for(size_t i = 1; i < _itineary.size(); ++i) {
        result += "->" + _itineary[i];
    }
    return result;
}
