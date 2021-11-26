import numpy as np


def solution(george, john):
    encoding = {
        1: 'O',
        2: '[]',
        3: '8<'
    }

    # Encode moves.
    for i, x in enumerate(['O', '[]', '8<']):
        george = george.replace(x, str(i + 1))
        john = john.replace(x, str(i + 1))

    # Find points.

    print(george)
    print(john)

    points_g = 0
    points_j = 0

    for move in zip(george, john):
        if move in { '21', '32', '13' }:
            points_g += 2
        elif move in { '22', '33', '11' }:
            points_g += 1
            points_j += 1
        else:
            points_j += 2

    print(points_g, points_j)

    print(list(zip(george, john)))

    n = [ int(''.join(pair)) for pair in zip(george, john) ]

    moves, freq = np.unique(n, return_counts=True)
    most_popular_george = encoding.get(moves[np.argmax(freq)] // 10, None)
    most_popular_john = encoding.get(moves[np.argmax(freq)] % 10, None)

    return f'George {points_g} John {points_j} {most_popular_george}{most_popular_john} {freq[np.argmax(freq)]}'


def main():
    print(solution('[][]8<O', 'OO[]O'))


if __name__ == '__main__':
    main()
