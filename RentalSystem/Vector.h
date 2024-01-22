#pragma once
#ifndef VECTOR_H
#define VECTOR_H
#include<iostream>
#include <cassert>

using namespace std;

template <typename T>
class Vector
{
private:
	T* data; //tablica
	size_t size; // ilosc elementow
	size_t capacity; //pojemnac array

public:
	Vector() : data(nullptr), size(0), capacity(0) {} // konstruktor domyslny

	// konstruktor
	Vector(size_t initialSize, const T& value);

	~Vector();


	void push_back(const T& value);

	Vector& operator=(const Vector& other);

	T& operator[](size_t index);

	size_t get_size() const;


	bool isEmpty() const;

	friend ostream& operator<<(ostream& wy, const Vector<T>& vec);
	friend istream& operator>>(istream& we, Vector<T>& vec) {
		T temp;
		while (we >> temp)
		{
			vec.push_back(temp);
		}
		return we;
	}


};

#endif