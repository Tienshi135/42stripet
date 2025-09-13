#include <iostream>
#include <string>
#include "iter.hpp"

// Test functions for int arrays
void printInt(int &x) {
    std::cout << x << " ";
}

void doubleInt(int &x) {
    x *= 2;
}

void incrementInt(int &x) {
    x++;
}

// Test functions for string arrays
void printString(std::string &s) {
    std::cout << "\"" << s << "\" ";
}

void upperCaseString(std::string &s) {
    for (size_t i = 0; i < s.length(); i++) {
        s[i] = std::toupper(s[i]);
    }
}

// Test functions for const arrays (read-only)
void printConstInt(const int &x) {
    std::cout << x << " ";
}

void printConstString(const std::string &s) {
    std::cout << "\"" << s << "\" ";
}

// Test functions for double arrays
void printDouble(double &d) {
    std::cout << d << " ";
}

void multiplyDouble(double &d) {
    d *= 1.5;
}

// Test functions for char arrays
void printChar(char &c) {
    std::cout << c << " ";
}

void toUpperChar(char &c) {
    c = std::toupper(c);
}

// Template function that can work with const arrays
template <typename T>
void iter_const(const T *array, size_t len, void (*f)(const T &)) {
    for (size_t i = 0; i < len; i++)
        f(array[i]);
}

int main() {
    std::cout << "=== Testing iter template function ===" << std::endl;
    
    // Test 1: Non-const int array
    std::cout << "\n1. Testing with non-const int array:" << std::endl;
    int numbers[] = {1, 2, 3, 4, 5};
    size_t numbersLen = sizeof(numbers) / sizeof(numbers[0]);
    
    std::cout << "Original array: ";
    iter(numbers, numbersLen, printInt);
    std::cout << std::endl;
    
    std::cout << "After doubling: ";
    iter(numbers, numbersLen, doubleInt);
    iter(numbers, numbersLen, printInt);
    std::cout << std::endl;
    
    std::cout << "After incrementing: ";
    iter(numbers, numbersLen, incrementInt);
    iter(numbers, numbersLen, printInt);
    std::cout << std::endl;
    
    // Test 2: Non-const string array
    std::cout << "\n2. Testing with non-const string array:" << std::endl;
    std::string words[] = {"hello", "world", "template", "function"};
    size_t wordsLen = sizeof(words) / sizeof(words[0]);
    
    std::cout << "Original strings: ";
    iter(words, wordsLen, printString);
    std::cout << std::endl;
    
    std::cout << "After uppercase: ";
    iter(words, wordsLen, upperCaseString);
    iter(words, wordsLen, printString);
    std::cout << std::endl;
    
    // Test 3: Const arrays (requires separate template function)
    std::cout << "\n3. Testing with const arrays:" << std::endl;
    const int constNumbers[] = {10, 20, 30, 40, 50};
    size_t constNumbersLen = sizeof(constNumbers) / sizeof(constNumbers[0]);
    
    std::cout << "Const int array: ";
    iter_const(constNumbers, constNumbersLen, printConstInt);
    std::cout << std::endl;
    
    const std::string constWords[] = {"const", "array", "test"};
    size_t constWordsLen = sizeof(constWords) / sizeof(constWords[0]);
    
    std::cout << "Const string array: ";
    iter_const(constWords, constWordsLen, printConstString);
    std::cout << std::endl;
    
    // Test 4: Different data types
    std::cout << "\n4. Testing with different data types:" << std::endl;
    
    // Double array
    double doubles[] = {1.1, 2.2, 3.3, 4.4};
    size_t doublesLen = sizeof(doubles) / sizeof(doubles[0]);
    
    std::cout << "Double array: ";
    iter(doubles, doublesLen, printDouble);
    std::cout << std::endl;
    
    std::cout << "After multiplying by 1.5: ";
    iter(doubles, doublesLen, multiplyDouble);
    iter(doubles, doublesLen, printDouble);
    std::cout << std::endl;
    
    // Char array
    char chars[] = {'a', 'b', 'c', 'd', 'e'};
    size_t charsLen = sizeof(chars) / sizeof(chars[0]);
    
    std::cout << "Char array: ";
    iter(chars, charsLen, printChar);
    std::cout << std::endl;
    
    std::cout << "After converting to uppercase: ";
    iter(chars, charsLen, toUpperChar);
    iter(chars, charsLen, printChar);
    std::cout << std::endl;
    
    std::cout << "\n=== All tests completed ===" << std::endl;
    
    return 0;
}
