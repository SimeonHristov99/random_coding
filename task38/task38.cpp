#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
private:
    ListNode *helper(ListNode *l1, ListNode *l2, bool carry)
    {
        if (l1 == nullptr && l2 == nullptr)
        {
            return (carry ? new ListNode(1) : nullptr);
        }

        if (l1 == nullptr)
        {
            int sum = l2->val + carry;
            return new ListNode(sum % 10, helper(l1, l2->next, sum / 10));
        }

        if (l2 == nullptr)
        {
            int sum = l1->val + carry;
            return new ListNode(sum % 10, helper(l1->next, l2, sum / 10));
        }

        int sum = l1->val + l2->val + carry;
        return new ListNode(sum % 10, helper(l1->next, l2->next, sum / 10));
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        return helper(l1, l2, 0);
    }
};

void test1()
{
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution sol;

    ListNode *l3 = sol.addTwoNumbers(l1, l2);

    std::cout << l3->val << '\n';
    std::cout << l3->next->val << '\n';
    std::cout << l3->next->next->val << '\n';
}

void test2()
{
    ListNode *l1 = new ListNode(0);
    ListNode *l2 = new ListNode(0);

    Solution sol;
    ListNode *l3 = sol.addTwoNumbers(l1, l2);

    std::cout << l3->val << '\n';
}

void test3()
{
    ListNode *l1 = new ListNode(9);
    l1->next = new ListNode(9);
    l1->next->next = new ListNode(9);
    l1->next->next->next = new ListNode(9);
    l1->next->next->next->next = new ListNode(9);
    l1->next->next->next->next->next = new ListNode(9);
    l1->next->next->next->next->next->next = new ListNode(9);

    ListNode *l2 = new ListNode(9);
    l2->next = new ListNode(9);
    l2->next->next = new ListNode(9);
    l2->next->next->next = new ListNode(9);

    Solution sol;

    ListNode *l3 = sol.addTwoNumbers(l1, l2);

    std::cout << l3->val << '\n';
    std::cout << l3->next->val << '\n';
    std::cout << l3->next->next->val << '\n';
    std::cout << l3->next->next->next->val << '\n';
    std::cout << l3->next->next->next->next->val << '\n';
    std::cout << l3->next->next->next->next->next->val << '\n';
    std::cout << l3->next->next->next->next->next->next->val << '\n';
    std::cout << l3->next->next->next->next->next->next->next->val << '\n';
}

int main(int argc, char const *argv[])
{
    test1();
    std::cout << '\n';
    test2();
    std::cout << '\n';
    test3();

    return 0;
}
