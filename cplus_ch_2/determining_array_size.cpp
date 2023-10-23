#include <cstdio>

int main() {
    short array[] = { 104, 105, 32, 98, 105, 108, 0 }; 
    size_t n_elements = sizeof(array) / sizeof(short);
    printf("The size of the array is: %zu", n_elements);
}
/*In this trick, I utilize the size in byte of the array and the size of each element and 
divide the two values to determine the size in the number of elements in the array.*/