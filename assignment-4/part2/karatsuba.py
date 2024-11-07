def karatsuba(x, y):
    if x < 10 or y < 10:
        return x * y

    m = max(len(str(x)), len(str(y)))
    m2 = m // 2

    high1 = x // 10**m2
    low1 = x % 10**m2
    high2 = y // 10**m2
    low2 = y % 10**m2

    z0 = karatsuba(low1, low2)
    z1 = karatsuba((low1 + high1), (low2 + high2))
    z2 = karatsuba(high1, high2)

    return (z2 * 10**(2 * m2)) + ((z1 - z2 - z0) * 10**m2) + z0

if __name__ == "__main__":
    x = int(input("Enter first integer: "))
    y = int(input("Enter second integer: "))
    result = karatsuba(x, y)
    print("Result:", result)
