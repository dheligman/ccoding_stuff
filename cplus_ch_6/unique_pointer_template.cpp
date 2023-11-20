#include <cstdio>
#include <utility>

template <typename T>
struct SimpleUniquePointer { // defining the pointer class
    SimpleUniquePointer() = default; // defining a default constructor
    SimpleUniquePointer(T* pointer) // defining a custom constructor that initializes the pointer
    : pointer{ pointer }{}
    ~SimpleUniquePointer(){ // defining the pointer destructor. deletes the pointer if it is not null
        if(pointer) delete pointer;
    }
    SimpleUniquePointer(const SimpleUniquePointer&) = delete; // preventing the copying of the pointer
    SimpleUniquePointer& operator=(const SimpleUniquePointer&) = delete; // preventinig the copy assignment of the pointer
    SimpleUniquePointer(SimpleUniquePointer&& other) noexcept // allowing the pointer to move
    : pointer{ other.pointer }{
        other.pointer = nullptr;
    }
    SimpleUniquePointer& operator=(SimpleUniquePointer&& other) noexcept { // allowing the move assignment
        if(pointer) delete pointer;
        pointer = other.pointer;
        other.pointer = nullptr;
        return *this;
    }
    T* get() { // defining a method that returns the pointer
        return pointer;
    }
    private:
    T* pointer;
};

struct Tracer {
    Tracer(const char* name) : name{ name }{
        printf("%s constructed.\n", name);
    }
    ~Tracer(){
        printf("%s destructed.\n", name);
    }
    private:
    const char* const name;
};

void consumer(SimpleUniquePointer<Tracer> consumer_ptr) {
    printf("(cons) consumer_ptr: 0x%p\n", consumer_ptr.get());
}

int main() {
    auto ptr_a = SimpleUniquePointer(new Tracer{ "ptr_a" });
    printf("(main) ptr_a: %p\n", ptr_a.get());
    consumer(std::move(ptr_a));
    printf("(main) ptr_a: %p\n", ptr_a.get());
}

