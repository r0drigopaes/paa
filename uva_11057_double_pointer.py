try:
	while True:		
		n = int(input())
		books = list(map(int, input().split()))
		money = int(input())

		books.sort()
		l = 0
		r = n-1
		while (l < r):
			value = books[l] + books[r]
			if (value == money):
				best_pair = [l,r]
				l += 1
				r -= 1
			elif (value < money):
				l += 1
			else:
				r -= 1

		print("Peter should buy books whose prices are {} and {}.".format(books[best_pair[0]], books[best_pair[1]]))
		print()
		
		input()
except EOFError:
	pass
