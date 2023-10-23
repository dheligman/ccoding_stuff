#include <cstddef>
#include <cstdio>

int main() {
    unsigned long maximum = 0; // initialize maximum to zero.
    unsigned long values[] = { 10, 50, 20, 40, 0 }; // define the array to iterate over.
    for(size_t i=0; i < 5; i++) {
        if (values[i] > maximum) maximum = values[i]; 
    } // defining an if statement stating thatif the value[i] is greater than maximum, replace maximum
    // with that value
    printf("The maximum value is %lu", maximum);
}
/*one thing to note is that it is better to use size_t for forloops thant it is to use int
since size_t does not have a limit to its byte size and int does.*/