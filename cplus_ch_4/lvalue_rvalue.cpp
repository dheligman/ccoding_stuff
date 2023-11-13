#include <cstdio>

void ref_type(int &x) { // defining a function that takes an lvalue as an argument.
    printf("lvalue reference %d\n", x);
}

void ref_type(int &&x) { // defining a function that takes an rvalue as an argument.
    printf("rvalue reference %d\n", x);
}

int main() {
    auto x = 1; 
    ref_type(x); // calling the ref_type function with x as the argument. It will call t he first function.
    ref_type(2); // calling the ref_type function with 2 as the argument. Since its not named, it will call the second function.
    ref_type(x+2); // calling the ref_type function with x + 2 as the argument. Since adding x to 2 is not bound to a name it will call the second function.
}