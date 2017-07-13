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
		sum = 0
		for j in range(i, len(inputList)):
			
			sum += inputList[j]

			if(sum > maxSum):
				maxSum = sum
				begin = i
				end = j

	print(maxSum)