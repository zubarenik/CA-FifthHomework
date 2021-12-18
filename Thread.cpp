#include "Thread.h"

void Thread::run(const std::function<void()> &operation) {
    while (!finish) {
        process.lock();

        try {
            operation();
        } catch (std::invalid_argument &exception) {
            printf("%s", exception.what());
        }

        process.unlock();
    }
}
