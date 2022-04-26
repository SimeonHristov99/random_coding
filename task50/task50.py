from ast import Or
from typing import List
import unittest


class OrderedStream:

    def __init__(self, n: int):
        self.n = n
        self.strings = [''] * n
        self.i = 0

    def insert(self, idKey: int, value: str) -> List[str]:
        self.strings[idKey - 1] = value

        result = []
        while self.i < self.n and self.strings[self.i] != '':
            result.append(self.strings[self.i])
            self.i += 1

        return result


class TestMethods(unittest.TestCase):

    def test(self):
        os = OrderedStream(5)

        self.assertEqual([], os.insert(3, "ccccc"))
        self.assertEqual(["aaaaa"], os.insert(1, "aaaaa"))
        self.assertEqual(["bbbbb", "ccccc"], os.insert(2, "bbbbb"))
        self.assertEqual([], os.insert(5, "eeeee"))
        self.assertEqual(["ddddd", "eeeee"], os.insert(4, "ddddd"))


if __name__ == '__main__':
    unittest.main()
