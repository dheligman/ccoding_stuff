#include <cstdio>

struct Book {
    char name[256];
    int year;
    int pages;
    bool hardcover;
};

int main() {
    Book neuromancer;
    neuromancer.pages = 271;
    printf("Neuromancer has %d pages.", neuromancer.pages);
}
/*In this example I define a book class. I initialize an instance of the book called 
neuromancer and set pages to equal 271.*/