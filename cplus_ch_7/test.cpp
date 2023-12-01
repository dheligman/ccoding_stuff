#include <cstdio>

int main() {
    int x{1};
    x++;
    printf("%d", x+=1);
    printf("%d", x);
}