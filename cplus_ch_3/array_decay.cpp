#include <cstdio>

struct College { // defining the College class 
    char name[256]; // has the member name
};

void print_name(College* college_ptr) { // defining a function that takes a College pointer 
    printf("%s College\n", college_ptr->name); // prints the name associated with that pointer
}

int main() {
    College best_colleges[] = { "Magdalen", "Nuffeild", "Kellogg" }; // defining an array of college objects
    print_name(best_colleges); 
    /*performing the print_name function on this array will collapse the array to a pointer pointing to 
    the object associated withg Magdalen. Thus, the arrow operator will return the name of the 
    first college object of the array.*/
}