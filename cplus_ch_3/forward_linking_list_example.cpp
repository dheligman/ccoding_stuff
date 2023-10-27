#include <cstdio>

struct Element { // defining the forward linking list class
    Element* next{}; // initializing the pointer member to nullptr
    void insert_after(Element* new_element) { // defining a method that takes in a different linking list type object, setting it to equal the pointer of the current element, and setting the pointer of the current element to the pointer of the new element
        new_element->next = next; 
        next = new_element;
    }
    char prefix[2]; // defining a character array
    short operating_number; // defining a short integer operating number
};

int main() {
    Element trooper1, trooper2, trooper3; // declaring three element objects
    trooper1.prefix[0] = 'T'; // initializing members
    trooper1.prefix[1] = 'K';
    trooper1.operating_number = 421; 
    trooper1.insert_after(&trooper2); // setting the pointer member to the next object
    trooper2.prefix[0] = 'F';
    trooper2.prefix[1] = 'N';
    trooper2.operating_number = 2187;
    trooper2.insert_after(&trooper3); // setting the pointer member to the next object
    trooper3.prefix[0] = 'L';
    trooper3.prefix[1] = 'S';
    trooper3.operating_number = 005;

/*Defining a for loop that starts with a pointer pointing at the first element object. It will 
terminate when the cursor is a nullptr. cursor is iterated by the elements next member.*/
    for (Element* cursor = &trooper1; cursor; cursor = cursor->next) {
        printf("stormtrooper %c%c-%d\n",
                cursor->prefix[0],
                cursor->prefix[1],
                cursor->operating_number);
    }
}
