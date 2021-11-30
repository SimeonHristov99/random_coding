def proper_fractions(n):
    """
    Using Euler's Totient Theorem
    """
    if n < 2:
        return 0
    
    phi = n

    i = 2
    while i * i <= n:
        if n % i == 0:
            phi = phi / i * (i - 1)
            while n % i == 0:
                n /= i

        i += 1
    
    if n > 1:
        phi = phi / n * (n - 1)
    
    return phi


print(proper_fractions(1))  # 0
print(proper_fractions(2))  # 1
print(proper_fractions(5))  # 4
print(proper_fractions(15))  # 8
print(proper_fractions(25))  # 20