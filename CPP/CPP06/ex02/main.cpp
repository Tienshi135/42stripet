#include "header/Base.hpp"
#include "header/A.hpp"
#include "header/B.hpp"
#include "header/C.hpp"
#include <iostream>
#include <cstdlib>

int main()
{
	std::cout << "=== Ex02 Dynamic Cast Tests ===" << std::endl << std::endl;
	
	Base base;
	
	// Test 2: Test identify() with pointers - create known objects
	std::cout << "Test 2: Testing identify() with pointers on known objects" << std::endl;
	{
		A* a = new A();
		B* b = new B();
		C* c = new C();
		
		std::cout << "Identifying A object: ";
		base.identify(a);
		std::cout << "Identifying B object: ";
		base.identify(b);
		std::cout << "Identifying C object: ";
		base.identify(c);
		
		delete a;
		delete b;
		delete c;
	}
	std::cout << std::endl;
	
	// Test 3: Test identify() with references - create known objects
	std::cout << "Test 3: Testing identify() with references on known objects" << std::endl;
	{
		A a;
		B b;
		C c;
		
		std::cout << "Identifying A object by reference: ";
		base.identify(a);
		std::cout << "Identifying B object by reference: ";
		base.identify(b);
		std::cout << "Identifying C object by reference: ";
		base.identify(c);
	}
	std::cout << std::endl;
	
	// Test 4: Test polymorphism - Base pointers pointing to derived objects
	std::cout << "Test 4: Testing polymorphism with Base pointers" << std::endl;
	{
		Base* objects[6];
		objects[0] = new A();
		objects[1] = new B();
		objects[2] = new C();
		objects[3] = new A();
		objects[4] = new B();
		objects[5] = new C();
		
		for (int i = 0; i < 6; i++) {
			std::cout << "Object " << i + 1 << " (Base*): ";
			base.identify(objects[i]);
		}
		
		for (int i = 0; i < 6; i++) {
			delete objects[i];
		}
	}
	std::cout << std::endl;
	
	// Test 5: Test polymorphism - Base references to derived objects
	std::cout << "Test 5: Testing polymorphism with Base references" << std::endl;
	{
		A a;
		B b;
		C c;
		
		Base& ref_a = a;
		Base& ref_b = b;
		Base& ref_c = c;
		
		std::cout << "A object via Base reference: ";
		base.identify(ref_a);
		std::cout << "B object via Base reference: ";
		base.identify(ref_b);
		std::cout << "C object via Base reference: ";
		base.identify(ref_c);
	}
	std::cout << std::endl;
	
	// Test 6: Test with NULL pointer (edge case)
	std::cout << "Test 6: Testing with NULL pointer (edge case)" << std::endl;
	{
		Base* null_ptr = NULL;
		std::cout << "Identifying NULL pointer: ";
		base.identify(null_ptr);
		std::cout << "(Should print nothing or handle gracefully)" << std::endl;
	}
	std::cout << std::endl;
	
	// Test 8: Generate and identify random objects in a loop
	std::cout << "Test 8: Generate and identify random objects (stress test)" << std::endl;
	{
		int count_a = 0, count_b = 0, count_c = 0;
		
		for (int i = 0; i < 20; i++) {
			Base* obj = base.generate();
			
			// Count the types for statistics
			A* test_a = dynamic_cast<A*>(obj);
			B* test_b = dynamic_cast<B*>(obj);
			C* test_c = dynamic_cast<C*>(obj);
			
			if (test_a) count_a++;
			else if (test_b) count_b++;
			else if (test_c) count_c++;
			
			std::cout << "Object " << (i + 1) << ": ";
			base.identify(obj);
			
			delete obj;
		}
		
		std::cout << "Statistics: A=" << count_a << ", B=" << count_b << ", C=" << count_c << std::endl;
	}
	
	std::cout << std::endl << "=== All tests completed ===" << std::endl;
	
	return 0;
}
