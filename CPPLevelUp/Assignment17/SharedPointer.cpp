#include "SharedPointer.h"


template<typename T>
SharedPointer<T>& SharedPointer<T>::operator=(const SharedPointer& rhs) noexcept
{
	if (this != rhs)
	{
		mPointerCount = rhs.mPointerCount;
		mWeakCount = rhs.mWeakCount;

		if (mData)
		{
			delete mData;
			mData = nullptr;
		}

		mData = new T[mPointerCount];

		for (unsigned int i = 0; i < mPointerCount; ++i)
		{
			mData[i] = rhs.mData[i];
		}
	}

	return *this;
}

template<typename T>
SharedPointer<T>& SharedPointer<T>::operator=(SharedPointer<T>&& rhs) noexcept
{
	if (this != rhs)
	{
		delete mData;

		mData = rhs.mData;
		mPointerCount = rhs.mPointerCount;
		mWeakCount = rhs.mWeakCount;

		rhs.mData = nullptr;
		rhs.mPointerCount = 0;
		rhs.mWeakCount = 0;
	}

	return *this;
}

template<typename T>
void SharedPointer<T>::Release()
{
	--mPointerCount;

	if (mData && mPointerCount == 0)
	{
		delete[] mData;
		mData = nullptr;
	}
}

template<typename T>
void SharedPointer<T>::Reset()
{

}

template<typename T>
void SharedPointer<T>::Swap(SharedPointer rhs)
{

}