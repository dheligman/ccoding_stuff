#include <stdexcept>
#include <cstdio>
#include <cstring>

struct SimpleString { // defining a simple string class
    SimpleString(size_t max_size) // constructor that takes a size_t argument
        : max_size{ max_size }, length{} { // initiallizing max_size t0 max_size and length to 0
            if (max_size == 0) { // through a runtime error if the length is equal to zero
                throw std::runtime_error{ "Max size must be at least 1."};
            }
            buffer = new char[max_size]; // creating a pointer for dynamic memory buffer with size max_size
            buffer[0] = 0; // initiallizing the buffer to zero
    }
     
    ~SimpleString() { // defining destructor
        delete[] buffer; // destructor deletes buffer
    }
    void print(const char* tag) const { // defining function that takes a constant string as argument
        printf("%s: %s", tag, buffer); // prints the tag and buffer strings
    }

    bool append_line(const char* x) { // defining a function that takes a read-only string as an argument
        const auto x_len = strlen(x); // defining a variable that stores the length of x
        if(x_len + length + 2 > max_size) return false; // the possible length of the new string is larger than max_size return false
        std::strncpy(buffer + length, x, max_size - length); // copying max_size - length from bytes from x to desitination buffer +length
        length += x_len; // increasing length by x_len
        buffer[length++] = '\n'; // setting the char at length++ to new line
        buffer[length] = 0; // setting char at length to the null char
        return true; // return true
    }
    
    SimpleString(const SimpleString& other) // declaring a copy constructor that takes a Simple string as an object
        : max_size{ other.max_size }, // setting the copy's max size to equal the other's max_size
        buffer{ new char[other.max_size] }, // setting the copy's buffer to be equal to a new dynamic char with a buffer size equal to the other's max_size.
        length{ other.length } { // setting the copy's length to be equal to other's length
            std::strncpy(buffer, other.buffer, length); // copying bytes defined by length of other.buffer to where buffer is pointing to.
        }

    private: // declaring the variables
        size_t max_size;
        char* buffer;
        size_t length;
   

    
};


void dont_do_this() {
    SimpleString a{ 50 };
    a.append_line("We apologize for the");
    SimpleString b{ 50 };
    b.append_line("Last message");
    b = a;
}

int main() {
    dont_do_this();
}
/*The defined function is an attempt to implement a copy assignement. The function will return an undefined behavior because we have not defined a copy assignment operator.*/