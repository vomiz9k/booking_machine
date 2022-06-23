#pragma once

#include <vector>
#include <map>
#include <unordered_map>
#include <booking.h>
#include <date.h>

class BookingMachine {
    std::vector<Booking> _bookings; // can be replaced with unordered_map<size_t, Booking> if deletings are needed

    std::multimap<Date, size_t> _dates;
    std::unordered_map<std::string, std::unordered_multimap<std::string, size_t>> _ways; /* can be replaced with 
                        std::unordered_map<std::string, std::unordered_map<std::string, std::vector<Booking>>>,
                        so selectVisiting will return const std::vector& and cost O(1) time*/

public:
    BookingMachine() = default;

    void addBooking(Booking booking);
    std::vector<Booking> selectBefore(const Date& date) const;
    std::vector<Booking> selectVisiting(const std::string& from, const std::string& to) const;
};