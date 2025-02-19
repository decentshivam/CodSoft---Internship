#include <iostream>

int main() {
    double num1, num2;
    char operation;

    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;
    std::cout << "Enter an operation (+, -, *, /): ";
    std::cin >> operation;

    switch(operation) {
        case '+':
            std::cout << "Result: " << num1 + num2 << std::endl;
            break;
        case '-':
            std::cout << "Result: " << num1 - num2 << std::endl;
            break;
        case '*':
            std::cout << "Result: " << num1 * num2 << std::endl;
            break;
        case '/':
            if (num2 != 0)
                std::cout << "Result: " << num1 / num2 << std::endl;
            else
                std::cout << "Cannot divide by zero." << std::endl;
            break;
        default:
            std::cout << "Invalid operation." << std::endl;
    }
    return 0;
}
