# Versão com subcadeia de soma máxima (modificado para guardar a soma de todas as subcadeias)
MAX = 1000001


# Marca como verdadeiro todas as subsomas
def find_subset_sums(robbers_sum):
	subsets[0] = True
	for i in range(len(robbers)):
		a_sum = robbers_sum
		while (a_sum >= robbers[i]):
			if (subsets[a_sum - robbers[i]] is True):
				subsets[a_sum] = True
			a_sum -= 1

# Você tem que ser capaz de dividir o array em duas partes. Pois
# os ladrões podem atuar em paralelo.
def solve(robbers_sum, guard):

	find_subset_sums(robbers_sum)

	# Imagine que vamos dividir em dois conjuntos, então cada um poderia gastar o tempo 'guard', pois eles
	# ocorreriam em paralelo. Ou seja: guard * 2 seria o tempo total somando os dois conjuntos
	# Mas sabemos que a soma real de todos os ladrões é robbers_sum.
	# Logo, a nossa margem de sobra = guard*2 - robbers_sum. Ou seja, se encontrarmos uma subsoma
	# entre (guard - sobra) e guard, então o que resta no outro subconjunto com certeza vai caber, pois 
	# nunca ultrapassará o guard.
	# guard 			= [-------------			 ]
	# 2* guard 		= [--------------------------]
	# robbers_sum		= [-----------------------   ]
	# sobra 			= [			 			  ---]
	# guard - sobra	= [----------   			 ]

	# Achamos uma subsoma:
	# guard - sobra	= [----------X   			 ]
	# O que resta de robbers_sum nunca ultrapassará guard
	# robbers_sum		= [           ------------   ]

	a_sum = robbers_sum - guard  #sobra
	while (a_sum <= guard):
		if (subsets[a_sum]):
			return True
		a_sum += 1
	return False


t = int(input())
for i in range(t):
	subsets = [False] * MAX
	robbers = []
	n, guard = map(int,  input().split())
	robbers = list(map(int,  input().split()))
	robbers_sum = sum(robbers)
	if (solve(robbers_sum, guard)):
		print("YES")
	else:
		print("NO")

			

