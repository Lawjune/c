def modpow(base, exponent, n):
    result = 1
    base = base % n
    while exponent > 0:
        if exponent % 2 == 1: # When exponent is odd
            result = (result * base) % n
        base = (base * base) % n
        exponent = exponent // 2
    return result

print(modpow(4, 23, 7))
