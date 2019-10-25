#pragma once
#include <type_traits>
#include "array.h"

template<typename T>
class List
{
	static_assert(!std::is_pointer<T>::value, "No pointer types permitted");
	
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
		n_array = new Array<T>(*other.n_array);
		return *this;
	}

	//move
	List(List<T>&& other) noexcept
	{
		*this = other;
	}
	List<T>& operator=(List<T>&& other) noexcept
	{
		delete n_array;
		n_array = new Array<T>(*other.n_array);
		delete *other;
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

	void add(const T* t)
	{
		add(*t);
	}
	void add(const T& t)
	{
		if (n_array->count() >= n_array->size())
		{
			auto newArray = new Array<T>(n_array->size() + 10);
			for (int i = 0; i < n_array->count(); i++)
			{
				newArray->add(n_array->getAt(i));
			}
			delete n_array;
			n_array = newArray;
		}
		n_array->add(t);
	}

	int indexOf(const T* t)
	{
		return indexOf(*t);
	}
	int indexOf(const T& t)
	{
		return n_array->indexOf(t);
	}

	T& get(const T* t)
	{
		return get(*t);
	}
	T& get(const T& t)
	{
		return getAt(indexOf(t));
	}
	T& getAt(const int index) const
	{
		return n_array->getAt(index);
	}

	void remove(const T* t)
	{
		remove(*t);
	}
	void remove(const T& t)
	{
		removeAt(indexOf(t));
	}
	void removeAt(const int index)
	{
		n_array->removeAt(index);
	}
	
	bool contains(const T* t)
	{
		return contains(*t);
	}
	bool contains(const T& t)
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