class RomanNumerals:

    def to_roman(val):
        result = ''

        symbols = ['M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I']
        nums = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        nums_len = len(nums)
        i = 0

        while i < nums_len:
            if nums[i] <= val:
                val -= nums[i]
                result += symbols[i]
                i -= 1
            i += 1

        return result

    def from_roman(roman_num):
        symbols_to_nums = {
            "I": 1,
            "IV": 4,
            "V": 5,
            "IX": 9,
            "X": 10,
            "XL": 40,
            "L": 50,
            "XC": 90,
            "C": 100,
            "CD": 400,
            "D": 500,
            "CM": 900,
            "M": 1000,
        }

        result = 0
        input_len = len(roman_num)

        i = 0

        while i < input_len:
            search = symbols_to_nums.get(roman_num[i:i+2], None)

            if search is None:
                search = symbols_to_nums.get(roman_num[i:i+1], None)
                i -= 1

            result += search

            i += 2

        return result


def main():
    print(RomanNumerals.to_roman(1000) == "M")
    print(RomanNumerals.to_roman(4) == "IV")
    print(RomanNumerals.to_roman(1) == "I")
    print(RomanNumerals.to_roman(9) == "IX")
    print(RomanNumerals.to_roman(1990) == "MCMXC")
    print(RomanNumerals.to_roman(2008) == "MMVIII")
    print(RomanNumerals.to_roman(3999) == "MMMCMXCIX")

    print(RomanNumerals.from_roman("XXI") == 21)
    print(RomanNumerals.from_roman("I") == 1)
    print(RomanNumerals.from_roman("IX") == 9)
    print(RomanNumerals.from_roman("IV") == 4)
    print(RomanNumerals.from_roman("MMVIII") == 2008)
    print(RomanNumerals.from_roman("MDCLXVI") == 1666)


if __name__ == '__main__':
    main()
