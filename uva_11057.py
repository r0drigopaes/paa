money = 0
books = []
best_diff = 0
best_pair = [0,0]

def binary_search(x, b, e):	
	global best_diff, money, best_pair, books
	
	if (b > e):
		return
	mid = (b + e) // 2
	value = books[x] + books[mid]
	if (value == money):
		if (books[mid] - books[x] < best_diff):			
			best_diff = books[mid] - books[x]
			best_pair = [x, mid]
		return
	elif ( value > money):
		binary_search(x, b, mid-1)
	else:
		binary_search(x, mid+1, e)

try:
	while True:		
		n = int(input())
		books = list(map(int, input().split()))
		money = int(input())
		half = money // 2
		best_diff = 1000002
		best_pair = [-1,-1]

		books.sort()

		i = 0
		while (i < n and books[i] <= half):
			binary_search(i, i+1, n-1)
			i+=1
		print("Peter should buy books whose prices are {} and {}.".format(books[best_pair[0]], books[best_pair[1]]))
		print()
		
		input()
except EOFError:
	pass
