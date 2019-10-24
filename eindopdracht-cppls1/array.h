#pragma once
#include <type_traits>

template <typename T>
class Array
{
	//static_assert(std::is_pointer<T>::value, "Array requires a pointer type");

private:
	T* n_array;
	int n_size;
	int n_count;

public:
	Array(const int size)
	: n_array(new T[size]), n_size(size), n_count(0) { }
	~Array()
	{
		for (int i = 0; i < n_count; i++)
		{
			delete (toPointer(n_array[i]));
		}
		
		delete[] n_array;
	}

	//copy
	Array(const Array& other)
	{
		*this = other;
	}
	Array& operator=(const Array& other)
	{
		delete[] n_array;
		n_size = other.n_size;
		n_count = other.n_count;
		n_array = new T[n_size];
		for (int i = 0; i < n_count; i++)
		{
			n_array[i] = other.n_array[i];
		}
		return *this;
	}

	//move
	Array(Array&& other) noexcept
	{
		*this = other;
	}
	Array& operator=(Array&& other) noexcept
	{
		delete[] n_array;
		n_size = other.n_size;
		n_count = other.n_count;
		n_array = new T[n_size];
		for (int i = 0; i < n_count; i++)
		{
			n_array[i] = other.n_array[i];
		}
		return *this;
	}

	//pointer parsers
	template<typename P>
	static P* toPointer(P& p)
	{
		return &p;
	}
	template<typename P>
	static P* toPointer(P* p)
	{
		return p;
	}
	
	bool operator==(const Array& other)
	{
		if(n_count == other.n_count)
		{
			for (int i = 0; i < n_count; i++)
			{
				if (n_array[i] != other.n_array[i])
				{
					return false;
				}
			}
			return true;
		}
		return false;
	}

	void add(const T t)
	{
		if (n_count < n_size)
		{
			n_array[n_count] = t;
			n_count++;
		}
		else
		{
			throw; //throw array full exception
		}
	}

	int indexOf(const T t)
	{
		for (int i = 0; i < n_count; i++)
		{
			if (*toPointer(n_array[i]) == *toPointer(t))
			{
				return i;
			}
		}
		throw; //object not found exception
	}

	T get(const T t)
	{
		return getAt(indexOf(t));
	}

	T getAt(const int index)
	{
		if (n_count > index)
		{
			return n_array[index];
		}
		else
		{
			throw; //throw index out of bounds exception
		}
	}

	void remove(const T t)
	{
		removeAt(indexOf(t));
	}
	
	void removeAt(const int index)
	{
		if (n_count > index)
		{
			for (int i = index + 1; i < n_count; i++)
			{
				n_array[i - 1] = n_array[i];
			}
			n_count--;
		}
		else
		{
			throw; //throw index out of bounds exception
		}
	}

	bool contains(const T t)
	{
		for (int i = 0; i < n_count; i++)
		{
			if (*toPointer(n_array[i]) == *toPointer(t))
			{
				return i;
			}
		}
		return false;
	}

	int count() const
	{
		return n_count;
	}

	int size() const
	{
		return n_size;
	}
};
