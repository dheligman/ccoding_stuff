#include <cstdio>
#include <stdexcept>

struct FileLogger { // Defining a FileLogger Class
    void log_transfer(long from, long to, double amount) { // Defining a log_transfer method that takes two longs and a double and prints [File] and the values
        //
        printf("[file] %ld, %ld, %f\n", from, to, amount);
    }
};

struct ConsoleLogger { // Defining a ConsoleLogger Class 
    void log_transfer(long from, long to, double amount) { // Defininga a log_transfer method. Does the same thing as above, but prints [cons] instead
        printf("[cons] %ld -> %ld: %f\n", from, to, amount);
    }
};

enum class LoggerType { // Defining an enum class that allows the Bank class below to switch between the filelogger and the consolelogger
    Console,
    File
};

struct Bank { // Defining a Bank class
    Bank() : type { LoggerType::Console } {} // Creating constructor that initializes the type to Console
    void set_logger(LoggerType new_type) { // defining a method that changes the logger type
        type = new_type;
    }

    void make_transfer(long from, long to, double amount) { // Defining a make_transfer method that runs either the method of the FileLogger or the ConsoleLogger 
        //
        switch(type) { // Creating a case structure that determines which method to use
            case LoggerType::Console: { // if its a Console type, it will run consolLogger
                consoleLogger.log_transfer(from, to, amount);
                break;
            }
            case LoggerType::File: { // if its a File type, it will run fileLogger
                fileLogger.log_transfer(from, to, amount); 
                break;
            }
            default: { // if its not a listed Logger type, it will throw a logic_error
                throw std::logic_error("Unknown Logger type encountered");
            }
        }
    }
    private:
        LoggerType type;
        ConsoleLogger consoleLogger;
        FileLogger fileLogger;
};

int main() {
    Bank bank; // Declaring a Bank bank
    bank.make_transfer(1000, 2000, 49.95); // making a transfer
    bank.make_transfer(2000, 4000, 20.00); // making another transfer
    bank.set_logger(LoggerType::File); // changing the logger type to file 
    bank.make_transfer(3000, 2000, 75.00); // making another transfer
    //bank.set_logger(LoggerType::Blah);
}
/*This approach is good and all. But it becomes a bit cumbersome if you need to add another type of logger.
You will need to add another logger class, another member to enum, and another case to the case structure in 
the bank class.*/