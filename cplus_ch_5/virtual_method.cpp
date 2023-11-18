#include <cstdio>

struct BaseClass { // defining the BaseClass class
    virtual const char* final_message() const { // defining a virtual constant string method that cannot modify members of the class
        return "We apologize for the incontinence.";
    }
};

struct DerivedClass : BaseClass { // defining the DerivedClass class that inherits the BaseClass
    const char* final_message() const override { // overriding the method inherited from the BaseClass
        return "We apologize for the inconvenience.";
    }
};

int main() {
    BaseClass base; // defining a BaseClass object base
    DerivedClass derived; // defining a DerivedClass derived
    BaseClass& ref = derived; // defining a BaseClass reference ref that references derived
    printf("BaseClass:    %s\n", base.final_message());
    printf("DerivedClass: %s\n", derived.final_message());
    printf("BaseClass&:   %s\n", ref.final_message());
}