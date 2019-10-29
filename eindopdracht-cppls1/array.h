#pragma once
#include <type_traits>

template <typename T>
class Array
{
	using type = T;
	
private:
	type* n_array = nullptr;
	int n_size;
	int n_count;

public:
	Array(const int size)
		: n_array(new type[size]), n_size(size), n_count(0)
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
		n_array = new type[n_size];
		for (int i = 0; i < n_count; i++)
		{
			n_array[i] = other.n_array[i];
		}
		return *this;
	}

	//move
	Array(Array<T>&& other) noexcept
	{
		delete[] n_array;
		n_count = other.n_count;
		n_array = other.n_array;
		other.n_array = nullptr;
	}
	Array<T>& operator=(Array<T>&& other) noexcept
	{
		delete[] n_array;
		n_count = other.n_count;
		n_array = other.n_array;
		other.n_array = nullptr;
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

	void add(const type& t)
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
	void add(type& t)
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

	int indexOf(const type& t)
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
	int indexOf(type& t)
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

	type& get(const type& t)
	{
		return getAt(indexOf(t));
	}
	type& get(type& t)
	{
		return getAt(indexOf(t));
	}
	type& getAt(const int index) const
	{
		if (n_count > index)
		{
			return n_array[index];
		}
		throw; //throw index out of bounds exception
	}

	void remove(const type& t)
	{
		removeAt(indexOf(t));
	}
	void remove(type& t)
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

	bool contains(const type& t)
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
	bool contains(type& t)
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

	void addSize(const int size)
	{
		n_size += size;
		auto new_array = new type[n_size];
		for (int i = 0; i < n_count; i++)
		{
			new_array[i] = n_array[i];
		}
		delete[] n_array;
		n_array = nullptr;
		n_array = std::move(new_array);
	}
};

template <typename T>
class Array<T*>
{
	using type = typename std::add_pointer<T>::type;

private:
	type* n_array = nullptr;
	int n_size;
	int n_count;

public:
	Array(const int size)
		: n_array(new type[size]), n_size(size), n_count(0)
	{

	}
	~Array()
	{
		for (int i = 0; i < n_count; i++)
		{
			delete n_array[i];
		}
		delete[] n_array;
	}

	//copy
	Array(const Array<T*>& other)
	{
		*this = other;
	}
	Array<T*>& operator=(const Array<T*>& other)
	{
		delete[] n_array;
		n_size = other.n_size;
		n_count = other.n_count;
		n_array = new type[n_size];
		for (int i = 0; i < n_count; i++)
		{
			n_array[i] = new T(*other.n_array[i]);
		}
		return *this;
	}

	//move
	Array(Array<T*>&& other) noexcept
	{
		*this = std::move(other);
	}
	Array<T*>& operator=(Array<T*>&& other) noexcept
	{
		delete[] n_array;
		n_count = other.n_count;
		n_array = other.n_array;
		other.n_array = nullptr;
		return *this;
	}

	bool operator==(const Array* other)
	{
		return *this == *other;
	}

	bool operator==(const Array& other)
	{
		if (n_count == other.n_count)
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
	
	void add(const type& t)
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
	void add(type& t)
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
	
	int indexOf(const type& t)
	{
		for (int i = 0; i < n_count; i++)
		{
			if (*n_array[i] == *t)
			{
				return i;
			}
		}
		throw; //object not found exception
	}
	int indexOf(type& t)
	{
		for (int i = 0; i < n_count; i++)
		{
			if (*n_array[i] == *t)
			{
				return i;
			}
		}
		throw; //object not found exception
	}
	
	type& get(const type& t)
	{
		return getAt(indexOf(t));
	}
	type& get(type& t)
	{
		return getAt(indexOf(t));
	}
	type& getAt(const int index) const 
	{
		if (n_count > index)
		{
			return n_array[index];
		}
		throw; //throw index out of bounds exception
	}
	
	void remove(const type& t)
	{
		removeAt(indexOf(t));
	}
	void remove(type& t)
	{
		removeAt(indexOf(t));
	}
	void removeAt(const int index)
	{
		if (n_count > index)
		{
			delete n_array[index];
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
	
	bool contains(const type& t)
	{
		for (int i = 0; i < n_count; i++)
		{
			if (*n_array[i] == *t)
			{
				return true;
			}
		}
		return false;
	}
	bool contains(type& t)
	{
		for (int i = 0; i < n_count; i++)
		{
			if (*n_array[i] == *t)
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

	void addSize(const int size)
	{
		n_size += size;
		auto new_array = new type[n_size];
		for (int i = 0; i < n_count; i++)
		{
			new_array[i] = new T(*n_array[i]);
			delete n_array[i];
		}
		delete[] n_array;
		n_array = nullptr;
		n_array = std::move(new_array);
	}
};

