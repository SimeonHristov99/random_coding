#pragma once

template <class T>
class List
{

private:
    struct Node
    {
        T data;
        Node *prev;
        Node *next;

        Node()
            : prev(nullptr),
              next(nullptr)
        {
        }

        Node(const T &new_data, Node *new_prev = nullptr, Node *new_next = nullptr)
            : data(new_data),
              prev(new_prev),
              next(new_next)
        {
        }
    };

    Node dummy;
    int size;

    void insert_after_node(Node *node, const T &value)
    {
        Node *new_node = new Node(value, node, node->next);

        // Attach neighbours to new_node.
        node->next->prev = new_node;
        node->next = new_node;

        ++size;
    }

    void remove_node(Node *node)
    {
        if (node == &dummy || size <= 0)
        {
            std::cout << "ERROR: List is empty!\n";
            return;
        }

        --size;

        // Disconnect node from neighbous.
        node->next->prev = node->prev;
        node->prev->next = node->next;

        delete node;
        node = nullptr;
    }

    void copy(const List<T> &rhs)
    {
        if (!empty())
        {
            std::cout << "ERROR: List is not empty!\n";
            return;
        }

        for (iterator it = rhs.begin(); it != rhs.end(); ++it)
        {
            push_back(*it);
        }
    }

public:
    class iterator
    {
    public:
        iterator() {}

        T &operator*()
        {
            return current->data;
        }

        T *operator->()
        {
            return &current->data;
        }

        bool operator==(const iterator &rhs) const
        {
            return current == rhs.current;
        }

        bool operator!=(const iterator &rhs) const
        {
            return !(*this == rhs);
        }

        iterator &operator++()
        {
            current = current->next;
            return *this;
        }

        iterator operator++(int)
        {
            iterator copy(*this);
            current = current->next;
            return copy;
        }

        iterator &operator--()
        {
            current = current->prev;
            return *this;
        }

        iterator operator--(int)
        {
            iterator copy(*this);
            current = current->prev;
            return copy;
        }

    private:
        friend class List;

        Node *current = nullptr;

        // Private so that only List has access to this contructor.
        explicit iterator(Node *node)
            : current(node)
        {
        }
    };

    List()
    {
        size = 0;
        dummy.prev = &dummy;
        dummy.next = &dummy;
    }

    List(const List<T> &rhs)
    {
        size = 0;
        dummy.prev = &dummy;
        dummy.next = &dummy;
        copy(rhs);
    }

    List<T> &operator=(const List<T> &rhs)
    {
        if (this != &rhs)
        {
            clear();
            copy(rhs);
        }

        return *this;
    }

    ~List()
    {
        clear();
    }

    bool empty() const
    {
        bool empty = dummy.prev == &dummy;

        if (empty != (size == 0))
        {
            std::cout << "ERROR: Size of list not properly set!\n";
            return false;
        }

        return empty;
    }

    int get_size() const
    {
        return size;
    }

    void pop_back()
    {
        remove_node(dummy.prev);
    }

    void pop_front()
    {
        remove_node(dummy.next);
    }

    void push_back(const T &value)
    {
        insert_after_node(dummy.prev, value);
    }

    T &back()
    {
        return dummy.prev->data;
    }

    T &front()
    {
        return dummy.next->data;
    }

    void insert_after(const iterator &it, const T &value)
    {
        insert_after_node(it.current, value);
    }

    void insert_before(const iterator &it, const T &value)
    {
        insert_after_node(it.current->prev, value);
    }

    void remove(const iterator &it)
    {
        remove_node(it.current);
    }

    void clear()
    {
        while (!empty())
        {
            pop_back();
        }
        size = 0;
    }

    iterator begin()
    {
        return iterator(dummy.next);
    }

    iterator end()
    {
        return iterator(&dummy);
    }
};
