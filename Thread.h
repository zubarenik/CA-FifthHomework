#include <thread>
#include <mutex>
#include <chrono>
#include <functional>

#ifndef CA_FIFTHHOMEWORK_THREAD_H
#define CA_FIFTHHOMEWORK_THREAD_H


class Thread {
protected:
    static std::mutex process;
    static bool finish;
    std::thread *thread;

public:
    static void run(const std::function<void()> &operation);
};


#endif //CA_FIFTHHOMEWORK_THREAD_H
