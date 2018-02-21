def counting_sort(n, min, max):
    p = (max - min) + 1     #ajusta o tamanho do array de ordenação
    x = [0]*p

    for j in range(len(n)):
        x[n[j] - min] += 1  #indices do array x contém a quantidade de elementos da entrada


    y = 0
    for k in range(p):
        while (x[k] > 0):
            n[y] = k + min
            y += 1
            x[k] -= 1

    return n



n = []

min = 10E6
max = 0


for i in input().split():
    i = int(i)
    n.append(i)
    if(i > max): max = int(i)
    if(i < min): min = int(i)


counting_sort(n, min, max)



print(n)