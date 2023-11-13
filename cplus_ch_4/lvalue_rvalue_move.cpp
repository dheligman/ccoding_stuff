#include <cstdio>
#include <utility>

void ref_type(int &x) { // defining a function that takes an lvalue as an argument.
    printf("lvalue reference %d\n", x);
}

void ref_type(int &&x) { // defining a function that takes an rvalue as an argument.
    printf("rvalue reference %d\n", x);
}

int main() {
    auto x = 1; 
    ref_type(std::move(x)); // By invoking the move function, you cast an lvalue reference into an rvalue reference. Thus, the function will recognize the argument as an rvalue
    ref_type(2);
    ref_type(x + 2);
    ref_type(x);
    int y = 2;
    int&& z = std::move(y);
    printf("%d",y);
}