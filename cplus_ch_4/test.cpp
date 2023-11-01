#include <cstdio>

int main() {
    int x = 1;
    printf("%d", x);
    int* const y = &x;
    int z = 2; 
    //y = &z;
    printf("%d", *y);
    //*y = *y + 1;
}