#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdio.h>
#include <string>

template <typename T>
class Array
{
	private:
		T* _data;
		unsigned int _size;
	public:
		Array();
		Array(unsigned int size);
		Array(const Array &other);
		Array &operator=(const Array &other);
		const T &operator[](unsigned int index) const;
		T &operator[](unsigned int index);

		unsigned int size() const;
		~Array();
    class OutOfRange : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

/*------------- Creates an empty array---------------------------*/
template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {}

/*------------ Creates an array of n elements initialized by default-----------*/
template <typename T>
Array<T>::Array(unsigned int size) : _data(new T[size]()), _size(size) {}

/*-------------------------------------------------------------*/
template <typename T>
Array<T>::~Array()
{
	delete[] _data;
}
/*---------------------- Contructor by copy------------------*/

template <typename T>
Array<T>::Array(const Array<T> &other) : _data(NULL), _size(0)
{
	*this = other;
}
/*-------------------------------------------------------------*/
template <typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	if (this != &other)
	{
		delete[] _data;
		_size = other._size;
		_data = (_size > 0) ? new T[_size]() : NULL;
		for (size_t i = 0; i < _size; i++)
			_data[i] = other._data[i];
	}
	return *this;
}
/*----------------------------------------------------------*/
template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw OutOfRange(); 
	else
		return _data[index];
}
/*---------------------------------------------------------*/
template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw OutOfRange();
	else
		return _data[index];
}
/*----------------function Size-----------------------------*/
template <typename T>
unsigned int  Array<T>::size() const
{
	return _size;
}
/*--------------Execption----------------------------------*/
template <typename T>
const char*	Array<T>::OutOfRange::what() const throw()
{
	return "Index out of range!";
}


#endif

