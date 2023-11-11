#include <cstdio>

struct Point {
    int x, y;
};

Point make_transpose(Point p) {
    int tmp = p.x;
    p.x = p.y;
    p.y = tmp;
    return p;
}

int main () {
    Point p{2,1};

    Point q = make_transpose(p);
    printf("%d, %d", p.x, p.y);
}