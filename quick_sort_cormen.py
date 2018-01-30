def swap(array, a, b):
    aux = array[a]
    array[a] = array[b]
    array[b] = aux
'''    
lo e hi são inclusivos
'''
def partition(a, lo, hi):
    pivot = a[hi]
    '''
        O i vai demarcar o final da partição daqueles
        que são menores que o pivô
    '''
    i = lo - 1
    for j in range(lo, hi):
        if(a[j] <= pivot):
            '''
                Temos que crescer a partição dos menores
            '''
            i+=1
            swap(a, i, j)
    '''
        Coloca o pivô logo depois da partição dos menores
    '''
    swap(a, i+1, hi)
    return i+1 #indice do pivô

'''    
lo e hi são inclusivos
'''
def quicksort(a, lo, hi):
    if(lo < hi):
        pos = partition(a, lo, hi)
        quicksort(a, lo, pos-1)
        quicksort(a, pos+1, hi)


#input na mesma linha:
a = list(map(int, input().split()))
n = len(a)
#input com enter:
'''
n = int(input())
a = []
for i in range(0, n):
    a.append(int(input()))
'''
quicksort(a, 0, n-1)
print(a)
