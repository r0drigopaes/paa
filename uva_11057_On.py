best_pair = [0,0]
try:
	while True:		
		n = int(input())
		books = list(map(int, input().split()))
		money = int(input())

		visited = {}
		# Poderia ficar ainda melhor em eficiência de tempo se usássemos uma array no lugar do map
		visited[books[0]] = True
		best_diff = 1000001
		for i in range(1, n):
			complement = money - books[i]			
			if (complement in visited):
				if (abs(books[i]-complement) < best_diff):
					best_diff = abs(books[i]-complement)
					best_pair = [complement, books[i]]
			visited[books[i]] = True


		best_pair.sort()
		print("Peter should buy books whose prices are {} and {}.".format(best_pair[0], best_pair[1]))
		print()
		
		input()
except EOFError:
	pass
