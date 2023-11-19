#include <cstdio>

int main() {
    const int x = 1;
    auto& y = const_cast<int&>(x);
    y = 2;
    printf("%d", x);

}