#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

struct Tree
{
    int val;
    Tree *left;
    Tree *right;
};

bool solve(Tree *root0, Tree *root1)
{
    if (!root0 && !root1)
    {
        return true;
    }

    if (!root0 || !root1)
    {
        return false;
    }

    return root0->val == root1->val
        && ((solve(root0->left, root1->left)
        && solve(root0->right, root1->right))
        || (solve(root0->left, root1->right)
        && solve(root0->right, root1->left)));
}

TEST_CASE("Test case name")
{
    Tree t1;
    t1.val = 3;
    t1.left = new Tree{2, nullptr, nullptr};
    t1.right = nullptr;

    Tree t2;
    t2.val = 3;
    t2.right = new Tree{2, nullptr, nullptr};
    t2.left = nullptr;

    CHECK(solve(&t1, &t2));
}
