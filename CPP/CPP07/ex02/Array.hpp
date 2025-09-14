#pragma once

#include <stdexcept>

template <typename T>
class Array {
	private:
		size_t	_size;
		T		*_data;
	public:
	Array() : _size(0), _data(NULL) {}
	Array(unsigned int n) : _size(n), _data(new T[n]()) {}
	Array(const Array &copy) : _size(copy._size), _data(new T[copy._size]())
	{
		for (size_t i = 0; i < _size; i++)
			this->_data[i] = copy._data[i];
	}
	Array &operator=(const Array &copy)
	{
		if (this != &copy) {
			if (this->_data)
				delete[] this->_data;
			this->_size = copy._size;
			this->_data = new T[this->_size]();
			for (size_t i = 0; i < this->_size; i++)
				this->_data[i] = copy._data[i];
		}
		return *this;
	}
	~Array() {delete[] this->_data;}

	T &operator[](size_t index)
	{
		if (index >= this->_size)
			throw std::out_of_range("Index out of bounds");
		return this->_data[index];
	}
	const T &operator[](size_t index) const
	{
		if (index >= this->_size)
			throw std::out_of_range("Index out of bounds");
		return this->_data[index];
	}
	size_t	size() const {return _size;};
};