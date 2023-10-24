#include <cstdio>

struct Earth {
    ~Earth() { //Earth's destructor
        printf("Making way for hyperspace bypass");
    }
};

int main() {
    Earth test;
}

/*Here, we incorporate a destructor in the the class. The destructor is a cleanup function which
Tells the script what to do with the class when the script ends. Here we tell it to print some
text.*/