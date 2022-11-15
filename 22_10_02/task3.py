# 

def woodcutters(xs):
    if len(xs) == 1:
        return 1

    res = 2
    left_i = xs[0][0]

    for (x0, h0), (x1, h1), (x2, h2) in zip(xs, xs[1:], xs[2:]):
        if x1 - h1 > left_i:
            res += 1
            left_i = x1
        elif x1 + h1 < x2:
            res += 1
            left_i = x1 + h1
        else:
            left_i = x1

    return res


def main():
    n = int(input())

    xs = []

    while n:
        xi, hi = input().split()

        xs.append((int(xi), int(hi)))

        n -= 1

    print(woodcutters(xs))


if __name__ == '__main__':
    main()
