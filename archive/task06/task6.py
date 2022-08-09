def get_length_of_missing_array(array_of_arrays):
    if array_of_arrays is None:
        return 0

    sorted_lens = sorted([ len(x) if x is not None else 0 for x in array_of_arrays])
    
    for i in range(len(sorted_lens) - 1):
        if sorted_lens[i] is None or sorted_lens[i] == 0:
            return 0

        if sorted_lens[i] != sorted_lens[i + 1] - 1:
            return sorted_lens[i] + 1
    
    return 0


print(get_length_of_missing_array(
    [[1, 2], [4, 5, 1, 1], [1], [5, 6, 7, 8, 9]])
    )  # 3
print(get_length_of_missing_array(
    [[5, 2, 9], [4, 5, 1, 1], [1], [5, 6, 7, 8, 9]])
    )  # 2
print(get_length_of_missing_array(
    [[None], [None, None, None]])
    )  # 2
print(get_length_of_missing_array(
    [['a', 'a', 'a'], ['a', 'a'], ['a', 'a', 'a', 'a'], ['a'], ['a', 'a', 'a', 'a','a', 'a']])
    )  # 5