#pragma once
#include <type_traits>

template <typename T>
class Array
{
	static_assert(!std::is_pointer<T>::value, "No pointer types permitted");

private:
	T* n_array = nullptr;
	int n_size;
	int n_count;

public:
	Array(const int size)
	: n_array(new T[size]), n_size(size), n_count(0)
	{
		
	}
	~Array()
	{
		delete[] n_array;
	}

	//copy
	Array(const Array<T>& other)
	{
		*this = other;
	}
	Array<T>& operator=(const Array<T>& other)
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
	Array(Array<T>&& other) noexcept
	{
		*this = other;
	}
	Array<T>& operator=(Array<T>&& other) noexcept
	{
		delete[] n_array;
		n_size = other.n_size;
		n_count = other.n_count;
		n_array = new T[n_size];
		for (int i = 0; i < n_count; i++)
		{
			n_array[i] = other.n_array[i];
		}
		delete *other;
		return *this;
	}
	
	bool operator==(const Array* other)
	{
		return *this == *other;
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

	void add(const T* t)
	{
		add(*t);
	}
	void add(const T& t)
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

	int indexOf(const T* t)
	{
		return indexOf(*t);
	}
	int indexOf(const T& t)
	{
		for (int i = 0; i < n_count; i++)
		{
			if (n_array[i] == t)
			{
				return i;
			}
		}
		throw; //object not found exception
	}

	T& get(const T* t)
	{
		return get(*t);
	}
	T& get(const T& t)
	{
		return getAt(indexOf(t));
	}
	T getAt(const int index)
	{
		if (n_count > index)
		{
			return T(n_array[index]);
		}
		else
		{
			throw; //throw index out of bounds exception
		}
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

	bool contains(const T* t)
	{
		return contains(*t);
	}
	bool contains(const T& t)
	{
		for (int i = 0; i < n_count; i++)
		{
			if (n_array[i] == t)
			{
				return true;
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
