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

struct Bank  { // defining a Bank class. This time instead of declaring a constructor, I defined a method that takes a pointer as an argument. This function will reseat the logger member to the new pointer.
    void set_logger(Logger* new_logger) {
        logger = new_logger;
    }
    void make_transfer(long from, long to, double amount) {
        if (logger) logger->log_transfer(from,to,amount); // if the logger is not the nullptr, it will implement the log_transfer method of logger
    }
    private:
    Logger* logger{};
};

int main() {
    ConsoleLogger console_logger; // declaring a ConsoleLogger object console_logger
    FileLogger file_logger; // declaring a FileLogger object file_logger
    Bank bank; // declaring a Bank object bank
    bank.set_logger(&console_logger); // reseating the logger pointer in bank to point to console_logger
    bank.make_transfer(1000, 2000, 49.95); 
    bank.set_logger(&file_logger); // reseating the logger pointer in bank to point to file_logger
    bank.make_transfer(2000, 4000, 20.00); 
}