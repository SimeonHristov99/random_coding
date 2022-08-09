from queue import SimpleQueue


def swap(s, i, j):
    lst = list(s)
    lst[i], lst[j] = lst[j], lst[i]
    return ''.join(lst)


def permutations(string):
    q = SimpleQueue()
    s = set()

    len_string = len(string)
    q.put((string, 1))

    while True:
        permutation, i = q.get()

        for j in range(i - 1, len(permutation)):
            new_permutation = swap(permutation, i - 1, j)
            q.put((new_permutation, i + 1))

        if i > len_string - 1:
            break

    while not q.empty():
        s.add(q.get()[0])

    return list(s)


def main():
    print(permutations('ABC'))


if __name__ == '__main__':
    main()
