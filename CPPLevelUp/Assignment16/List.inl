#include "List.h"
namespace Storage
{
	template<class T>
	List<T>::~List()
	{
		while (pHead != nullptr)
		{
			Node<T>* pCurrent = pHead;
			pHead = pHead->pNext;

			delete pCurrent;
			pCurrent = nullptr;
		}
	}

	template<class T>
	List<T>& List<T>::operator=(const List& rhs)
	{
		mCount = rhs.mCount;
		
		List::Node* currentNode = rhs.pHead;
		pHead = new List::Node();
		List::Node* tempNode = pHead;

		while (currentNode != nullptr)
		{

		}
	}

	template<class T>
	List<T>& List<T>::operator=(List&& rhs)
	{
		pHead = nullptr;

		mCount = rhs.mCount;
		pHead = rhs.pHead;

		rhs.pHead = nullptr;
		rhs.mCount = 0;
	}

	// ----------------------------------------------------------------------------------------------------

	template<class T>
	void List<T>::Add(const T& item)
	{
		Node<T>* pEnd = pHead;
		Node<T>* pCurrent = pHead;

		while (pCurrent != nullptr)
		{
			pEnd = pCurrent;
			pCurrent = pCurrent->pNext;
		}

		CreateNode(pEnd, item);
	}

	// ----------------------------------------------------------------------------------------------------

	template<class T>
	void List<T>::Remove(const T& item)
	{
		Node<T>* pCurrent = pHead;
		Node<T>* pPrevious = nullptr;

		while (pCurrent != nullptr)
		{
			if (pCurrent->Item == item)
			{
				RemoveNode(pCurrent, pPrevious);
				break;
			}

			pPrevious = pCurrent;
			pCurrent = pCurrent->pNext;
		}
	}

	// ----------------------------------------------------------------------------------------------------

	template<class T>
	void List<T>::RemoveAt(int index)
	{
		Node<T>* pCurrent = pHead;
		Node<T>* pPrevious = nullptr;

		int currentIndex = 0;
		while (pCurrent != nullptr)
		{
			if (currentIndex == index)
			{
				RemoveNode(pCurrent, pPrevious);
				break;
			}

			pPrevious = pCurrent;
			pCurrent = pCurrent->pNext;
		}
	}

	// ----------------------------------------------------------------------------------------------------

	template<class T>
	void List<T>::Clear()
	{
		while (pHead != nullptr)
		{
			Node<T>* pCurrent = pHead;
			pHead = pHead->pNext;
			delete pCurrent;
		}
	}

	// ----------------------------------------------------------------------------------------------------

	template<class T>
	T& List<T>::operator[](int index)
	{
		Node<T>* pCurrent = pHead;
		for (int i = 0; i < index; ++i)
		{
			pCurrent = pCurrent->pNext;
		}

		return pCurrent->Item;
	}

	// ----------------------------------------------------------------------------------------------------

	template<class T>
	void List<T>::CreateNode(Node<T>* pEnd, const T& item)
	{
		Node<T>* pNewNode = new Node<T>(item, nullptr);

		if (pEnd != nullptr)
		{
			pEnd->pNext = pNewNode;
		}
		else
		{
			pHead = pNewNode;
		}
		++mCount;
	}

	// ----------------------------------------------------------------------------------------------------

	template<class T>
	void List<T>::RemoveNode(Node<T>* pNode, Node<T>* pPrevious)
	{
		if (pPrevious == nullptr)
		{
			pHead = pNode->pNext;
		}
		else
		{
			pPrevious->pNext = pNode->pNext;
		}

		delete pNode;
		pNode = nullptr;

		--mCount;
	}
}