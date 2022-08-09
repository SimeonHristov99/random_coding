def sum_strings(s1, s2):
    return str((int(s1) + int(s2)))

def main():
    print(sum_strings("10", "35679"))  # "35689"
    print(sum_strings("99", "99"))  # "198"
    print(sum_strings("99", "2"))  # "101"
    print(sum_strings("123", "456"))  # "579"
    print(sum_strings("111111111111111111111111111111",
                     "111111111111111111111111111111")) # 222222222222222222222222222222"


if __name__ == '__main__':
    main()
