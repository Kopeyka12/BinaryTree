#pragma once
template <class T>
class Iterator
{
protected:
	int iterComplete;
public:
	Iterator();
	virtual void Next() = 0;
	virtual void Reset() = 0;

	virtual T& Data() = 0;
	virtual int EndOf() const;
};
template <class T>
	Iterator<T>::Iterator() : iterComplete(0) {};