#pragma once
#include "list.h"

template<typename K, typename V>
class Dictionary
{
	
private:
	List<K>* n_keys = nullptr;
	List<V>* n_values = nullptr;
	
public:
	Dictionary()
		: n_keys(new List<K>()), n_values(new List<V>())
	{
		
	}
	~Dictionary()
	{
		delete n_keys;
		delete n_values;
	}

	//copy
	Dictionary(const Dictionary& other)
	{
		*this = other;
	}
	Dictionary& operator=(const Dictionary& other)
	{
		delete n_keys;
		if (other.n_keys)
		{
			n_keys = new List<K>(*other.n_keys);
		}
		
		delete n_values;
		if (other.n_values)
		{
			n_values = new List<V>(*other.n_values);
		}
		
		return *this;
	}

	//move
	Dictionary(Dictionary&& other) noexcept
	{
		*this = std::move(other);
	}
	Dictionary& operator=(Dictionary&& other) noexcept
	{
		delete n_keys;
		n_keys = new List<K>(*other.n_keys);
		other.n_keys = nullptr;
		
		delete n_values;
		n_values = new List<V>(*other.n_values);
		other.n_values = nullptr;
		
		return *this;
	}
	
	bool operator==(const Dictionary* other)
	{
		return *this == *other;
	}
	bool operator==(const Dictionary& other)
	{
		return ((n_keys == other.n_keys) && (n_values == other.n_values));
	}

	void add(const K& k, const V& v)
	{
		n_keys->add(k);
		n_values->add(v);
	}
	void add(const K& k, V& v)
	{
		n_keys->add(k);
		n_values->add(v);
	}
	void add(K& k, const V& v)
	{
		n_keys->add(k);
		n_values->add(v);
	}
	void add(K& k, V& v)
	{
		n_keys->add(k);
		n_values->add(v);
	}
	
	V& get(const K& k)
	{
		return getValueAt(n_keys->indexOf(k));
	}
	V& get(K& k)
	{
		return getValueAt(n_keys->indexOf(k));
	}
	K& getKeyAt(const int index) const
	{
		return n_keys->getAt(index);
	}
	V& getValueAt(const int index) const
	{
		return n_values->getAt(index);
	}
	
	void remove(const K& k)
	{
		removeAt(n_keys->indexOf(k));
	}
	void remove(K& k)
	{
		removeAt(n_keys->indexOf(k));
	}
	void removeAt(const int index)
	{
		n_keys->removeAt(index);
		n_values->removeAt(index);
	}
	
	bool contains(const K& k)
	{
		return n_keys->contains(k);
	}
	bool contains(K& k)
	{
		return n_keys->contains(k);
	}

	int count() const
	{
		return n_keys->count();
	}

	List<K> getKeys() const
	{
		return *n_keys;
	}
	List<V> getValues() const
	{
		return *n_values;
	}
};
