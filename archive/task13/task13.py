from string import ascii_lowercase as abc, ascii_uppercase as ABC
from math import ceil

def _code(string, shift, mode):
    return ''.join(
        abc[(abc.index(c) + i*mode + shift) % len(abc)] if c in abc else
        ABC[(ABC.index(c) + i*mode + shift) % len(ABC)] if c in ABC else c
        for i, c in enumerate(string))

def moving_shift(string, shift):
    encoded = _code(string, shift, 1)
    cut = int(ceil(len(encoded) / 5.0))
    return [encoded[i : i+cut] for i in range(0, 5 * cut, cut)]

def demoving_shift(arr, shift):
    return _code(''.join(arr), -shift, -1)


def main():
    u = "I should have known that you would have a perfect answer for me!!!"
    v = ["J vltasl rlhr ", "zdfog odxr ypw",
         " atasl rlhr p ", "gwkzzyq zntyhv", " lvz wp!!!"]

    result = moving_shift(u, 1)
    print(result)
    print(result == v)


if __name__ == '__main__':
    main()
