#include <cstdio>

struct Point { //  Defining a class Point
    int x, y; // Declaring two class members: x and y
};

Point make_transpose(Point p) { // defining function that returns a point.
    int tmp = p.x; // Defining an integer that equals the x member of p
    p.x = p.y; // Setting x to equal y 
    p.y = tmp; // Setting y to equal tmp. since tmp equals the original value for x. the result will be y and x swapping values
    return p; // returning the modified p object
}

int main () {
    Point p{2,1}; // defining the Point object p

    Point q = make_transpose(p); // defining Point q to be equal to make_transpose(p)
    printf("%d, %d", p.x, p.y);
    printf("\n%d, %d", q.x, q.y);
}
/*This shows that if you perform make_transpose on p, the function makes a copy of p within the function. 
The result of this is that the members of p will be unaffected.*/