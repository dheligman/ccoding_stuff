#include <cstdio>

int main() {
    unsigned long maximum = 0;
    unsigned long values[] = { 10, 50, 20, 40, 0 };
    for(unsigned long value : values) { 
        if (value > maximum) maximum = value;
    }
    printf("The maximum value is: %lu.", maximum);
}

/*in this example, I defined the value that was being iterated was an unsigned long
and that it is iterating within the array values. */