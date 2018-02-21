# rede de telecomunicações

g = []
visited = []
parent = []
disc = []
low = []
ans = 0
disc_time = 0

def dfs(u):
	global g, visited, parent, disc, low, ans, disc_time

	visited[u] = True
	disc[u] = disc_time
	low[u] = disc_time
	disc_time += 1
	children = 0
	for v in g[u]:
		if (not visited[v]):
			parent[v] = u
			children += 1

			dfs(v)
			
			if (parent == -1 and children >1):
				if (not articulation[u]):
					ans += 1
				articulation[u] = True
			elif (parent != -1 and disc[u] <= low[v]):
				if (not articulation[u]):
					ans += 1
				articulation[u] = True
			
			low[u] = min(low[u], low[v])

		elif (parent[v] != u):
			low[u] = min(disc[v], low[u])


n = int(input())
while ( n != 0):
	g = [ [] for i in range(n+1) ]
	visited = [False] * (n+1)
	articulation = [False] * (n+1)
	parent = [-1] * (n+1)
	disc = [0] * (n+1)
	low = [0] * (n+1)
	ans = 0
	disc_time = 0

	line = list(map(int, input().split()))
	s = line[0]

	print(line)
	while (s != 0):	
		# Falta deixar bidirecional
		g[s] += line[1:]
		
		line = list(map(int, input().split()))
		s = line[0]

	print(g)

	for i in range(1,(n+1)):
		if (not visited[i]):
			dfs(i)
	print(ans)

	n = int(input())




