def find_smallest(nums):
    result = []
    s = []

    for x in nums:
        while len(s) != 0 and s[-1] >= x:
            s.pop()
        result.append(s[-1] if len(s) != 0 else -1)

        s.append(x)

    return result


def test1():
    t = [2, 5, 3, 7, 8, 1, 9]
    print(find_smallest(t) == [-1, 2, 2, 3, 7, -1, 1])


def test2():
    t = [5, 7, 4, 9, 8, 10]
    print(find_smallest(t) == [-1, 5, -1, 4, 4, 8])

def test3():
    t = [1, 5, 2, 2, 2, 5, 5, 4]
    print(find_smallest(t) == [-1, 1, 1, 1, 1, 2, 2, 2])

def main():
    test1()
    test2()
    test3()


if __name__ == '__main__':
    main()
