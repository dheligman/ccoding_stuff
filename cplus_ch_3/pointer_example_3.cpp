#include <cstdio>

int main() {
    int gettysburg{}; // declaring an integer named gettysburg
    int* gettysburg_address = &gettysburg; // declaring a pointer named gettysburg_address equal to gettysburg address
    printf("Value at gettysburg_address: %d\n", *gettysburg_address); // printing value at gettysburg address
    printf("Gettysburg Address: %p\n", gettysburg_address); // printing the gettysburg address
    *gettysburg_address = 17325; // setting the value at gettysburg_address to 17325
    printf("Value at gettysburg_address: %d\n", *gettysburg_address); // print the new value
    printf("Gettysburg Address: %p\n", gettysburg_address); // print the gettysburg_address again
}