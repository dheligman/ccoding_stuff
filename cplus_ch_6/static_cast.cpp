#include <cstdio>

short increment_as_short(void* target) { // defining a short function that takes a void pointer as an argument
    auto as_short = static_cast<short*>(target); // defining an auto type as_short that equals a static_cast of the target converting it to a short pointer
    *as_short = *as_short + 1; // adding 1 to the value at as_short's address
    return *as_short;
}

int main() {
    short beast{ 665 };
    auto mark_of_the_beast = increment_as_short(&beast);
    printf("%d is the mark_of_the_beast", mark_of_the_beast);
}