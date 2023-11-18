#include <cstdio>

struct BaseClass {}; // defining a BaseClass class
struct DerivedClass : BaseClass {}; // defining a DerivedClass class that inherits BaseClass
void are_belong_to_us(BaseClass base) {} // defining a 

int main() {
    DerivedClass derived;
    are_belong_to_us(derived);
}