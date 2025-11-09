#include "../include/three.hpp"
#include <cassert>
#include <iostream>

void testThreeCreation() {
    std::cout << "Testing Three creation..." << std::endl;
    
    Three empty;
    assert(empty.toString() == "");
    
    Three fromString("1201");
    assert(fromString.toString() == "1201");
    
    Three fromList{'1', '2', '0', '1'};
    assert(fromList.toString() == "1201");
    
    Three sized(4, '1');
    assert(sized.toString() == "1111");
    
    std::cout << "Three creation tests passed!" << std::endl;
}

void testThreeOperations() {
    std::cout << "Testing Three operations..." << std::endl;
    
    Three num1("1201");
    Three num2("0212");
    
    // Test addition
    Three sum = num1.add(num2);
    assert(sum.toString() == "2120");
    
    // Test subtraction
    Three diff = num1.subtract(num2);
    assert(diff.toString() == "212");
    
    // Test assignment operations
    Three num3 = num1.copy();
    num3.addAndAssign(num2);
    assert(num3.toString() == "2120");
    
    Three num4 = num1.copy();
    num4.subtractAndAssign(num2);
    assert(num4.toString() == "212");
    
    // Test comparison
    assert(num1.greaterThan(num2) == true);
    assert(num1.lessThan(num2) == false);
    assert(num1.equals(num2) == false);
    
    Three num5("1201");
    assert(num1.equals(num5) == true);
    
    std::cout << "Three operations tests passed!" << std::endl;
}

void testThreeImmutability() {
    std::cout << "Testing Three immutability..." << std::endl;
    
    Three num1("1201");
    Three num2("0212");
    
    std::string original1 = num1.toString();
    std::string original2 = num2.toString();
    
    Three sum = num1.add(num2);
    Three diff = num1.subtract(num2);
    
    assert(num1.toString() == original1);
    assert(num2.toString() == original2);
    
    std::cout << "Three immutability tests passed!" << std::endl;
}

int main() {
    try {
        testThreeCreation();
        testThreeOperations();
        testThreeImmutability();
        
        std::cout << "All tests passed!" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Test failed: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}