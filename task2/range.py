def generate_range(min, max, step):
    return list(range(min, max + 1, step))


print(generate_range(2, 10, 2))  # should return list of [2,4,6,8,10]
print(generate_range(1, 10, 3))  # should return list of [1,4,7,10]
print(generate_range(2, 10, 2))  # should return array of [2, 4, 6, 8, 10]
print(generate_range(1, 10, 3))  # should return array of [1, 4, 7, 10]
