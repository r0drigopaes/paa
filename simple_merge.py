def simpleMerge(a, b):
    total = len(a) + len(b)
    j, k = 0, 0

    c = list()

    for i in range(total):
        if (k == len(b) or (j < len(a) and a[j] < b[k])):
            c.append(a[j])
            j += 1
        else:
            c.append(b[k])
            k += 1

    return(c)


aSize, bSize = map(int, input().split()) # Apenas para acordar com o simple_merge.in

a = list(map(int, input().split())) # Lê uma lista em uma linha
b = list(map(int, input().split())) # Lê uma lista em uma linha

result = simpleMerge(a, b)

for i in result:
    print(i)
