# Programacao Dinamica
# Huxley  874

import sys

sys.setrecursionlimit(100000)

memo = []
v  = []

def dp(i):
	if (i == 0):
		return 0
	if (memo[i] != -1):
		return memo[i]	
	best = -1
	# escolher o tamanho do corte
	for j in range(1, i+1):
		best = max(best, v[j-1] + dp(i-j))

	memo[i] = best
	return best


def dp_bottom(i):
	memo[0] = 0;
	for j in range(1, i+1):
		best = -1
		for k in range(j):
			best = max(best, v[k] + memo[j-(k+1)])	
		memo[j] = best
	return memo[i]


n = int(input())
while n != 0:
	v = []
	memo = [-1] * (n+1)
	for i in range(n):
		v.append(int(input()))
	
	print(dp(n))
	# print(dp_bottom(n))
	n = int(input())



