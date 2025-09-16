#include <iostream>
#include <stdexcept>
#include "header/Span.hpp"

int main() {
    std::cout << "=== Testing Span Class ===" << std::endl;
    
    // Test 1: Basic functionality
    std::cout << "\n--- Test 1: Basic functionality ---" << std::endl;
    try {
        Span span(5);
        
        span.addNumber(6);
        span.addNumber(3);
        span.addNumber(17);
        span.addNumber(9);
        span.addNumber(11);
        
        span.printArray();
        
        std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
        std::cout << "Longest span: " << span.longestSpan() << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    // Test 2: Exception when span is full
    std::cout << "\n--- Test 2: Exception when span is full ---" << std::endl;
    try {
        Span span(3);
        span.addNumber(1);
        span.addNumber(2);
        span.addNumber(3);
        span.printArray();
        
        std::cout << "Trying to add one more number..." << std::endl;
        span.addNumber(4); // This should throw
        
    } catch (const SpanFullException& e) {
        std::cout << "Caught SpanFullException: " << e.what() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    // Test 3: Exception when not enough numbers for span
    std::cout << "\n--- Test 3: Exception when not enough numbers ---" << std::endl;
    try {
        Span span(5);
        span.addNumber(42);
        span.printArray();
        
        std::cout << "Trying to find shortest span with only 1 number..." << std::endl;
        std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    
    try {
        Span span(5);
        std::cout << "Trying to find longest span with 0 numbers..." << std::endl;
        std::cout << "Longest span: " << span.longestSpan() << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    
    // Test 4: Copy constructor and assignment operator
    std::cout << "\n--- Test 4: Copy constructor and assignment ---" << std::endl;
    try {
        Span original(4);
        original.addNumber(10);
        original.addNumber(20);
        original.addNumber(30);
        
        std::cout << "Original span:" << std::endl;
        original.printArray();
        
        // Test copy constructor
        Span copied(original);
        std::cout << "Copied span:" << std::endl;
        copied.printArray();
        
        // Test assignment operator
        Span assigned(2);
        assigned = original;
        std::cout << "Assigned span:" << std::endl;
        assigned.printArray();
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    // Test 5: Edge cases
    std::cout << "\n--- Test 5: Edge cases ---" << std::endl;
    try {
        // Minimum size span (2 elements)
        Span minSpan(2);
        minSpan.addNumber(100);
        minSpan.addNumber(200);
        minSpan.printArray();
        std::cout << "Min span shortest: " << minSpan.shortestSpan() << std::endl;
        std::cout << "Min span longest: " << minSpan.longestSpan() << std::endl;
        
        // Same numbers
        Span sameSpan(3);
        sameSpan.addNumber(5);
        sameSpan.addNumber(5);
        sameSpan.addNumber(5);
        sameSpan.printArray();
        std::cout << "Same numbers shortest: " << sameSpan.shortestSpan() << std::endl;
        std::cout << "Same numbers longest: " << sameSpan.longestSpan() << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    // Test 6: fillArray function (large span)
    std::cout << "\n--- Test 6: fillArray with large span ---" << std::endl;
    try {
        Span largeSpan(10000);
        std::cout << "Filling span with 10000 random numbers..." << std::endl;
        largeSpan.fillArray();
        
        std::cout << "Shortest span: " << largeSpan.shortestSpan() << std::endl;
        std::cout << "Longest span: " << largeSpan.longestSpan() << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== All tests completed ===" << std::endl;
    return 0;
}