#include <cstdio>
#include <cstring>
#include <stdexcept>
#include <utility>

struct SimpleString { // defining a SimpleString class
    SimpleString(size_t max_size) // defining a constructor that takes a size_t max_size argument
    : max_size{ max_size }, // initializing the max_size member to max_size
    length{} { // initializing length to 0
        if (max_size == 0) { // throw a runtime error if max_size is 0
            throw std::runtime_error{ "Max size must be at least 1." };
        }
        buffer = new char[max_size]; // allocating memory for buffer with a size of max_size
        buffer[0] = 0; // setting the buffer at 0 to be null
    }
    ~SimpleString() { // defining a destructor that deletes the buffers allocated memory
        delete[] buffer; 
    }
    SimpleString(const SimpleString& other) // defining a copy constructor
    : max_size{ other.max_size }, // setting the max_size to equal the original's max_size
    buffer{ new char[other.max_size] }, // allocating memory for the new buffer and setting the size to be the original's max_size 
    length{ other.length } { // setting the length to equal the original's length
        std::strncpy(buffer, other.buffer, max_size); // copying max_size bytes from the original's buffer to the new buffer
    }
    SimpleString(SimpleString&& other) noexcept // defining a move operator
    : max_size{ other.max_size }, // setting the max size to equal the original's
    buffer{ other.buffer }, // setting the buffer to equal the original's buffer
    length{ other.length } { // setting the length to equal the original's length
        other.length = 0; // setting the original's length to equal 0
        other.buffer = nullptr; // setting the original's buffer to equal the null pointer
        other.max_size = 0; // setting the original's max_size to zero
    }
    SimpleString& operator=(const SimpleString& other) { // defining a copy assignment operator
         if (this == &other) return *this; // defining a conditional if the original is set to equal itself
         const auto new_buffer = new char[other.max_size]; // defining a temporary buffer and allocating memory for it
         delete[] buffer; // deleting the old buffer of the assignee
         buffer = new_buffer; // setting the old buffer to be equal to the temporary buffer
         length = other.length; // setting the original length to equal the original's length
         max_size = other.max_size; // setting the max size to equal the original's max size
         std::strncpy(buffer, other.buffer, max_size); // copying max_size bytes from the original buffer to the assignee's buffer
         return *this; // returning itself
    }
    SimpleString& operator=(SimpleString&& other) noexcept { // defining a move assignment operator
        if (this == &other) return *this; // defining a conditional if it is moved to itself
        delete[] buffer; // deleting the buffer memory
         buffer = other.buffer; // setting the buffer to equal the original's
         length = other.length; // setting the length to equal the original's
         max_size = other.max_size; // setting the max_size to equal the original's max_size
         other.buffer = nullptr; // setting the original's buffer to a null pointer
         other.length = 0; // setting the original's length to equal 0 
         other.max_size = 0; // setting the max_size to equal 0
         return *this; // returning itself
    }
    void print(const char* tag) const { // defining a function that prints the buffer. set to constant so its not possible to change the buffer member
        printf("%s: %s", tag, buffer);
    }
    bool append_line(const char* x) { // defining a function that appends a new line to the string
        const auto x_len = strlen(x); // defining an auto variable x_len and initializing it to the length of x
        if (x_len + length + 2 > max_size) return false; // if the resulting string after append exceeds the max length of the buffer, return false
        std::strncpy(buffer + length, x, max_size - length); // copy max_size - length bytes of x to buffer starting at buffer + length
        length += x_len; // add x_len to length
        buffer[length++] = '\n'; // adding a new line to the buffer at length + 1
        buffer[length] = 0; // setting the buffer at location length to equal null
        return true; // return true
    }
    private: // declaring the member variables of the class
        size_t max_size;
        char* buffer;
        size_t length;
};

int main() {
    SimpleString a{ 50 };
    SimpleString b{ 50 };
    a.append_line("Hello World!");
    b.append_line("Hello Sun!");
    a.print("a");
    b.print("b");
    SimpleString c{ a };
    c.print("c");
    c = b; 
    c.print("c");
    SimpleString d{std::move(a)};
    a.print("a");
    printf("\n");
    d.print("d");
    d = std::move(b);
    b.print("b");
    printf("\n");
    d.print("d");
}