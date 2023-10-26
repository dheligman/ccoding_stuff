#include <cstdio>

struct College { // Defining the POD College. Has a string member representing college names
    char name[256];
};

/*Defining a function that takes a College pointer and an array length as arguments. 
Within the function we run a for loop that goes from 0 to length of the array. Within the 
for loop, we print the name member of each college object in the array.*/
void print_names(College colleges[], size_t n_colleges) { 
    for (size_t i = 0; i < n_colleges; i++) {
        printf("%s College\n", colleges[i].name);
    }
}

int main() {
    College oxford[] = { "Magdalen", "Nuffield", "Kellogg" };
    print_names(oxford, sizeof(oxford) / sizeof(College));
}