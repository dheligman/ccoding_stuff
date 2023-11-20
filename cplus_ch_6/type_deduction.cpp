#include <cstdio>

template<typename T> // defining a template that takes in T
T mean(const T* values, size_t length) { //defining a T function that calculates mean
    T result{};
    for(size_t i{}; i<length; i++) {
        result += values[i];
    }
    return result / length;
}

int main() {
    const double nums_d[]{ 1, 2, 3, 4 };
    const auto result1 = mean(nums_d, sizeof(nums_d)/sizeof(double));
    printf("double: %f\n", result1);

    const float nums_f[]{ 1.0f, 2.0f, 3.0f, 4.0f };
    const auto result2 = mean(nums_f, sizeof(nums_f)/sizeof(float));
    printf("float: %f\n", result2);

    const size_t nums_c[] { 1, 2, 3, 4 };
    const auto result3 = mean(nums_c, sizeof(nums_c)/sizeof(size_t));
    printf("size_t: %zu\n", result3);
}
/*Here, I removed the type suffix to show that the 
compile can deduce the type for T*/