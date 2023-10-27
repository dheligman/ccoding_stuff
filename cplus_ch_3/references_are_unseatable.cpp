#include <cstdio>

int main() {
    int original = 100; // defining an integer
    int& original_ref = original; // defining an integer reference that references original
    printf("Original: %d\n", original); // printing the original integer
    printf("Reference: %d\n", original_ref); // printing the value that original_ref references

    int new_value = 200; // defining a new integer
    original_ref = new_value; // changing the value of the original integer. Does not change the address of the reference!
    printf("Original: %d\n", original); // printing the original integer
    printf("New Value: %d\n", new_value); // printing the new value
    printf("Reference: %d\n", original_ref); // printing the original referenced value
}