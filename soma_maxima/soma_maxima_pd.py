while True:
	try:
		n = int(input())
	except (EOFError):
		break

	inputList = []	
	for i in range(0,n):
		inputList.append(int(input()))
	
	i = j = sum = maxSum = 0

	for k in range(0, len(inputList)):
		sum += inputList[k] 
		
		if(sum > maxSum):
			maxSum = sum

		elif(sum < 0):
			i = k
			sum = 0

		j = k

	print(maxSum)