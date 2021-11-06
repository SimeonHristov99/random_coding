def correct_capitalization(string: str):
    return string is not None and (string == '' or string.islower() or string.isupper() or string.istitle())


def main():
    print(correct_capitalization("USA"))       # True
    print(correct_capitalization("Calvin"))    # True
    print(correct_capitalization("compUter"))  # False
    print(correct_capitalization("coding"))    # True
    print(correct_capitalization(""))          # True
    print(correct_capitalization(None))        # False


if __name__ == '__main__':
    main()
