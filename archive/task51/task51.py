from typing import List
import unittest
import numpy as np


class Solution:
    def luckyNumbers(self, matrix: List[List[int]]) -> List[int]:
        return np.intersect1d(np.max(matrix, axis=0), np.min(matrix, axis=1))


class TestMethods(unittest.TestCase):

    def test(self):
        self.assertEqual(Solution().luckyNumbers(
            [[3, 7, 8], [9, 11, 13], [15, 16, 17]]), [15])


if __name__ == '__main__':
    unittest.main()
