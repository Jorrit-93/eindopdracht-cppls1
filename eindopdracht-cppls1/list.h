#pragma once
#include "array.h"

template<typename T>
class List
{
protected:
	Array<T>* n_array;
	
public:
	List()
		: n_array(new Array<T>(10)) { }
	~List() { delete n_array; }
	
	//copy
	List(const List& other)
	{
		*this = other;
	}
	List& operator=(const List& other)
	{
		delete n_array;
		n_array = new Array<T>(other.size());
		for (int i = 0; i < other.count(); i++)
		{
			n_array->add(other.getAt(i));
		}
		return *this;
	}

	//move
	List(List&& other) noexcept
	{
		*this = other;
	}
	List& operator=(List&& other) noexcept
	{
		delete n_array;
		n_array = new Array<T>(other.size());
		for (int i = 0; i < other.count(); i++)
		{
			n_array->add(other->getAt(i));
		}
		return *this;
	}

	bool operator==(const List& other)
	{
		return (*n_array == *other.n_array);
	}
	
	void add(T t)
	{
		if (n_array->count() >= n_array->size())
		{
			auto newArray = new Array<T>(n_array->size() + 10);
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

	T getAt(const int index) const
	{
		return n_array->getAt(index);
	}

	void remove(const T t)
	{
		n_array->remove(t);
	}

	void removeAt(const int index)
	{
		n_array->removeAt(index);
	}

	int count() const
	{
		return n_array->count();
	}

	Array<T>& toArray()
	{
		return *n_array;
	}
};