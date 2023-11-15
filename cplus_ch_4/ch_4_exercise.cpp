#include <cstdio>
#include <utility>
#include <stdexcept>
#include <cstring>
#include <ctime>

struct TimerClass{
    TimerClass(const char* name)
    : name{ name } {
        timestamp = time(NULL);
    }
    TimerClass(const TimerClass& other)
    : name{ other.name }, timestamp{ other.timestamp } {};

    TimerClass(TimerClass&& other) noexcept
    : name { other.name }, timestamp{ other.timestamp} {
        other.timestamp = -1;
    }

    TimerClass& operator=(const TimerClass& other) {
        if (this == &other) return *this;
        timestamp = other.timestamp;
        return *this;
    }

    TimerClass& operator=(TimerClass&& other) {
        if (this == &other) return *this;
        timestamp = other.timestamp;
        other.timestamp = -1;
        return *this;
    }

    ~TimerClass() {
        if (timestamp != -1) {
            timestamp = time(NULL) - timestamp;
            printf("%s's Duration: %ld\n", name, timestamp);
        }
    }

    private:
        time_t timestamp;
        const char* name;

};

void stress_test() {
    int x{1};
    for(int i=0; i<100000; i++) {
        for (int j=0; j<100000; j++) {
            x++;
        }
    }
}


int main() {
    TimerClass a("a");
    TimerClass b{ a };
    TimerClass c{ std::move(b) };
    b = c;
    b = std::move(c);
    stress_test();
}