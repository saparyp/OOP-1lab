#include "../include/three.hpp"
#include <iostream>

int main() {
    try {
        Three num1("1201");  // 46
        Three num2("0212");  // 23
        
        std::cout << "Ternary 1: " << num1.toString() << std::endl;
        std::cout << "Ternary 2: " << num2.toString() << std::endl;
        
        //иммутабельные
        Three sum = num1.add(num2);
        std::cout << "Sum: " << sum.toString() << " (expected: 2120)" << std::endl;
        
        Three diff = num1.subtract(num2);
        std::cout << "Difference: " << diff.toString() << " (expected: 212)" << std::endl;
        
        Three copy = num1.copy();
        std::cout << "Copy of num1: " << copy.toString() << std::endl;
        
        //с присваиванием
        Three num3 = num1.copy();
        num3.addAndAssign(num2);
        std::cout << "num1 + num2 (assign): " << num3.toString() << std::endl;
        
        Three num4 = num1.copy();
        num4.subtractAndAssign(num2);
        std::cout << "num1 - num2 (assign): " << num4.toString() << std::endl;
        
        //сравнения
        std::cout << "num1 > num2: " << (num1.greaterThan(num2) ? "true" : "false") << std::endl;
        std::cout << "num1 < num2: " << (num1.lessThan(num2) ? "true" : "false") << std::endl;
        std::cout << "num1 == num2: " << (num1.equals(num2) ? "true" : "false") << std::endl;
        
        //проверка иммутабельности
        std::cout << "Original num1 after operations: " << num1.toString() << " (should be unchanged)" << std::endl;
        std::cout << "Original num2 after operations: " << num2.toString() << " (should be unchanged)" << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}