#pragma once
#include "array.h"

template<typename T>
class List
{
private:
	Array<T>* n_array;
	int n_size;
public:
	List()
		: n_array(new Array<T>(10)), n_size(10) { }
	~List() { delete n_array; }
	
	//copy
	List(const List& other)
		: n_array(other.n_array), n_size(other.n_size) { }
	List& operator=(const List& other)
	{
		return *this = List(other);
	}

	//move
	List(List&& other) noexcept
		: n_array(std::exchange(other.n_array, nullptr)), n_size(std::exchange(other.n_size, nullptr)) { }
	List& operator=(List&& other) noexcept
	{
		std::swap(n_array, other.n_array);
		std::swap(n_size, other.n_size);
		return *this;
	}

	bool operator==(const List& other)
	{
		return n_array == other.n_array;
	}
	
	void add(T t)
	{
		if (n_array->count() >= n_size)
		{
			n_size += 10;
			auto newArray = new Array<T>(n_size);
			for (int i = 0; i < n_array->count(); i++)
			{
				newArray->add(n_array->getAt(i));
			}
			auto temp = n_array;
			n_array = newArray;
			delete temp;
		}
		n_array->add(t);
	}

	int indexOf(const T t)
	{
		return n_array->indexOf(t);
	}

	T get(const T t)
	{
		return n_array->get(t);
	}

	T getAt(int index)
	{
		return n_array->getAt(index);
	}

	void remove(const T t)
	{
		n_array->remove(t);
	}

	void removeAt(int index)
	{
		n_array->removeAt(index);
	}

	int count()
	{
		return n_array->count();
	}
};