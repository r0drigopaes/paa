while True:
	try:
		n = int(input())
	except (EOFError):
		break

	inputList = []	
	for i in range(0,n):
		inputList.append(int(input()))

	maxSum = 0
	for i in range(0, len(inputList)):
		for j in range(i, len(inputList)):
			sum = 0
			for k in range(i,j):
				sum += inputList[k]
			
			if sum > maxSum:
				maxSum = sum

	print(maxSum)