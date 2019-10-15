#pragma once

template <typename T>
class Array
{
private:
	T* n_array;
	const int n_size;
	int n_count;

public:
	Array(const int size)
	: n_array(new T[size]), n_size(size), n_count(0) { }
	~Array() { delete[] n_array; }

	//copy
	Array(const Array& other)
	: n_array(new T[other.n_size]), n_size(other.n_size), n_count(other.n_count) { std::copy(other.n_array, other.n_array + other.n_count, n_array); }
	Array& operator=(const Array& other)
	{
		return *this = Array(other);
	}

	//move
	Array(Array&& other) noexcept
	: n_array(std::exchange(other.n_array, nullptr)), n_size(std::exchange(other.n_size, nullptr)), n_count(std::exchange(other.n_count, nullptr)) { }
	Array& operator=(Array&& other) noexcept
	{
		std::swap(n_array, other.n_array);
		std::swap(n_size, other.n_size);
		std::swap(n_count, other.n_count);
		return *this;
	}

	bool operator==(const Array* other)
	{
		if(n_count != other->n_count)
		{
			for (int i = 0; i < n_count; i++)
			{
				if (n_array[i] != other->n_array[i])
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
			if (n_array[i] == t)
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

	T getAt(int index)
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

	int count() const
	{
		return n_count;
	}
};
