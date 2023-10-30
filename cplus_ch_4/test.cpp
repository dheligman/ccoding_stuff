#include <cstdio>

void tester(int* x) {
    *x = *x + 1;
    printf("%d", *x);
}

 int main() {
    int y = 1;
    tester(&y);
    printf("%d", y);
 }