#include <cstdio>

struct BaseClass {}; // defining a BaseClass class

struct DerivedClass : BaseClass { // defining a DerivedClass class that inherits the BaseClass
    DerivedClass() { // defining a constructor
        printf("DerivedClass() invoked.\n");
    }
    ~DerivedClass() { // defining a destructor
        printf("~DerivedClass() invoked.\n");
    }
};

int main() {
    printf("Constructing DerivedClass x.\n");
    BaseClass* x{ new DerivedClass{} }; // defining a BaseClass pointer that points to a DerivedClass dynamic allocated memory object
    printf("Deleting x as a BaseClass*.\n");
    delete x;
}
// Since the pointer is a BaseClass type, it would call the Bass class destructor, but not the DerivedClass destructor