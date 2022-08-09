from math import floor

def zeros(n):
    result = 0
    denominator = 5

    while denominator <= n:
        result += floor(n / denominator)
        denominator *= 5

    return result

print(zeros(0))  # 0
print(zeros(6))  # 1
print(zeros(30))  # 7
print(zeros(100))  # 24
print(zeros(1000))  # 249
print(zeros(100000))  # 24999
print(zeros(1000000000))  # 249999998
