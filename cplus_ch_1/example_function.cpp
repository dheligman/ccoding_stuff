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
    int value1 = step_function(100); // value is 1
    int value2 = step_function(0); // value is 0
    int value3 = step_function(-10); // value is -1
    printf("value1: %d\n", value1);
    printf("value2: %d\n", value2);
    printf("value3: %d\n", value3);

    return 0;
}