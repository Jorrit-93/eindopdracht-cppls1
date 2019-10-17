#pragma once
#include "list.h"

template<typename K, typename V>
class Dictionary
{
private:
	List<K>* n_key;
	List<V>* n_value;
	
public:
	Dictionary() : n_key(new List<K>()), n_value(new List<V>()) { }
	~Dictionary() { delete n_key; delete n_value; }

	//copy
	Dictionary(const Dictionary& other)
	{
		*this = other;
	}
	Dictionary& operator=(const Dictionary& other)
	{
		delete n_key;
		delete n_value;
		n_key = new List<K>();
		n_value = new List<V>();
		for (int i = 0; i < other.getKeys()->count(); i++)
		{
			n_key->add(other.getKeys()->getAt(i));
			n_value->add(other.getValues()->getAt(i));
		}
		return *this;
	}

	//move
	Dictionary(Dictionary&& other) noexcept
	{
		*this = other;
	}
	Dictionary& operator=(Dictionary&& other) noexcept
	{
		delete n_key, n_value;
		n_key = new List<K>();
		n_value = new List<V>();
		for (int i = 0; i < other.getKeys()->count(); i++)
		{
			n_key->add(other.getKeys()->getAt(i));
			n_value->add(other.getValues()->getAt(i));
		}
		return *this;
	}

	bool operator==(const Dictionary& other)
	{
		return ((*n_key == *other.n_key) && (*n_value == *other.n_value));
	}

	void add(K k, V v)
	{
		n_key->add(k);
		n_value->add(v);
	}

	V get(const K k)
	{
		int index = n_key->indexOf(k);
		return n_value->getAt(index);
	}

	void remove(const K k)
	{
		int index = n_key->indexOf(k);
		n_key->removeAt(index);
		n_value->removeAt(index);
	}

	List<K>* getKeys() const
	{
		return n_key;
	}

	List<V>* getValues() const
	{
		return n_value;
	}
};
