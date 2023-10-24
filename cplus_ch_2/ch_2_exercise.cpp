#include <cstdio>

enum class Operation { // Defining the different operations as an enum class.
    Add,
    Subtract,
    Multiply,
    Divide
};

struct Calculator { //constructing the calculator class.
    
    Calculator(Operation op){ // initializing the operation object with a constructor.
        operation = op;
    }; 

    Operation operation; //Declaring the operation object.

    int calculate(int a, int b) {
        /**Defining the calculate method. It takes in two integers as arguments, decides
         * decides which argument to use based on the operation (using switch cases), and returns
         * the result of the operation.
        */
        switch (operation) {
        case Operation::Add: {
            return a + b;
        } break;
        case Operation::Subtract: {
            return a - b;
        } break;
        case Operation::Multiply: {
            return a * b;
        } break;
        case Operation::Divide: {
            return a / b;
        }
        default: {
            printf("Invalid operation");
            return 0;
        } break;
        }
    }
    

};

int main() {
    Calculator calc{ Operation::Divide }; // Declaring the calculator object and setting it to divide.
    int x = calc.calculate(10, 5); // Declaring x to be equal to the result of the division.
    printf("x = %d", x); // Printing the result.
}

/*For future reference, when declaring variables using a constructor, do not name the variable
in the constructor to be the same as the member being declared. It will cause some issues!*/