#include <iostream>
#include <list>
#include <algorithm>
#include "MutantStack.hpp"

int main() {
    std::cout << "=== Testing MutantStack ===" << std::endl;
    
    // Test 1: Basic stack operations
    std::cout << "\n--- Test 1: Basic stack operations ---" << std::endl;
    MutantStack<int> mstack;
    
    mstack.push(5);
    mstack.push(17);
    
    std::cout << "Top element: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;
    
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    std::cout << "Final size: " << mstack.size() << std::endl;
    
    // Test 2: Iterator functionality (the main feature!)
    std::cout << "\n--- Test 2: Iterator functionality ---" << std::endl;
    std::cout << "Iterating through MutantStack: ";
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    
    while (it != ite) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
    
    // Test 3: Forward and backward iteration
    std::cout << "\n--- Test 3: Forward and backward iteration ---" << std::endl;
    std::cout << "Forward iteration: ";
    for (MutantStack<int>::iterator iter = mstack.begin(); iter != mstack.end(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
    
    // Test 4: Comparison with std::list (same functionality)
    std::cout << "\n--- Test 4: Comparison with std::list ---" << std::endl;
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    
    std::cout << "std::list contents: ";
    for (std::list<int>::iterator lit = lst.begin(); lit != lst.end(); ++lit) {
        std::cout << *lit << " ";
    }
    std::cout << std::endl;
    
    // Test 5: Copy constructor
    std::cout << "\n--- Test 5: Copy constructor ---" << std::endl;
    MutantStack<int> copy_stack(mstack);
    std::cout << "Copied stack contents: ";
    for (MutantStack<int>::iterator it2 = copy_stack.begin(); it2 != copy_stack.end(); ++it2) {
        std::cout << *it2 << " ";
    }
    std::cout << std::endl;
    
    // Test 6: Assignment operator
    std::cout << "\n--- Test 6: Assignment operator ---" << std::endl;
    MutantStack<int> assigned_stack;
    assigned_stack.push(99);
    assigned_stack = mstack;
    std::cout << "Assigned stack contents: ";
    for (MutantStack<int>::iterator it3 = assigned_stack.begin(); it3 != assigned_stack.end(); ++it3) {
        std::cout << *it3 << " ";
    }
    std::cout << std::endl;
    
    // Test 7: Const iterator
    std::cout << "\n--- Test 7: Const iterator ---" << std::endl;
    const MutantStack<int> const_stack = mstack;
    std::cout << "Const stack contents: ";
    for (MutantStack<int>::const_iterator cit = const_stack.begin(); cit != const_stack.end(); ++cit) {
        std::cout << *cit << " ";
    }
    std::cout << std::endl;
    
    // Test 8: Different data types
    std::cout << "\n--- Test 8: String MutantStack ---" << std::endl;
    MutantStack<std::string> string_stack;
    string_stack.push("Hello");
    string_stack.push("World");
    string_stack.push("MutantStack");
    
    std::cout << "String stack contents: ";
    for (MutantStack<std::string>::iterator sit = string_stack.begin(); sit != string_stack.end(); ++sit) {
        std::cout << *sit << " ";
    }
    std::cout << std::endl;
    
    // Test 9: Modifying through iterators
    std::cout << "\n--- Test 9: Modifying through iterators ---" << std::endl;
    MutantStack<int> modify_stack;
    modify_stack.push(1);
    modify_stack.push(2);
    modify_stack.push(3);
    
    std::cout << "Before modification: ";
    for (MutantStack<int>::iterator mit = modify_stack.begin(); mit != modify_stack.end(); ++mit) {
        std::cout << *mit << " ";
    }
    std::cout << std::endl;
    
    // Multiply each element by 10
    for (MutantStack<int>::iterator mit = modify_stack.begin(); mit != modify_stack.end(); ++mit) {
        *mit *= 10;
    }
    
    std::cout << "After modification: ";
    for (MutantStack<int>::iterator mit = modify_stack.begin(); mit != modify_stack.end(); ++mit) {
        std::cout << *mit << " ";
    }
    std::cout << std::endl;
    
    // Test 10: Empty stack
    std::cout << "\n--- Test 10: Empty stack ---" << std::endl;
    MutantStack<int> empty_stack;
    std::cout << "Empty stack size: " << empty_stack.size() << std::endl;
    std::cout << "Empty stack begin == end: " << (empty_stack.begin() == empty_stack.end()) << std::endl;
    
    std::cout << "\n=== All tests completed ===" << std::endl;
    return 0;
}