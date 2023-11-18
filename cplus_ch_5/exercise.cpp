#include <cstdio>

struct Logger { // defining a Logger base class with a virtual destructor and virtual method
    virtual ~Logger() = default;
    virtual void log_transfer(long from, long to, double amount) = 0;
};

struct AccountDatabase {
    virtual ~AccountDatabase() = default;
    virtual void account_receive(long id, double amount) = 0;
};

struct InMemoryAccountDatabase : AccountDatabase {
    void account_receive(long id, double amount) override {
        printf("%ld: %f\n", id, amount);
    }
};

struct ConsoleLogger : Logger { // defining a ConsoleLogger class which inherits the Logger base class. Its method overrides the inherited method from the base class
    ConsoleLogger(const char* str) : str{ str }{};
    void log_transfer(long from, long to, double amount) override {
        printf("[cons] %s %ld -> %ld: %f\n", str, from, to, amount);
    }
    private:
    const char* str;
};

struct FileLogger : Logger { // same idea as the above class
    void log_transfer(long from, long to, double amount) override {
        printf("[file] %ld,%ld,%f\n", from, to, amount);
    }
};

struct Bank { // defining a bank class. This class takes a Logger baseclass object reference as an argument. This means that it can take any class object that inherited the base class
    Bank(Logger& logger, AccountDatabase& accountdatabase) : logger{ logger }, accountdatabase{ accountdatabase } {}
    void make_transfer(long from, long to, double amount) {
        logger.log_transfer(from, to, amount);
        accountdatabase.account_receive(to, amount);
    }
    private:
    Logger& logger;
    AccountDatabase& accountdatabase;
};

int main() {
    ConsoleLogger logger{ "string" }; // declaring a ConsoleLogger object logger
    InMemoryAccountDatabase database;
    Bank bank{ logger, database }; // defining a bank Bank that takes logger as an argument. since logger is a ConsoleLogger type, it will override the original method from the base class with the ConsolLogger's method 
    bank.make_transfer(1000, 2000, 49.95);
    bank.make_transfer(2000, 4000, 20.00);
}