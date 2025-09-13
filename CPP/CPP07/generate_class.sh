#!/bin/bash

# Script to generate C++ class files with Orthodox Canonical Form
# Usage: ./generate_class.sh ex00 ClassName

if [ $# -ne 2 ]; then
	echo "Usage: $0 <exercise> <ClassName>"
	echo "Example: $0 ex00 MyClass"
	exit 1
fi

EXERCISE=$1
CLASS_NAME=$2

# Check if exercise directory exists
if [ ! -d "$EXERCISE" ]; then
	echo "Error: Exercise directory '$EXERCISE' does not exist"
	exit 1
fi

# Create header and src directories if they don't exist
mkdir -p "$EXERCISE/header"
mkdir -p "$EXERCISE/src"

HEADER_FILE="$EXERCISE/header/$CLASS_NAME.hpp"
SOURCE_FILE="$EXERCISE/src/$CLASS_NAME.cpp"

# Generate header file
cat > "$HEADER_FILE" << EOF
#pragma once

#include <iostream>

class $CLASS_NAME
{
private:

public:
	$CLASS_NAME();
	$CLASS_NAME(const $CLASS_NAME &copy);
	$CLASS_NAME &operator=(const $CLASS_NAME &copy);
	~$CLASS_NAME();

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
};

EOF

# Generate source file
cat > "$SOURCE_FILE" << EOF
#include "$CLASS_NAME.hpp"

$CLASS_NAME::$CLASS_NAME()
{
	std::cout << "$CLASS_NAME default constructor called" << std::endl;
}

$CLASS_NAME::$CLASS_NAME(const $CLASS_NAME &copy)
{
	std::cout << "$CLASS_NAME copy constructor called" << std::endl;
	*this = copy;
}

$CLASS_NAME &$CLASS_NAME::operator=(const $CLASS_NAME &copy)
{
	std::cout << "$CLASS_NAME assignment operator called" << std::endl;
	if (this != &copy)
	{

	}
	return *this;
}

$CLASS_NAME::~$CLASS_NAME()
{
	std::cout << "$CLASS_NAME destructor called" << std::endl;
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
EOF

echo "Generated files:"
echo "  Header: $HEADER_FILE"
echo "  Source: $SOURCE_FILE"
echo ""
echo "Files created successfully!"
echo ""
echo "Don't forget to:"
echo "1. Add your member variables to the private section in the header"
echo "2. Implement proper copying logic in the assignment operator"
echo "3. Add any additional member functions you need"
echo "4. Update the Makefile to include the new source file"
