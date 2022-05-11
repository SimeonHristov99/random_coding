import unittest
from typing import List


class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        seen = {}

        for i, n in enumerate(nums):

            if n in seen and abs(seen[n] - i) <= k:
                return True

            seen[n] = i

        return False


class TestMethods(unittest.TestCase):

    def test(self):
        s = Solution()
        self.assertTrue(s.containsNearbyDuplicate([1, 2, 3, 1], 3))
        self.assertTrue(s.containsNearbyDuplicate([1, 0, 1, 1], 1))
        self.assertFalse(s.containsNearbyDuplicate([1, 2, 3, 1, 2, 3], 2))


if __name__ == '__main__':
    unittest.main()
