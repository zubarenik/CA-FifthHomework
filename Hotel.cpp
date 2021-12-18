#include "Hotel.h"

void Hotel::book(int money) {
    if (money < 200) {
        throw std::invalid_argument("Guest does not have enough money!");
    }

    if (money < 400) {
        if (occupied_rooms_200 == ROOMS_200) {
            throw std::invalid_argument("Rooms (costing 200) are all occupied!");
        }
        ++occupied_rooms_200;
        return;
    }

    if (money < 600) {
        if (occupied_rooms_400 == ROOMS_400) {
            throw std::invalid_argument("Rooms (costing 400) are all occupied!");
        }
        ++occupied_rooms_400;
        return;
    }

    if (occupied_rooms_600 == ROOMS_600) {
        throw std::invalid_argument("Rooms (costing 600) are all occupied!");
    }
    ++occupied_rooms_600;
}

void Hotel::consoleInput() {
    char *input = nullptr;
    scanf("%s", input);

    if (!strcmp(input, "exit")) {
        finish = true;
        return;
    }

    int money = std::stoi(input);
    book(money);
}

void Hotel::randomInput() {
    if (amount == 0) {
        finish = true;
        return;
    }

    --amount;
    int money = rand() % (1000 - 200 + 1) + 200;
    book(money);
}

void Hotel::leave() {
    int index = rand() % (occupied_rooms_200 + occupied_rooms_400 + occupied_rooms_600) + 1;

    if (index <= occupied_rooms_200 && occupied_rooms_200 > 0) {
        --occupied_rooms_200;
    } else if (index <= occupied_rooms_400 && occupied_rooms_400 > 0) {
        --occupied_rooms_400;
    } else if (occupied_rooms_600 > 0) {
        --occupied_rooms_600;
    }

    std::this_thread::sleep_for(std::chrono::microseconds(300));
}

Hotel::Hotel(char *argv[]) : Thread() {
    std::function<void()> operation;

    if (!strcmp(argv[1], "random")) {
        amount = std::stoi(argv[2]);

        std::thread thread(&Hotel::run, Hotel::randomInput);
    } else if (!strcmp(argv[1], "console")) {
        std::thread thread(&Hotel::run, Hotel::consoleInput);
    } else {
        throw std::invalid_argument("This command is not available!");
    }
}

Hotel::Hotel() : Thread() {
    amount = 0;
    std::thread thread(&Hotel::run,  Hotel::leave);
}

void Hotel::init() {
    occupied_rooms_200 = 0;
    occupied_rooms_400 = 0;
    occupied_rooms_600 = 0;
}

void Hotel::stop() {
    thread->join();
}

void Hotel::result() {
    std::cout << "Rooms (costing 200) have " + std::to_string(ROOMS_200 - occupied_rooms_200) + " free\n";
    std::cout << "Rooms (costing 400) have " + std::to_string(ROOMS_400 - occupied_rooms_400) + " free\n";
    std::cout << "Rooms (costing 600) have " + std::to_string(ROOMS_600 - occupied_rooms_600) + " free\n";
}

Hotel::~Hotel() {
    delete thread;
    thread = nullptr;
}
