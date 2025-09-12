#include "header/Serialize.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Serialize/Deserialize Tests ===" << std::endl << std::endl;
	
	// Test 1: Basic serialization/deserialization
	std::cout << "Test 1: Basic serialize/deserialize" << std::endl;
	{
		Data* original = new Data;
		original->val = 42;
		
		std::cout << "Original Data address: " << original << std::endl;
		std::cout << "Original Data value: " << original->val << std::endl;
		
		// Serialize the pointer to uintptr_t
		uintptr_t serialized = Serialize::serialize(original);
		std::cout << "Serialized value: " << serialized << std::endl;
		
		// Deserialize back to pointer
		Data* deserialized = Serialize::deserialize(serialized);
		std::cout << "Deserialized address: " << deserialized << std::endl;
		std::cout << "Deserialized value: " << deserialized->val << std::endl;
		
		// Verify they point to the same object
		if (original == deserialized) {
			std::cout << "✅ SUCCESS: Pointers match!" << std::endl;
		} else {
			std::cout << "❌ FAIL: Pointers don't match!" << std::endl;
		}
		
		// Verify the values are the same
		if (original->val == deserialized->val) {
			std::cout << "✅ SUCCESS: Values match!" << std::endl;
		} else {
			std::cout << "❌ FAIL: Values don't match!" << std::endl;
		}
		
		delete original;
	}
	std::cout << std::endl;
	
	// Test 2: Multiple Data objects
	std::cout << "Test 2: Multiple Data objects" << std::endl;
	{
		Data* data1 = new Data;
		Data* data2 = new Data;
		data1->val = 100;
		data2->val = 200;
		
		std::cout << "Data1 address: " << data1 << ", value: " << data1->val << std::endl;
		std::cout << "Data2 address: " << data2 << ", value: " << data2->val << std::endl;
		
		uintptr_t ser1 = Serialize::serialize(data1);
		uintptr_t ser2 = Serialize::serialize(data2);
		
		std::cout << "Serialized data1: " << ser1 << std::endl;
		std::cout << "Serialized data2: " << ser2 << std::endl;
		
		Data* deser1 = Serialize::deserialize(ser1);
		Data* deser2 = Serialize::deserialize(ser2);
		
		std::cout << "Deserialized data1: " << deser1 << ", value: " << deser1->val << std::endl;
		std::cout << "Deserialized data2: " << deser2 << ", value: " << deser2->val << std::endl;
		
		bool test1_pass = (data1 == deser1 && data1->val == deser1->val);
		bool test2_pass = (data2 == deser2 && data2->val == deser2->val);
		
		if (test1_pass && test2_pass) {
			std::cout << "✅ SUCCESS: Both objects serialized/deserialized correctly!" << std::endl;
		} else {
			std::cout << "❌ FAIL: Object mismatch!" << std::endl;
		}
		
		delete data1;
		delete data2;
	}
	std::cout << std::endl;
	
	// Test 3: Edge case - NULL pointer
	std::cout << "Test 3: NULL pointer handling" << std::endl;
	{
		Data* nullPtr = NULL;
		
		std::cout << "Original NULL pointer: " << nullPtr << std::endl;
		
		uintptr_t serialized = Serialize::serialize(nullPtr);
		std::cout << "Serialized NULL: " << serialized << std::endl;
		
		Data* deserialized = Serialize::deserialize(serialized);
		std::cout << "Deserialized pointer: " << deserialized << std::endl;
		
		if (nullPtr == deserialized) {
			std::cout << "✅ SUCCESS: NULL pointer handled correctly!" << std::endl;
		} else {
			std::cout << "❌ FAIL: NULL pointer not preserved!" << std::endl;
		}
	}
	std::cout << std::endl;
	
	// Test 4: Different values
	std::cout << "Test 4: Different Data values" << std::endl;
	{
		int test_values[] = {0, -1, 2147483647, -2147483648, 12345};
		int num_tests = sizeof(test_values) / sizeof(test_values[0]);
		
		for (int i = 0; i < num_tests; i++) {
			Data* data = new Data;
			data->val = test_values[i];
			
			std::cout << "Testing value: " << test_values[i] << std::endl;
			
			uintptr_t serialized = Serialize::serialize(data);
			Data* deserialized = Serialize::deserialize(serialized);
			
			bool success = (data == deserialized && data->val == deserialized->val);
			std::cout << (success ? "✅ PASS" : "❌ FAIL") << std::endl;
			
			delete data;
		}
	}
	std::cout << std::endl;
	
	// Test 5: Demonstrate that the serialized value is actually the pointer address
	std::cout << "Test 5: Verify serialized value is pointer address" << std::endl;
	{
		Data* data = new Data;
		data->val = 999;
		
		uintptr_t serialized = Serialize::serialize(data);
		uintptr_t manual_cast = reinterpret_cast<uintptr_t>(data);
		
		std::cout << "Pointer address: " << data << std::endl;
		std::cout << "Serialized value: " << serialized << std::endl;
		std::cout << "Manual reinterpret_cast: " << manual_cast << std::endl;
		
		if (serialized == manual_cast) {
			std::cout << "✅ SUCCESS: Serialized value equals manual cast!" << std::endl;
		} else {
			std::cout << "❌ FAIL: Values don't match!" << std::endl;
		}
		
		delete data;
	}
	
	std::cout << std::endl << "=== All tests completed ===" << std::endl;
	
	return 0;
}
