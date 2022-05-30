#ifndef MYLIST_H
#define MYLIST_H

#include <iostream>
#include <memory>

template <typename T> class MyList
{
public:
    using value_type = T;

    struct Node;
    struct Iterator;
    struct ConstIterator;

public:
    std::unique_ptr <MyList::Node> head;

    MyList() {}
    MyList(const MyList<T>&) = delete;

    T front() const;
    size_t size() const { return size_; }

    MyList<T>& operator=(MyList<T>&) = delete;

    void push_front(T element);
    T pop_front();
    void remove(T element);

    Iterator begin() { return Iterator(head.get()); }
    ConstIterator begin() const { return ConstIterator(head.get()); }
    Iterator end() { return Iterator(); }
    ConstIterator end() const { return ConstIterator(); }

private:
    size_t size_ = 0;
};

template <typename T> T MyList<T>::front() const
{
    if (head == nullptr)
        throw std::out_of_range("The list is empty");
    return head->value();
}

template <typename T> void MyList<T>::push_front(T element)
{
    std::unique_ptr<Node> node = std::make_unique<Node>(element);
    node->next = std::move(head);
    head = std::move(node);
    ++size_;
}

template <typename T> T MyList<T>::pop_front()
{
    if (head == nullptr)
        throw std::out_of_range("Attempted to pop from an empty list");
    T toReturn = head->value();
    head = std::move(head->next);
    --size_;
    return toReturn;
}

template <typename T> void MyList<T>::remove(T element)
{
    while (head != nullptr && head->value() == element)
    {
        head = std::move(head->next);
        --size_;
    }

    if (head == nullptr)
        return;

    Node* prev = nullptr;
    Node* curr = head.get();
    while (curr != nullptr)
    {
        if (curr->value() == element)
        {
            prev->next = std::move(curr->next);
            --size_;
            curr = prev->next.get();
        }
        else
        {
            prev = curr;
            curr = curr->next.get();
        }
    }
}

template <typename T> std::ostream& operator<<(std::ostream& os, const MyList<T>& myList)
{
    for (auto node : myList)
        os << node << " -> ";
    os << "*\n";
    return os;
}

template <typename T> class MyList<T>::Node
{
public:
    std::unique_ptr<Node> next = nullptr;

    explicit Node(T value) : value_(value) {}

    T& value() { return value_; }
    T const& value() const { return value_; }

private:
    T value_;
};

template <typename T> class MyList<T>::Iterator
{
public:
    explicit Iterator() noexcept : curr(nullptr) {}
    explicit Iterator(Node* node) noexcept : curr(node) {}

    Iterator& operator++() noexcept
    {
        curr = curr->next == nullptr ? nullptr : curr->next.get();
        return *this;
    }

    bool operator!=(const Iterator& other) const noexcept { return curr != other.curr; }
    T& operator*() noexcept { return curr->value(); }

private:
    Node* curr;
};


template <typename T> class MyList<T>::ConstIterator
{
public:
    explicit ConstIterator() noexcept : curr(nullptr) {}
    explicit ConstIterator(const Node* node) noexcept : curr(node) {}

    ConstIterator const& operator++() noexcept
    {
        curr = curr->next == nullptr ? nullptr : curr->next.get();
        return *this;
    }

    bool operator!=(const ConstIterator& other) const noexcept { return curr != other.curr; }
    T const& operator*() noexcept { return curr->value(); }

private:
    const Node* curr;
};

#endif // MYLIST_H
