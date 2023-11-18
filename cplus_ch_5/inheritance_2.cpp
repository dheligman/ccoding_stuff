#include <cstdio>

struct BaseClass {}; // defining the BaseClass class
struct DerivedClass : BaseClass {}; // defining the DerivedClass class that inherits BaseClass
void all_about_that(DerivedClass& derived) {}; // defining a void function that takes a DerivedClass reference as an argument

int main() {
    BaseClass base; // defining a base class object
    all_about_that(base); // attempting to use base within the defined function
}
/*Since BaseClass does not inherit from DerivedClass, this 
script will fail.*/