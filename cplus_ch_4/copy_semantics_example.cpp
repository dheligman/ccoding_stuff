#include <cstdio>

int add_one_to(int x) { // defining a function that takes an int argmument, adds 1 in-place and resturns it.
    x++;
    return x;
}

int main() {
    auto original = 1; // initializing an auto object original to 1;
    auto result = add_one_to(original); // initializing an auto result and setting it equal to add_one_to(original)
    printf("Original: %d; Result: %d", original, result); // printing the two variables
}
/*When defining the variable result and setting it to equal add_one_to(original), the function copies original to a local variable
x and adds to it. The result is then copied to result. since result is a copy of x which is a copy of original, anything that is done 
to result will not affect the original object*/
