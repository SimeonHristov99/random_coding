def narcissistic(value):
    val_str = str(value)
    return value == sum(map(lambda x: x**len(val_str), map(int, val_str)))
