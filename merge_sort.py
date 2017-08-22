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

def mergeSort(data):
    if (len(data) <= 1):
        return(data)

    middle = int(len(data) / 2)
    left = mergeSort(data[0 : middle]) # O data de 0 até middle
    right = mergeSort(data[middle : len(data)]) # O data de middle até o final

    result = simpleMerge(left, right)
    return(result)

a = list()
n = int(input())

for i in range(n):
    a.append(int(input()))

result = mergeSort(a)

for i in result:
    print(i)
