#include <string>
#include <vector>
#include <iostream>

#include <booking_machine.h>

int main() {
    std::vector<Booking> bookings = {
        {"Alice", "May-26 06:45 2020", "LHR->AMS"},
        {"Bruce", "Jun-04 11:04 2020", "GVA->AMS->LHR"},
        {"Cindy", "Jun-06 10:00 2020", "AAL->AMS->LHR->JFK->SFO"},
        {"Derek", "Jun-12 08:09 2020", "AMS->LHR"},
        {"Erica", "Jun-13 20:40 2020", "ATL->AMS->AAL"},
        {"Fred", "Jun-14 09:10 2020", "AMS->CDG->LHR"}
    };

    BookingMachine machine;

    for(const auto& booking: bookings) {
        machine.addBooking(booking);
    }

    std::cout << "Selected bookings before Jun-12 08:09 2020:\n";
    auto before = machine.selectBefore({"Jun-12 08:09 2020"});
    for(const auto& booking: before) {
        std::cout << booking.toString() << '\n';
    }
    std::cout << '\n';

    std::cout << "Selected bookings visiting AMS->LHR:\n";
    auto thisway = machine.selectVisiting("AMS", "LHR");
    for(const auto& booking: thisway) {
        std::cout << booking.toString() << '\n';
    }
}

