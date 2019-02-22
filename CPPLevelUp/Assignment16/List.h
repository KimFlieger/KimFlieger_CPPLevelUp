#pragma once

namespace Storage
{
	template<class T>
	class List
	{
	public:
		~List();
		List& operator=(const List& rhs);
		List& operator=(List&& rhs);

		T& operator[](int index);

		unsigned int Count() const { return mCount; }

		void Add(const T& item);
		void Remove(const T& item);
		void RemoveAt(int index);
		void Clear();

	private:
		template<class T>
		class Node
		{
		public:
			Node(const T& item, Node* next)
				: Item(item)
				, pNext(next)
			{
				// Empty
			}

			T Item;
			Node* pNext;
		};

		Node<T>* pHead = nullptr;
		unsigned int mCount = 0;

		void CreateNode(Node<T>* pEnd, const T& item);
		void RemoveNode(Node<T>* pNode, Node<T>* pPrevious);
	};
}

#include "List.inl"