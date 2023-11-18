#include <cstdio>

struct BaseClass { // defininga BaseClass class
    int the_answer() const { return 42; } // defininga int method that returns 42. This method cannot change any members (const).
    const char* member = "gold"; // defining a public member string gold
    private:
    const char* holistic_detective = "Dirk Gently"; // defining a private string member Dirk Gently
};

struct DerivedClass : BaseClass { // defining a DerivedClass class that inherits the BaseClass
    void announce_agency() { // defininga void method that prints the private member of the BaseClass (this won't work because you can't inherit a private member).
        // This line doesn't compile:
        // printf("%s's Holistic Detective Agency\n", holistic_detective); 
    }
};

int main() {
    DerivedClass x; // defining a DerivedClass object x
    printf("The answer is %d\n", x.the_answer()); // printing the result of the_answer() method
    printf("%s member\n", x.member); // printing the public member of the BaseClass
}
