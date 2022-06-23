#include <booking_machine.h>

void BookingMachine::addBooking(Booking booking) {
    size_t id = _bookings.size();
    _bookings.push_back(booking);
    _dates.insert(std::make_pair(booking.getDate(), id));
    std::vector<std::string> itineary = booking.getItineary();

    for(size_t i = 0; i < itineary.size() - 1; ++i) {
        _ways[itineary[i]].insert(std::make_pair(itineary[i + 1], id));
    }
}

std::vector<Booking> BookingMachine::selectBefore(const Date& date) const {
    std::vector<Booking> result;

    auto it = _dates.lower_bound(date);
    if (it != _dates.end()) {
        --it;
        while(it != _dates.begin()) {
            result.push_back(_bookings[it->second]);
            --it;
        }
        result.push_back(_bookings[it->second]);
    }
    return result;
}

std::vector<Booking> BookingMachine::selectVisiting(const std::string& from, const std::string& to) const {
    std::vector<Booking> result;
    auto range = _ways.find(from)->second.equal_range(to);
    for (auto it = range.first; it != range.second; ++it) {
        result.push_back(_bookings[it->second]);
    }
    return result;
}