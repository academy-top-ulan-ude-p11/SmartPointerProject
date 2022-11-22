#pragma once
template <class T>
class SmartPointerUnique
{
	T* object;
public:
	SmartPointerUnique(T* object = nullptr) : object{ object } {};
	~SmartPointerUnique()
	{
		delete object;
	}

	SmartPointerUnique(SmartPointerUnique<T>& sptr)
	{
		object = sptr.object;
		sptr.object = nullptr;
	}

	SmartPointerUnique<T>& operator=(SmartPointerUnique<T>& sptr)
	{
		if (&sptr == this)
			return *this;

		delete object;
		object = sptr.object;
		sptr.object = nullptr;

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

	bool IsNull()
	{
		return object == nullptr;
	}
};

