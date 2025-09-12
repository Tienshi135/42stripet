#pragma once

#include <iostream>
#include <stdint.h>

typedef struct Data
{
	int	val;
}	Data;

class Serialize
{
private:
	Serialize();
	Serialize(const Serialize &copy);
	Serialize &operator=(const Serialize &copy);
	~Serialize();
public:
	static uintptr_t	serialize(Data* ptr);
	static Data			*deserialize(uintptr_t raw);
};

