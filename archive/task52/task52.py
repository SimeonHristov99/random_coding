import unittest
from typing import List


class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        seen = set()

        for n in nums:
            if n in seen:
                return True

            seen.add(n)

        return False


class TestMethods(unittest.TestCase):

    def test(self):
        s = Solution()
        self.assertTrue(s.containsDuplicate(nums=[1, 2, 3, 1]))


if __name__ == '__main__':
    unittest.main()
