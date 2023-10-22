#include <cstdio>

int main(){
    bool t = true;
    bool f = false;
    printf("!true: %d\n", !t); // not true equals false
    printf("true  &&  false: %d\n", t && f); // true and false equals false
    printf("true  && !false: %d\n", t && !f); // true and not false equals true
    printf("true  ||  false: %d\n", t || f); // true or false equals true
    printf("false ||  false: %d\n", f || f); // false or false equals false
}