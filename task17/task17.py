def nums_add_up(k, xs):
    s = set()

    for x in xs:
        el = None if x not in s else x

        if el is not None:
            return True

        s.add(k - x)

    return False


def main():
    xs = [10, 15, 3, 7]
    print(nums_add_up(17, xs))  # true


if __name__ == '__main__':
    main()
