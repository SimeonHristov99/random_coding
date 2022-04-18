from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def helper(self, current: Optional[TreeNode]) -> bool:
        if current is None:
            return False

        if self.k - current.val in self.diffs:
            return True

        self.diffs.add(current.val)

        return self.helper(current.left) or self.helper(current.right)

    def findTarget(self, root: Optional[TreeNode], k: int) -> bool:
        if root is None:
            return False

        self.k = k
        self.diffs = set()

        return self.helper(root)


def test1():
    s = Solution()

    r = TreeNode(2, TreeNode(1), TreeNode(3))

    print(s.findTarget(r, 4) == True)
    print(s.findTarget(r, 3) == True)


def test2():
    s = Solution()

    r = TreeNode(0,
                 TreeNode(-1, TreeNode(-3)),
                 TreeNode(2, right=TreeNode(4)))

    print(s.findTarget(r, -4) == True)


def test3():
    s = Solution()

    r = TreeNode(1)

    print(s.findTarget(r, 2) == False)


def main():
    test1()
    test2()
    test3()


if __name__ == '__main__':
    main()
