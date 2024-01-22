#include "Vector.h"
#include "User.h"
#include "RentedCar.h"
#include "Car.h"
using namespace std;


template <typename T>
Vector<T>::Vector(size_t initialSize, const T& value) : size(initialSize), capacity(initialSize) {
	data = new T[capacity];
	for (size_t i = 0; i < size; ++i) {
		data[i] = value; // tworzymy array z nowymi danymi
	}
}

template <typename T>
Vector<T>::~Vector()
{
	delete[] data;
}


template <typename T>

void Vector<T>::push_back(const T& value) {
	if (size == capacity) {
		// 
		capacity = (capacity == 0) ? 1 : capacity * 2;
		T* newData = new T[capacity]; // 
		for (size_t i = 0; i < size; ++i) {
			newData[i] = data[i]; //
		}
		delete[] data; //
		data = newData; // 
	}
	data[size++] = value; // 
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& other)
{
	if (this != &other) {
		delete[] data;
		size = other.size; // 
		capacity = other.capacity;
		data = new T[capacity];
		for (size_t i = 0; i < size; ++i) {
			data[i] = other.data[i]; // 
		}
	}
	return *this;
}

template <typename T>

T& Vector<T>::operator[](size_t index) {
	if (index >= size) {
		throw std::out_of_range("Index out of range");
	}
	return data[index]; // 
}

template <typename T>

size_t Vector<T>::get_size() const
{
	return size;
}

template <typename T>

bool Vector<T>::isEmpty() const {
	return size == 0;
}

template <typename T>

ostream& operator<<(ostream& wy, const Vector<T>& vec)
{
	for (size_t i = 0; i < vec.size; i++)
	{
		wy << vec.data[i];
	}
	return wy;
}

//template <typename T>

//istream& operator>>(istream& we, Vector<T>& vec)
//{
//	T temp;
//	while (we >> temp)
//	{
//		vec.push_back(temp);
//	}
//	return we;
//}

template class Vector<User>;
template class Vector<RentedCar>;
template class Vector<Car>;