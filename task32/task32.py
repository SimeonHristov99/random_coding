def reverse_seq(n):
    return list(range(n, 0, -1))


def test():
    print(reverse_seq(5) == [5, 4, 3, 2, 1])


def main():
    test()


if __name__ == '__main__':
    main()
