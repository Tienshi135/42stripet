#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stdexcept>
#include "easyfind.hpp"

int main() {
    std::cout << "=== Testing easyfind function ===" << std::endl;
    
    // Test with std::vector
    std::cout << "\n--- Testing with std::vector ---" << std::endl;
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);
    
    try {
        std::vector<int>::iterator it = easyfind(vec, 30);
        std::cout << "Found value 30 in vector: " << *it << std::endl;
        std::cout << "Position in vector: " << std::distance(vec.begin(), it) << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    try {
        std::vector<int>::iterator it = easyfind(vec, 99);
        std::cout << "Found value 99 in vector: " << *it << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Error searching for 99: " << e.what() << std::endl;
    }
    
    // Test with std::list
    std::cout << "\n--- Testing with std::list ---" << std::endl;
    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.push_back(5);
    
    try {
        std::list<int>::iterator it = easyfind(lst, 1);
        std::cout << "Found value 1 in list: " << *it << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    try {
        std::list<int>::iterator it = easyfind(lst, 10);
        std::cout << "Found value 10 in list: " << *it << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Error searching for 10: " << e.what() << std::endl;
    }
    
    // Test with std::deque
    std::cout << "\n--- Testing with std::deque ---" << std::endl;
    std::deque<int> deq;
    deq.push_back(100);
    deq.push_back(200);
    deq.push_back(300);
    
    try {
        std::deque<int>::iterator it = easyfind(deq, 200);
        std::cout << "Found value 200 in deque: " << *it << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    // Test with empty container
    std::cout << "\n--- Testing with empty container ---" << std::endl;
    std::vector<int> empty_vec;
    
    try {
        std::vector<int>::iterator it = easyfind(empty_vec, 42);
        std::cout << "Found value 42 in empty vector: " << *it << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Error searching in empty container: " << e.what() << std::endl;
    }
    
    // Test with duplicate values
    std::cout << "\n--- Testing with duplicate values ---" << std::endl;
    std::vector<int> dup_vec;
    dup_vec.push_back(5);
    dup_vec.push_back(3);
    dup_vec.push_back(5);
    dup_vec.push_back(7);
    dup_vec.push_back(5);
    
    try {
        std::vector<int>::iterator it = easyfind(dup_vec, 5);
        std::cout << "Found first occurrence of 5: " << *it << std::endl;
        std::cout << "Position: " << std::distance(dup_vec.begin(), it) << std::endl;
    } catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "\n=== All tests completed ===" << std::endl;
    return 0;
}