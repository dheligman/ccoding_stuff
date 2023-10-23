#include <cstdio>

int main() {
    int arr[] = {1, 2, 3, 4}; // defining an array of size 4
    printf("The third element is %d.\n", arr[2]); // printing out the third element of the array.
    arr[2] = 100; // setting the third element of the array to 100.
    printf("The third element is %d.\n", arr[2]); // printing out the third element again.
}