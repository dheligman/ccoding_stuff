#include <cstdio>
#include <stdexcept>

template <typename To, typename From> // defining a template for narrow_cast
To narrow_cast(From value) { // defining a To function that takes a From argument
    const auto converted = static_cast<To>(value); // defining a constant auto object and setting to equal a static_cast of value as a To
    const auto backwards = static_cast<From>(converted); // defining a constant auto object and setting to equal a static cast of converted as a From
    if (value != backwards) throw std::runtime_error{"Narrow!"}; // if the original value does not equal the backwards, then throw a runtime error
    return converted;
}

int main() {
    int perfect{ 496 }; // defining an integer
    const auto perfect_short = narrow_cast<short>(perfect); // defining a const auto perfect_short and setting it equal narrow_cast of perfect as a short
    printf("perfect_short: %d\n", perfect_short); // printing the result
    try {
        int cyclic{ 142857 }; // defining an integer 
        const auto cyclic_short = narrow_cast<short>(cyclic); // same as above
        printf("cyclic_short: %d\n", cyclic_short);
    }
    catch (const std::runtime_error& e) { // if what is tried throws an error print the error
        printf("Exception: %s\n", e.what());
    }
}