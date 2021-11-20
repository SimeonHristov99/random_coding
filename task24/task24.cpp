#include <iostream>
#include "list.hpp"

void test_empty()
{
    List<int> l;
    std::cout << std::boolalpha << (l.empty() == true) << '\n';

    l.push_back(42);
    std::cout << (l.empty() == false) << '\n';

    l.pop_back();
    std::cout << (l.empty() == true) << '\n';
}

void test_get_size()
{
    List<int> l;

    l.push_back(42);
    std::cout << std::boolalpha << (l.get_size() == 1) << '\n';

    l.push_back(24);
    std::cout << (l.get_size() == 2) << '\n';
}

void test_pop_back()
{
    List<int> l;
    l.push_back(42);

    std::cout << std::boolalpha << (l.get_size() == 1) << '\n';

    l.pop_back();

    std::cout << (l.get_size() == 0) << '\n';
}

void test_back()
{
    List<int> l;
    l.push_back(42);

    std::cout << std::boolalpha << (l.back() == 42) << '\n';
    l.back() = 24;
    std::cout << (l.back() == 24) << '\n';
}

void test_front()
{
    List<int> l;
    l.push_back(42);

    std::cout << std::boolalpha << (l.front() == 42) << '\n';
    l.back() = 24;
    std::cout << (l.front() == 24) << '\n';
}

void test_pop_front()
{
    List<int> l;
    l.push_back(42);
    l.pop_front();

    std::cout << std::boolalpha << (l.empty() == true) << '\n';
    std::cout << (l.get_size() == 0) << '\n';
}

void test_push_back()
{
    List<int> l;
    l.push_back(42);
    l.push_back(92);
    l.push_back(82);
    l.push_back(72);
    l.push_back(62);
    l.push_back(52);
    l.push_back(42);
    l.push_back(32);
    l.push_back(22);
    l.push_back(12);
    l.push_back(2);

    std::cout << std::boolalpha << (l.back() == 2) << '\n';
    std::cout << (l.empty() == false) << '\n';
}

void test_insert_after_and_before()
{
    List<int> l;
    l.push_back(92);
    l.push_back(82);
    l.push_back(72);
    l.push_back(62);
    l.push_back(52);
    l.push_back(42);
    l.push_back(32);
    l.push_back(22);
    l.push_back(12);
    l.push_back(2);

    std::cout << std::boolalpha << (l.get_size() == 10) << '\n';

    l.insert_after(l.begin(), 69);

    std::cout << (l.front() == 92) << '\n';
    l.pop_front();
    std::cout << (l.front() == 69) << '\n';
    std::cout << (l.get_size() == 10) << '\n';

    List<int>::iterator it = l.begin();
    int i = 5;
    for (int j = 0; j < i; j++)
    {
        ++it;
    }

    std::cout << (*it == 42) << '\n';
    l.insert_after(it, 69);
    std::cout << (*it == 42) << '\n';
    l.insert_before(it, 69);

    // This should print the following: 69 82 72 62 52 69 42 69 32 22 12 2
    while (!l.empty())
    {
        std::cout << l.front() << ' ';
        l.pop_front();
    }
    std::cout << '\n';
}

void test_remove()
{
    List<int> l;
    l.push_back(92);
    l.push_back(82);
    l.push_back(72);
    l.push_back(62);
    l.push_back(52);
    l.push_back(42);
    l.push_back(32);
    l.push_back(22);
    l.push_back(12);
    l.push_back(2);

    std::cout << std::boolalpha << (l.get_size() == 10) << '\n';

    l.insert_after(l.begin(), 69);

    std::cout << (l.front() == 92) << '\n';
    l.pop_front();
    std::cout << (l.front() == 69) << '\n';
    std::cout << (l.get_size() == 10) << '\n';

    List<int>::iterator it = l.begin();
    int i = 5;
    for (int j = 0; j < i; j++)
    {
        ++it;
    }

    std::cout << (*it == 42) << '\n';
    l.insert_after(it, 69);
    std::cout << (*it == 42) << '\n';
    l.insert_before(it, 69);

    l.remove(it);
    l.remove(l.begin());
    l.remove(--l.end());

    // This should print the following: 82 72 62 52 69 69 32 22 12
    while (!l.empty())
    {
        std::cout << l.front() << ' ';
        l.pop_front();
    }
    std::cout << '\n';
}

void test_clear()
{
    List<int> l;
    l.push_back(92);
    l.push_back(82);
    l.push_back(72);
    l.push_back(62);
    l.push_back(52);
    l.push_back(42);
    l.push_back(32);
    l.push_back(22);
    l.push_back(12);
    l.push_back(2);

    l.clear();

    std::cout << std::boolalpha << (l.empty() == true) << '\n';
    std::cout << (l.get_size() == 0) << '\n';
}

void test_iteration()
{
    List<int> l;
    l.push_back(92);
    l.push_back(82);
    l.push_back(72);
    l.push_back(62);
    l.push_back(52);
    l.push_back(42);
    l.push_back(32);
    l.push_back(22);
    l.push_back(12);
    l.push_back(2);

    // This should print the following: 92 82 72 62 52 42 32 22 12 2
    for (List<int>::iterator it = l.begin(); it != l.end(); ++it)
    {
        std::cout << *it << ' ';
    }
    std::cout << '\n';
}

int main(int argc, char const *argv[])
{
    test_empty();
    test_get_size();
    test_pop_back();
    test_back();
    test_front();
    test_pop_front();
    test_push_back();
    test_insert_after_and_before();
    test_remove();
    test_clear();
    test_iteration();

    return 0;
}
