#ifndef MYLIST_H
#define MYLIST_H

#include <ostream>

template <typename T> class MyList
{
protected: // Node
	struct Node
	{
		using node_ptr = std::unique_ptr<Node>;
		
		Node(T value) : value(value) {}

		T value;
		node_ptr next;
	};

public: // Iterator
	struct Iterator
	{
		friend class LinkedList;

	public:
		Iterator() noexcept : curr(nullptr) {}
		Iterator(const node_ptr& node) noexcept : curr(node.get()) {}

		Iterator& operator++() noexcept
		{
			if (curr != nullptr)
			{
				prev = curr;
				curr = curr->next.get();
			}
			return *this;
		}
		Iterator operator++(int) noexcept
		{
			Iterator tempIter = *this;
			++* this;
			return tempIter;
		}
		bool operator!=(const Iterator& other) const noexcept { return this->curr != other.curr; }
		T operator*() const noexcept { return this->curr->value; }

	private:
		const Node* prev = nullptr;
		const Node* curr = nullptr;
	};

public:
	MyList() : size_(0) {}
	MyList(const MyList<T>&) = delete;

	size_t size() const { return size_; }

	MyList<T>& operator=(MyList<T>&) = delete;
	friend ostream& operator<<(ostream& os, const MyList<T>& myList);

	void push_front(T element);
	T pop_front();
	T front();
	void remove(T element);
	Iterator begin() const noexcept { return Iterator(this->head); }
	Iterator end() const noexcept { return Iterator(); }

protected:
	using node_ptr = std::unique_ptr<Node>;
	node_ptr head;

private:
	size_t size_;
};

template <typename T> std::ostream& operator<<(std::ostream& os, const MyList<T>& myList)
{
	os << dt.mo << '/' << dt.da << '/' << dt.yr;
	return os;
}

template <typename T> void MyList<T>::push_front(T element)
{
	Node node(element);
	node.next = head;
	head = node_ptr(node);
	++size_;
}

template <typename T> T MyList<T>::pop_front()
{
	if (head == nullptr)
		throw std::out_of_range("The list is empty");
	T toReturn = head.value;
	head = head.next;
	--size_;
	return toReturn;
}

template <typename T> T MyList<T>::front()
{
	return head.value;
}

template <typename T> void MyList<T>::remove(T element)
{
	node_ptr prev = nullptr;
	node_ptr curr = head;
	while (curr != nullptr)
	{
		if (curr->value == element)
			prev = curr;
		else
		{
			prev->next = curr->next;
			--size_;
		}
		curr = curr->next;
	}
}

#endif // MYLIST_H
