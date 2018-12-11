from math import *
st = []
a = []

# i = indice da seg_tree (inicialmente = 1)
# l = intervalo esquerdo fechado do array
# r = intervalo direito aberto do array
def build(i, l, r):
	if (r - l < 2 ):
		st[i] = a[l]
		return
	mid = int((l + r) / 2)
	build(i*2, l, mid)
	build(i*2 +1, mid, r)
	st[i] = st[i*2] + st[i*2+1]

def sum(b, e, i, node_b, node_e):
	if (b >= node_e or e <= node_b):
		return 0
	elif (b <= node_b and e >= node_e):
		return st[i]
	else:
		mid = int((node_b + node_e) / 2)
		return sum(b, e, i*2, node_b, mid) + sum(b, e, i*2+1, mid, node_e)

def modify(pos, value, i, node_b, node_e):
	st[i] += (value - a[pos])
	if (node_e - node_b < 2):
		a[pos] = value
	else:
		mid = int((node_b + node_e)/2)
		if (pos < mid):
			modify(pos, value, i*2, node_b, mid)
		else:
			modify(pos, value, i*2+1, mid, node_e)




# leitura de dados
n = int(input()) + 1
a = list(map(int, input().split()))
a = [0] + a
b, e = map(int, input().split())

# altura da arvore (coloco mais 1 para gerar sempre uma arvore completa)
h = int(log(float(n), 2)) + 1 
# numero maximo de nos (mantive um a mais para ignorar a posição 0), 
st = [0] * ((2 ** h) *2 + 1)

build(1, 1, n)
print(sum(b,e,1, 1, n))
modify(2, 7, 1, 1, n)
print(sum(b,e,1, 1, n))