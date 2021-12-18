#include "Hotel.h"
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc != 3 && argc != 2) {
        std::cout << "Only 4 arguments can be entered!\n";
        return 0;
    }

    Hotel::init();
    try {
       Hotel new_guests(argv), departing_guests;

       new_guests.stop();
       departing_guests.stop();
    } catch (std::invalid_argument &exception) {
        std::cout << exception.what();
    }
    Hotel::result();

    return 0;
}
