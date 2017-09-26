def div_and_conquer(list):
	if len(list) == 1:
		if list[0] > 0:
			return list[0]
		else:
			return 0;
	else:
		sum = 0
		maxLeft = 0
		left = list[0:int(len(list)/2)]
		for x in reversed(range(0,len(left))):
			sum += left[x]

			if sum > maxLeft:
				maxLeft = sum

		sum = 0
		maxRight = 0
		right = list[int(len(list)/2):int(len(list))]
		for x in range(0,len(right)):
			sum += right[x]

			if sum > maxRight:
				maxRight = sum

		return max(max(div_and_conquer(left), div_and_conquer(right)), maxLeft+maxRight)

while True:
	try:
		n = int(input())
	except (EOFError):
		break

	inputList = []	
	for i in range(0,n):
		inputList.append(int(input()))
	
	print(div_and_conquer(inputList))

