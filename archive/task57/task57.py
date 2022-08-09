import unittest


class Solution:
    def solve(self, nums, k):
        # Optimized:
        # nums.sort()
        # return min(y - x for x, y in zip(nums, nums[k - 1 :]))

        results = []
        current = []

        for n in sorted(nums):
            if len(current) < k:
                current.append(n)
            elif len(current) == k:
                results.append(current[-1] - current[0])
                current.pop(0)
                current.append(n)

        results.append(current[-1] - current[0])
        return min(results)


class TestMethods(unittest.TestCase):

    def test(self):
        s = Solution()

        nums = [1, 2, 2]
        k = 2

        self.assertEqual(s.solve(nums, k), 0)

    def test2(self):
        s = Solution()

        nums = [2, 10, 5, 1, 8]
        k = 3

        self.assertEqual(s.solve(nums, k), 4)


if __name__ == '__main__':
    unittest.main()
