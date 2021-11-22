def remove_intersections(intervals):
    result = []

    s = set(range(intervals[0][0], intervals[0][1] + 1))

    i = 1
    while i < len(intervals):
        new_interval = set(range(intervals[i][0], intervals[i][1] + 1))
        if not s.isdisjoint(new_interval):
            s = s.union(new_interval)
            i += 1
        else:
            l = list(s)
            s = set(range(intervals[i][0], intervals[i][1] + 1))
            result.append((l[0], l[-1]))

    if s != {}:
        l = list(s)
        result.append((l[0], l[-1]))

    return result


def test1():
    intervals = [(1, 5), (2, 3), (4, 6), (7, 8), (8, 10), (12, 15)]
    expected = [(1, 6), (7, 10), (12, 15)]

    print(remove_intersections(intervals) == expected)


def test2():
    intervals = [(9, 10), (10, 12), (11, 13), (14, 18), (15, 18)]
    expected = [(9, 13), (14, 18)]

    print(remove_intersections(intervals) == expected)


def main():
    test1()
    test2()


if __name__ == '__main__':
    main()
