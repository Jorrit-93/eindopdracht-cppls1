#pragma once
#include "array.h"

template<typename T>
class List
{
	
private:
	Array<T>* n_array = nullptr;
	
public:
	List()
		: n_array(new Array<T>(10))
	{
		
	}
	~List()
	{
		delete n_array;
	}
	
	//copy
	List(const List<T>& other)
	{
		*this = other;
	}
	List<T>& operator=(const List<T>& other)
	{
		delete n_array;
		if (other.n_array)
		{
			n_array = new Array<T>(*other.n_array);
		}
		
		return *this;
	}

	//move
	List(List<T>&& other) noexcept
	{
		*this = std::move(other);
	}
	List<T>& operator=(List<T>&& other) noexcept
	{
		delete n_array;
		n_array = other.n_array;
		other.n_array = nullptr;
		
		return *this;
	}

	bool operator==(const List* other)
	{
		return *this == *other;
	}
	bool operator==(const List& other)
	{
		return (n_array == other.n_array);
	}

	void add(const T& t)
	{
		if (n_array->count() >= n_array->size())
		{
			n_array->addSize(10);
		}
		n_array->add(t);
	}
	void add(T& t)
	{
		if (n_array->count() >= n_array->size())
		{
			n_array->addSize(10);
		}
		n_array->add(t);
	}

	int indexOf(const T& t)
	{
		return n_array->indexOf(t);
	}
	int indexOf(T& t)
	{
		return n_array->indexOf(t);
	}

	T& get(const T& t)
	{
		return getAt(indexOf(t));
	}
	T& get(T& t)
	{
		return getAt(indexOf(t));
	}
	T& getAt(const int index) const
	{
		return n_array->getAt(index);
	}
	
	void remove(const T& t)
	{
		removeAt(indexOf(t));
	}
	void remove(T& t)
	{
		removeAt(indexOf(t));
	}
	void removeAt(const int index)
	{
		n_array->removeAt(index);
	}
	
	bool contains(const T& t)
	{
		return n_array->contains(t);
	}
	bool contains(T& t)
	{
		return n_array->contains(t);
	}

	int count() const
	{
		return n_array->count();
	}

	Array<T> toArray()
	{
		return *n_array;
	}
};