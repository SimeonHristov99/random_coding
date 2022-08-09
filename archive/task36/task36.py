def is_isogram(string):
    return len(set(sorted(string.lower()))) == len(sorted(string.lower()))


def main():
    print(is_isogram("Dermatoglyphics") == True)
    print(is_isogram("isogram") == True)
    print(is_isogram("aba") == False)
    print(is_isogram("moOse") == False)
    print(is_isogram("isIsogram") == False)
    print(is_isogram("") == True)


if __name__ == '__main__':
    main()
