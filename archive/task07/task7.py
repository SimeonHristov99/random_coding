def rot13(msg):
    LEN_ALPHA = ord('z') - ord('a') + 1
    result = ''

    for c in msg:
        if c.islower():
            result += chr(ord('a') + (ord(c) - ord('a') + 13) % LEN_ALPHA)
        elif c.isupper():
            result += chr(ord('A') + (ord(c) - ord('A') + 13) % LEN_ALPHA)
        else:
            result += c

    return result


print(rot13("test"))  # "grfg"
print(rot13("te665st"))  # "gr665fg"
print(rot13("4"))  # "4"
print(rot13("Test"))  # "Grfg"
