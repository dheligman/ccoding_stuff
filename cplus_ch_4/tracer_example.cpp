#include <cstdio>

struct Tracer // defining a tracer object class
{
    Tracer(const char* name) : name{ name } { // defining a constructor, initializes name
        printf("%s constructed.\n", name); // constructor prints name constructed
    }
    ~Tracer() { // defining deconstructor
        printf("%s destructed.\n", name); // deconstructor prints name deconstructed
    }
    private:
        const char* const name; // declaring a constant string 

};

static Tracer t1{ "Static variable" }; // defining a static variable tracer
thread_local Tracer t2{ "Thread-local variable" }; // defining a thread_local tracer

int main() {
    const auto t2_ptr = &t2; // declaring a pointer. this declaration activates t2
    printf("A\n");
    Tracer t3{ "Automatic variable" }; // declaring t3 as an automatic variable
    printf("B\n");
    const auto* t4 = new Tracer{ "Dynamic variabe" }; // declaring a dynamic tracer t4
    printf("C\n");
    delete t4; // deleting t4 to prevent memory leaks
}
/*When the script ends, first the dynamic variable deconstructs (deleted before script finished), 
then the automatic variable (terminates when the thread ends), then the thread-local variable, 
and finally the static variable (deconstructs when the program ends)*/