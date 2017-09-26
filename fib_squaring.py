def multiplyMatrix(a, b):
    c = [[0, 0], [0, 0]]
    c[0][0] = (a[0][0] * b[0][0]) + (a[0][1] * b[1][0]);
    c[0][1] = (a[0][0] * b[0][1]) + (a[0][1] * b[1][1]);
    c[1][0] = (a[1][0] * b[0][0]) + (a[1][1] * b[1][0]);
    c[1][1] = (a[1][0] * b[0][1]) + (a[1][1] * b[1][1]);
    return(c)

def pot(m, n):
    if (n == 1):
        return(m)
    if (n % 2 == 0):
        half = pot(m, n / 2)
        return(multiplyMatrix(half, half))
    else:
        half = pot(m, (n - 1) / 2)
        temp = multiplyMatrix(half, half)
        return(multiplyMatrix(m, temp))

def fib(n):
    result = pot(M, n)
    return(result[0][1])

M = [[1, 1], [1, 0]]
print(fib(int(input())))
