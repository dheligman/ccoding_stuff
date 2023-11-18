#include <cstdio>

struct Logger { // defining a Logger base class with a virtual destructor and virtual method
    virtual ~Logger() = default;
    virtual void log_transfer(long from, long to, double amount) = 0;
};

struct ConsoleLogger : Logger { // defining a ConsoleLogger class which inherits the Logger base class. Its method overrides the inherited method from the base class
    void log_transfer(long from, long to, double amount) override {
        printf("[cons] %ld -> %ld: %f\n", from, to, amount);
    }
};

struct FileLogger : Logger { // same idea as the above class
    void log_transfer(long from, long to, double amount) override {
        printf("[file] %ld,%ld,%f\n", from, to, amount);
    }
};

struct Bank { // defining a bank class. This class takes a Logger baseclass object reference as an argument. This means that it can take any class object that inherited the base class
    Bank(Logger& logger) : logger{ logger } {}
    void make_transfer(long from, long to, double amount) {
        logger.log_transfer(from, to, amount);
    }
    private:
    Logger& logger;
};

int main() {
    ConsoleLogger logger; // declaring a ConsoleLogger object logger
    Bank bank{ logger }; // defining a bank Bank that takes logger as an argument. since logger is a ConsoleLogger type, it will override the original method from the base class with the ConsolLogger's method 
    bank.make_transfer(1000, 2000, 49.95);
    bank.make_transfer(2000, 4000, 20.00);
}