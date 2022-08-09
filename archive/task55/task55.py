import unittest
from typing import List


class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        return list(set(range(1, len(nums) + 1)) - set(nums))


class TestMethods(unittest.TestCase):

    def test(self):
        s = Solution()
        self.assertEqual(s.findDisappearedNumbers(
            [4, 3, 2, 7, 8, 2, 3, 1]), [5, 6])


if __name__ == '__main__':
    unittest.main()
