DIAGONAL = 0
UP = 1
LEFT = 2
def lcs_bottom_up(str1, str2):
	memo = []
	path = []
	for i in range(len(str1)+1):
		memo.append([0])
		path.append([-1])
		for j in range(len(str2)+1):
			memo[i].append(0)
			path[i].append(-1)

	for i in range(1,len(str1)+1):
		for j in range(1, len(str2)+1):			
			if (str1[i-1] == str2[j-1]):
				memo[i][j] = 1 + memo[i-1][j-1]
				path[i][j] = DIAGONAL
			else:
				if (memo[i-1][j] > memo[i][j-1]):
					path[i][j] = UP
					memo[i][j] = memo[i-1][j]
				else:
					path[i][j] = LEFT
					memo[i][j] = memo[i][j-1]

	# print(memo[i][j])
	i = len(str1) 
	j = len(str2)
	ans = ""
	while (i >= 0 and j >= 0):
		# print("[{}][{}]={}".format(i,j,path[i][j]))
		if (path[i][j] == DIAGONAL):
			if (ans != ""):
				ans = str1[i-1] + " " + ans
			else:
				ans = str1[i-1]
			i = i - 1
			j = j - 1
		elif (path[i][j] == UP):
			i = i - 1
		else:
			j = j - 1

	print(ans)


try:
	while (True):
		str1 = []
		str2 = []
		line = input()
		while (line != "#"):
			str1.extend(line.split())
			line = input()

		line = input()
		while (line != "#"):
			str2.extend(line.split())
			line = input()

		lcs_bottom_up(str1, str2)

except EOFError:
	pass


