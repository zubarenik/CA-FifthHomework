#include <cstring>
#include <iostream>
#include "Thread.h"

#ifndef CA_FIFTHHOMEWORK_HOTEL_H
#define CA_FIFTHHOMEWORK_HOTEL_H


class Hotel : Thread {
private:
    static int amount;

    static const int ROOMS_200 = 10, ROOMS_400 = 10, ROOMS_600 = 10;
    static int occupied_rooms_200, occupied_rooms_400, occupied_rooms_600;

    static void book(int money);

public:
    explicit Hotel(char *argv[]);

    Hotel();

    ~Hotel();

    static void consoleInput();

    static void randomInput();

    static void leave();

    static void init();

    void stop();

    static void result();
};


#endif //CA_FIFTHHOMEWORK_HOTEL_H
