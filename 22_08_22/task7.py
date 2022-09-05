# Better approach 1
# def shifted_diff(first, second):
#     return (second + second).find(first) if len(first) == len(second) else - 1


# Better approach 2
# def shifted_diff(first, second):
#     for i in range(len(first)):
#         if first == second[i:] + second[:i]:
#             return i
#     return -1


def shifted_diff(first, second):
    if first == second:
        return 0

    len_first = len(first)

    if len_first != len(second):
        return -1

    for rot in range(len_first):
        second = second[1:] + second[0]

        if second == first:
            return rot + 1

    return -1
