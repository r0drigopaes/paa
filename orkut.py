from collections import deque

tc = 0
n = int(input())
while (n > 0):	
	index = {}
	indegree = {}	
	queue = []
	tc += 1	

	names = list(input().split())

	for i in range(n):
		index[names[i]] = []
		indegree[names[i]] = 0		

	for i in range(n):
		entrada = input().split()
		src = entrada[0]	
		amigos = entrada[2:]
		
		indegree[src] += int(entrada[1])
		for amigo in amigos:
			index[amigo].append(src)

	for i in range(n):
		if (indegree[names[i]] == 0):
			queue.append(names[i])	

	queue = deque(queue)

	ans = []
	while (len(queue) > 0):
		u = queue.popleft()
		ans.append(u)		
		for filho in index[u]:		
			indegree[filho] -= 1
			if (indegree[filho] == 0):
				queue.append(filho)

	print("Teste %d" % tc)
	if (len(ans) == n):
		print(*ans)
	else:
		print("impossivel")
	n = int(input())
	if (n > 0):
		print()
