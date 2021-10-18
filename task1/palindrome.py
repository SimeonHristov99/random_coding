def is_palindrome(s):
    normalized = [char.lower() for char in s if char.isalpha()]
    return normalized == normalized[::-1]


print(is_palindrome("level") == True)
print(is_palindrome("algorithm") == False)
print(is_palindrome("A man, a plan, a canal: Panama.") == True)
