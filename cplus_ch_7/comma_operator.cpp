#include <cstdio>

int confusing(int& x) { // defining a function that references the argument
    return x = 9, x++, x / 2; // referenced argument will be set to 9 and incremented by 1. The function then returns the last operation to y
}

int main() {
    int x{};
    auto y = confusing(x);
    printf("x: %d\ny: %d", x, y);
}