def dirReduc(arr):
    opposite_dirs = {
        'NORTH': 'SOUTH',
        'SOUTH': 'NORTH',
        'WEST': 'EAST',
        'EAST': 'WEST',
    }

    if len(arr) == 0:
        return arr

    result = [arr[0]]

    for i in range(len(arr) - 1):
        if len(result) > 0 and result[-1] == opposite_dirs.get(arr[i + 1], None):
            result.pop()
            i += 1
        else:
            result.append(arr[i + 1])

    return result


def main():
    a = ['NORTH', 'SOUTH', 'SOUTH', 'EAST', 'WEST', 'NORTH', 'WEST']
    print(dirReduc(a))  # ['WEST']

    a = ['NORTH', 'WEST', 'SOUTH', 'EAST']
    print(dirReduc(a))  # ['NORTH', 'WEST', 'SOUTH', 'EAST']

    a = []
    print(dirReduc(a))  # []

    a = ['NORTH', 'SOUTH']
    print(dirReduc(a))  # []

if __name__ == '__main__':
    main()
