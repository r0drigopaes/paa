def pot(x, n):
    if (n == 0):
        return(1)
    if (n == 1):
        return(x)
    if (n % 2 == 0):
        half = pot(x, n / 2)
        return(half * half)
    else:
        half = pot(x, (n - 1) / 2)
        return(half * half * x)

x, n = map(int, input().split())
print(pot(x, n))
