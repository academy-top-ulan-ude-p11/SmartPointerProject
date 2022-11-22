#pragma once
template <class T>
class SmartPointerShare
{
	T* object;
	static int count;
public:
	SmartPointerShare(T* object = nullptr) 
		: object{ object } {};

	SmartPointerShare(const SmartPointerShare<T>& sptr)
	{
		object = sptr.object;
		count++;
	}

	~SmartPointerShare()
	{
		if (count > 1)
			count--;
		else
			delete object;
	}

	SmartPointerShare<T>& operator=(const SmartPointerShare<T>& sptr)
	{
		if (&sptr == this)
			return *this;

		object = sptr.object;
		count++;
		return *this;
	}

	T& operator*() const
	{
		return *object;
	}
	T* operator->() const
	{
		return object;
	}

	static int Count()
	{
		return count;
	}

	bool IsNull()
	{
		return object == nullptr;
	}
};

template <class T>
int SmartPointerShare<T>::count = 1;

