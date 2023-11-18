#include <cstdio>

struct BaseClass { // defining a BaseClass class
    virtual const char* final_message() const = 0; // defining a virtual const string method that cant change members. The =0 makes this a pure virtual method
}; // can't be instansiated, only inherited.

struct DerivedClass : BaseClass { // defining a DerivedClass class that inherits the BaseClass
    const char* final_message() const override { //since this method is pure virtual it must be implemented by the DerivedClass
        return "We appologize for the inconvenience.";
    }
};

int main() {
    // BaseClass base; // Bang! // uncommenting this will cause an error
    DerivedClass derived; // Defining a DerivedClass object derived
    BaseClass& ref = derived; // Defining a BaseClass reference ref that references derived
    printf("DerivedClass: %s\n", derived.final_message());
    printf("BaseClass&:   %s\n", ref.final_message());
}