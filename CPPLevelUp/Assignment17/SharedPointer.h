#pragma once
#include <functional>

template<typename T>
class SharedPointer
{
public:
	SharedPointer<T>()	noexcept {}
	SharedPointer<T>(T* data) : mData(data) {}
	~SharedPointer<T>() { Release(); }

	T& operator[](int index) const { return Get()[index]; }
	T& operator* () const	{ return *mData; }
	T* operator-> () const	{ return mData; }

	SharedPointer& operator=(const SharedPointer<T>& rhs) noexcept;
	SharedPointer& operator=(SharedPointer<T>&& rhs) noexcept;

	void Release();
	void Reset();
	void Swap(SharedPointer rhs);

	unsigned int Count() const	{ return mPointerCount; }
	T* Get() const noexcept		{ return mData; }

private:
	T* mData = nullptr;

	unsigned int mPointerCount = 0;
	unsigned int mWeakCount = 0;
};