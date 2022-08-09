import unittest

# Time: O(n), n = len(s)
# Space: O(1)


class Solution:
    def solve(self, dictionary, s):
        codes = {}
        prev = None

        for i, c in enumerate(dictionary):
            codes[c] = i

        for c in s:
            if c in codes:
                if prev is not None and prev > codes[c]:
                    return False

                prev = codes[c]

        return True


class TestMethods(unittest.TestCase):

    def test1(self):
        sol = Solution()

        dictionary = "acb"
        s = "aaaa h ccc i bbb"

        self.assertTrue(sol.solve(dictionary, s))

    def test2(self):
        sol = Solution()

        dictionary = "acb"
        s = "aaaacccbc"

        self.assertFalse(sol.solve(dictionary, s))

    def test3(self):
        sol = Solution()

        dictionary = "uoxtsnvkby"
        s = "bootnoaaaccghjlmppqrrrz"

        self.assertFalse(sol.solve(dictionary, s))

    def test4(self):
        sol = Solution()

        dictionary = "nmrl"
        s = "tm"

        self.assertTrue(sol.solve(dictionary, s))

    def test5(self):
        sol = Solution()

        dictionary = "swzncmvri"
        s = "sswswwwwwswznccccmmvvvvvrriiaabbbddefgggggghhhhjjkkkkklllooooppqqttuuxyyy"

        self.assertFalse(sol.solve(dictionary, s))


if __name__ == '__main__':
    unittest.main()
