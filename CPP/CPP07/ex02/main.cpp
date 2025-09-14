#include <iostream>
#include <string>
#include <exception>
#include "Array.hpp"

int main() {
    std::cout << "=== Testing Array Template Class ===" << std::endl;
    
    try {
        // Test 1: Default constructor
        std::cout << "\n1. Testing default constructor:" << std::endl;
        Array<int> emptyArray;
        std::cout << "Empty array size: " << emptyArray.size() << std::endl;
        
        // Test 2: Parameterized constructor
        std::cout << "\n2. Testing parameterized constructor:" << std::endl;
        Array<int> intArray(5);
        std::cout << "Int array size: " << intArray.size() << std::endl;
        
        // Test 3: Element access and modification with operator[]
        std::cout << "\n3. Testing operator[] for element access and modification:" << std::endl;
        for (size_t i = 0; i < intArray.size(); i++) {
            intArray[i] = i * 10;
        }
        
        std::cout << "Int array elements: ";
        for (size_t i = 0; i < intArray.size(); i++) {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;
        
        // Test 4: Copy constructor
        std::cout << "\n4. Testing copy constructor:" << std::endl;
        Array<int> copiedArray(intArray);
        std::cout << "Copied array size: " << copiedArray.size() << std::endl;
        std::cout << "Copied array elements: ";
        for (size_t i = 0; i < copiedArray.size(); i++) {
            std::cout << copiedArray[i] << " ";
        }
        std::cout << std::endl;
        
        // Test 5: Verify deep copy (modify original, check copy)
        std::cout << "\n5. Testing deep copy (modifying original):" << std::endl;
        intArray[0] = 999;
        std::cout << "Original array[0]: " << intArray[0] << std::endl;
        std::cout << "Copied array[0]: " << copiedArray[0] << std::endl;
        std::cout << "Deep copy works: " << (intArray[0] != copiedArray[0] ? "YES" : "NO") << std::endl;
        
        // Test 6: Assignment operator
        std::cout << "\n6. Testing assignment operator:" << std::endl;
        Array<int> assignedArray(3);
        assignedArray[0] = 100;
        assignedArray[1] = 200;
        assignedArray[2] = 300;
        
        std::cout << "Before assignment - assigned array: ";
        for (size_t i = 0; i < assignedArray.size(); i++) {
            std::cout << assignedArray[i] << " ";
        }
        std::cout << std::endl;
        
        assignedArray = intArray;
        std::cout << "After assignment - assigned array size: " << assignedArray.size() << std::endl;
        std::cout << "After assignment - assigned array elements: ";
        for (size_t i = 0; i < assignedArray.size(); i++) {
            std::cout << assignedArray[i] << " ";
        }
        std::cout << std::endl;
        
        // Test 7: Self-assignment
        std::cout << "\n7. Testing self-assignment:" << std::endl;
        assignedArray = assignedArray;
        std::cout << "Self-assignment completed, size: " << assignedArray.size() << std::endl;
        
        // Test 8: Const array and const operator[]
        std::cout << "\n8. Testing const array and const operator[]:" << std::endl;
        const Array<int> constArray(intArray);
        std::cout << "Const array elements: ";
        for (size_t i = 0; i < constArray.size(); i++) {
            std::cout << constArray[i] << " ";  // Uses const operator[]
        }
        std::cout << std::endl;
        
        // Test 9: Different data types - string
        std::cout << "\n9. Testing with string type:" << std::endl;
        Array<std::string> stringArray(3);
        stringArray[0] = "Hello";
        stringArray[1] = "World";
        stringArray[2] = "Template";
        
        std::cout << "String array: ";
        for (size_t i = 0; i < stringArray.size(); i++) {
            std::cout << "\"" << stringArray[i] << "\" ";
        }
        std::cout << std::endl;
        
        // Test 10: Different data types - double
        std::cout << "\n10. Testing with double type:" << std::endl;
        Array<double> doubleArray(4);
        for (size_t i = 0; i < doubleArray.size(); i++) {
            doubleArray[i] = (i + 1) * 1.5;
        }
        
        std::cout << "Double array: ";
        for (size_t i = 0; i < doubleArray.size(); i++) {
            std::cout << doubleArray[i] << " ";
        }
        std::cout << std::endl;
        
        // Test 11: Out of bounds access (if bounds checking is implemented)
        std::cout << "\n11. Testing out of bounds access:" << std::endl;
        try {
            std::cout << "Trying to access index 10 in array of size " << intArray.size() << std::endl;
            std::cout << intArray[10] << std::endl;  // Should throw if bounds checking implemented
            std::cout << "No bounds checking implemented (or index was valid)" << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
        
        // Test 12: Zero-size array edge case
        std::cout << "\n12. Testing zero-size array:" << std::endl;
        Array<int> zeroArray(0);
        std::cout << "Zero array size: " << zeroArray.size() << std::endl;
        
        // Test 13: Large array
        std::cout << "\n13. Testing large array:" << std::endl;
        Array<int> largeArray(1000);
        std::cout << "Large array size: " << largeArray.size() << std::endl;
        largeArray[0] = 42;
        largeArray[999] = 84;
        std::cout << "Large array[0]: " << largeArray[0] << std::endl;
        std::cout << "Large array[999]: " << largeArray[999] << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== All tests completed ===" << std::endl;
    
    return 0;
}
