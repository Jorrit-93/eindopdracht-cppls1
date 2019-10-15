#pragma once

template <typename T>
class Array
{
private:
	T* narray;
	const int nsize;
	int ncount;
	
public:
	Array(const int size) : narray(new T[size]), nsize(size), ncount(0) { }

	void Add(T t)
	{
		if (ncount < nsize)
		{
			narray[ncount] = t;
			ncount++;
		}
		else
		{
			throw; //throw array full exception
		}
	}
	
	T Get(int index)
	{
		if (ncount > index)
		{
			return narray[index];
		}
		else
		{
			throw; //throw index out of bounds exception
		}
	}
	
	void Remove(int index)
	{
		if (ncount > index)
		{
			for (int i = index + 1; i < ncount; i++)
			{
				narray[i - 1] = narray[i];
			}
			ncount--;
		}
		else
		{
			throw; //throw index out of bounds exception
		}
	}
	
	int Count() const
	{
		return ncount;
	}
};
