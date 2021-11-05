from math import ceil


def moving_shift(s, shift):
    len_list = ceil(len(s) / 5)
    current_len = 0
    result = []

    current_s = ''
    for c in s:
        if c.isalpha():
            is_up = c.isupper()
            if is_up:
                current_s += chr(ord('A') + ((ord(c) - ord('A') + shift) % 26))
            else:
                current_s += chr(ord('a') + ((ord(c) - ord('a') + shift) % 26))
        else:
            current_s += c
        shift += 1

    while len(current_s) > 0:
        result.append(current_s[:len_list])
        current_s = current_s[len_list:]

    while len(result) < 5:
        result.append('')

    return result


def demoving_shift(s, shift):
    s = ''.join(s)
    result = ''

    for c in s:
        if c.isalpha():
            is_up = c.isupper()
            if is_up:
                result += chr(ord('A') + ((ord(c) - ord('A') - shift) % 26))
            else:
                result += chr(ord('a') + ((ord(c) - ord('a') - shift) % 26))
        else:
            result += c
        shift += 1

    return result


def main():
    u = "I should have known that you would have a perfect answer for me!!!"
    v = ["J vltasl rlhr ", "zdfog odxr ypw",
         " atasl rlhr p ", "gwkzzyq zntyhv", " lvz wp!!!"]

    result = moving_shift(u, 1)
    print(result)
    print(result == v)


if __name__ == '__main__':
    main()
