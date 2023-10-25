#include <cstdio>

int main() {
    int gettysburg{}; // declaring an integer gettysburg
    printf("gettysburg: %d\n", gettysburg); // printing the value of gettysburg (0)
    int* gettysburg_address = &gettysburg; // declaring an integer pointer gettysburg_address and point it to gettysburg.
    printf("&gettysburg: %p\n", gettysburg_address); // printing the gettysburg_adress pointer
} 