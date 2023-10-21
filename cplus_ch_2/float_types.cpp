#include <cstdio>

int main(){
    double an = 6.0221409e23;
    printf("Avogradro's Number: %le %lf %lg \n", an, an, an); 
    // showing the different representations of doubles.

    float hp = 9.75;
    printf("Hogwarts' Platform: %e %f %g\n", hp, hp, hp);
    // showing the different representations of floats.
    //as common practice use %g for floating point types. Its just easier.
}