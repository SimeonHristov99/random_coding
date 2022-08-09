def snail(snail_map):
    row_limit = len(snail_map)
    col_limit = row_limit

    if row_limit < 1:
        return []

    if row_limit < 2:
        return snail_map[0]

    result = []

    i = 0
    j = 0

    iteration = 1
    changed = True

    while changed:
        changed = False

        while j < col_limit - iteration:
            result.append(snail_map[i][j])
            j += 1
            changed = True

        while i < row_limit - iteration:
            result.append(snail_map[i][j])
            i += 1
            changed = True

        while col_limit > j > iteration - 1:
            result.append(snail_map[i][j])
            j -= 1
            changed = True

        while row_limit > i > iteration:
            result.append(snail_map[i][j])
            i -= 1
            changed = True

        iteration += 1

    result.append(snail_map[i][j])

    return result


"""
Optimized

import numpy as np

def snail(array):
    m = []
    array = np.array(array)
    while len(array) > 0:
        m += array[0].tolist()
        array = np.rot90(array[1:])
    return m
"""


def test1():
    map1 = [[1, 2, 3],
            [4, 5, 6],
            [7, 8, 9]]

    print(snail(map1))  # => [1,2,3,6,9,8,7,4,5]


def test2():
    map2 = [[1, 2, 3, 1],
            [4, 5, 6, 4],
            [7, 8, 9, 7],
            [7, 8, 9, 7]]

    print(snail(map2))  # => [1,2,3,4,5,6,7,8,9]


def main():
    test1()
    test2()


if __name__ == '__main__':
    main()
