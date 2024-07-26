#include <iostream>
#include <thread>

volatile bool Stop = false;

void beep(int delay) {
    while (!Stop) {
        std::cout << '\a' << std::flush;  
        std::this_thread::sleep_for(std::chrono::seconds(delay));
    }
}

void wait() {
    std::cin.get();
    Stop = true;
}

int main() {
    int delay = 3;  

    std::thread beepingThread(beep, delay);

    std::thread enterThread(wait);

    beepingThread.join();
    
    enterThread.join();

    return 0;
}
