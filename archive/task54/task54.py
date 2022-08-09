import unittest
from typing import List


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        return list(set(range(len(nums) + 1)) - set(nums))[0]


class TestMethods(unittest.TestCase):

    def test(self):
        s = Solution()
        self.assertEqual(s.missingNumber([3, 0, 1]), 2)


if __name__ == '__main__':
    unittest.main()
