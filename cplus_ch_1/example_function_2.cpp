#include <cstdio>

int step_function(int x) {
    int result = 0;
    if (x < 0){
        result = -1;
    } 
    else if (x > 0){
        result = 1;
    }
    
    return result;
}

int main(){
    int num1 = 42;
}