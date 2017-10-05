# Adega de Vinhos. Programação Dinâmica
# Huxley 602


def pd(b, e, y):	
	if (memo[b][e] != -1):
		return memo[b][e]
	elif (b == e):
		memo[b][e] = p[b] * y	
	else:
		# escolher o vinho da direita ou da esquerda
		left = p[b]*y + pd(b+1, e, y+1)
		right = p[e]*y + pd(b, e-1, y+1)
		memo[b][e] = left if (left > right) else right
	return memo[b][e]

while (True):
	try:
		n = int(input())
		p = []
		memo = []
		for i in range(n):
			p.append(int(input()))
		for i in range (n+1):
			memo.append([-1] * (n+1))
		print(pd(0, n-1, 1))
	except (EOFError):		
		break

