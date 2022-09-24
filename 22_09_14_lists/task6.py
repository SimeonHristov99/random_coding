# Better
# def is_pangram(s):
#     return set(string.ascii_lowercase).issubset(s.lower())

import string


def is_pangram(s):
    expected = set(string.ascii_lowercase)
    actual = {chr.lower() for chr in s if chr.isalpha()}
    return expected == actual
