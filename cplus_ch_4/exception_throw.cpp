#include <stdexcept>
#include <cstdio>

struct Groucho { // defining Groucho class
    void forget(int x) { // defining a function that takes an integer argument
        if (x == 0xFACE) { // defining a condition that throws an exception
            throw std::runtime_error  { "I'd be glad to make an exception." };
        }
        printf("Forgot 0x%x\n", x); // prints integer if exception is not thrown
    }
};

int main() {
    Groucho groucho; // declaring and initializing groucho
    try {
        groucho.forget(0xC0DE); // performing forget on 0xC0DE. integer passes
        groucho.forget(0xFACE); // performing forget on 0xFACE. integer does not pass. throws exception
        groucho.forget(0xC0FFEE); // program terminates before this line
    } catch (const std::runtime_error& e) { // defining the catch. references the runtime error that is thrown in-flight
        printf("exception caught with message: %s\n", e.what()); // prints exception message
    }
}