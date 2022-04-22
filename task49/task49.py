from typing import List
import unittest

# Brute force
# def power_of_two(n: int):
#     return (n & (n-1) == 0) and n != 0


# def countPairs(deliciousness: List[int]) -> int:
#     result = 0

#     i = 0
#     j = 0

#     len_deliciousness = len(deliciousness)

#     for i in range(len_deliciousness - 1):
#         for j in range(i+1, len_deliciousness):
#             if power_of_two(deliciousness[i] + deliciousness[j]):
#                 result += 1

#     return result % (10**9 + 7)


# Optimized - Map
def countPairs(deliciousness: List[int]) -> int:
    result = 0
    diffs = {x: 0 for x in deliciousness}
    pow_twos = [2**k for k in range(22)]

    for x in deliciousness:

        for pow_two in pow_twos:
            diff = pow_two - x

            if diffs.get(diff) is not None:
                result += diffs[diff]
                result = result % (10**9 + 7)

        diffs[x] += 1

    return result


class TestMethods(unittest.TestCase):

    def test1(self):
        self.assertEqual(countPairs([1, 3, 5, 7, 9]), 4)

    def test2(self):
        self.assertEqual(countPairs([1, 1, 1, 3, 3, 3, 7]), 15)

    def test3(self):
        self.assertEqual(countPairs([64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
                         64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64]), 528)


if __name__ == '__main__':
    unittest.main()
