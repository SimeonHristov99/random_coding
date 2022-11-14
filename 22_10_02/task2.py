from math import gcd, lcm


def get_nums(limit):
    for x1 in range(1, limit):
        for x2 in range(1, limit):
            if gcd(x1, x2) + lcm(x1, x2) == limit:
                return (x1, x2)


def main():
    t = int(input())

    for test in range(t):
        limit = int(input())
        x1, x2 = get_nums(limit)
        print(x1, x2)


if __name__ == '__main__':
    main()
