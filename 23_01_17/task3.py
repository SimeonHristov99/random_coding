# Not finished.

from typing import List
from math import sqrt, trunc


def is_prime(n: int) -> bool:
    return n > 1 and [] == [x for x in range(2, trunc(sqrt(n)) + 1) if n % x == 0]


def prime_factors(n: int) -> List[int]:
    res = []

    for d in range(2, n + 1):
        if is_prime(d):
            while n % d == 0:
                res.append(d)
                n /= d

    return res


def convert(n):
    nums = []
    res = []
    cl_brs = []
    primes = [x for x in range(n + 1) if is_prime(x)]

    nums.append(n)

    while len(nums) > 0:
        current = nums.pop()
        res.append('[')
        cl_brs.append(']')

        if current != 2:
            ps = prime_factors(current)
            for p in ps:
                if p == 2:
                    res.append('[')
                    res.append(']')
            ps = [primes.index(x) + 1 for x in ps if x != 2]
            nums += reversed(ps)
        else:
            res.append('[')
            res.append(']')
            res.append(cl_brs.pop())

    while len(cl_brs) > 0:
        res.append(cl_brs.pop())

    res.pop(0)
    res = ''.join(['1' if r == '[' else '0' for r in res])
    res = res.rstrip('0')
    res = int(res[:-1], 2)

    return res


def main():
    n = 46

    res = convert(n)
    print(res)


if __name__ == '__main__':
    main()

# For pytest
# from HARD_int_to_list import convert
# def test_convert():
#     ns = [46, 3, 4, 5, 6, 7, 8, 9, 10, 10000, 10001, 10002,
#           10003, 10004, 10005, 10006, 10007, 10008, 999983]
#     es = [185, 1, 2, 3, 5, 6, 10, 25, 11, 179189987, 944359, 183722,
#           216499, 2863321, 27030299, 93754, 223005, 1402478, 1825387733]
#     rs = map(convert, ns)
#     for (n, expected, r) in zip(ns, es, rs):
#         assert r == expected, f'{n=}'
