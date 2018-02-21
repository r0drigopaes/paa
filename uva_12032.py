rungs = []
diffs = []
n = 0

def is_possible(k):
	for diff in diffs:
		if (k < diff):
			return False
		elif (k == diff):
			k -= 1
			# É preciso colocar esse if principalmente para o caso onde o último elemento ficou negativo.
			if (k < 0):
				return False
	return True

def solve(b, e):	
	if (e==b):
		return e
	mid = (b+e) // 2
	if (is_possible(mid)):
		return solve(b, mid)
	else:
		return solve(mid+1, e)


test_cases = int(input())
for i in range(test_cases):	
	n = int(input())
	rungs = list(map(int, input().split())) # ligeiramente mais rapido que a list comprehension
	# rungs = [int(x) for x in input().split()]

	# Criar uma única lista com as diferenças para evitar ficar refazendo a conta todas as vezes
	diffs = [rungs[0]]
	best_guess = 10000000
	for j in range(1, n):
		d = rungs[j] - rungs[j-1]
		diffs.append(d)		
	
	print("Case {}: {}".format(i+1, solve(0, best_guess)))