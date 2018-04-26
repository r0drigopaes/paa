# Expondo a corrupção
# BFS, DP, Componentes conectados

from collections import deque 

MAX_CONGRESSMEN = 200
DELTA = int( MAX_CONGRESSMEN / 2 )

graph = []
visited = []
cost = []
components = []
memo = {}

def bfs(s):
	global graph, visited, cost, components
	# print("BFS({})".format(s))
	q = deque([]) 
	q.append(s);	
	
	component_cost = 0
	pd_members = 0
	prism_members = 0
	
	while q:
		u = q.popleft()
		if visited[u]:
			continue
		visited[u] = True

		# print("Pop {}".format(u))
		
		component_cost += cost[u]
		if (u < DELTA):
			pd_members += 1
		else:
			prism_members += 1
		

		for v in graph[u]:
			if not visited[v]:
				q.append(v)
	
	components.append((component_cost, [pd_members, prism_members]))
	# print(components)


# Mochila, com o identificador do componente conectado,
# o quanto que ainda resta de orçamento e qual o partido
# que está sendo contado (que é o que será maximizado)
def knapsack(i, remaining_budget, party):
	global components, memo
	
	# print("DP({},{},{})".format(i, remaining_budget, party))
	
	# Parada 1: acabou o dinheiro
	if (remaining_budget < 0):
		return -10000
	
	# Parada 2: acabaram os componentes
	if (i == len(components)):
		return 0	

	# Parada 3: Já foi calculado antes
	if ((i, remaining_budget) in memo):
		return memo[(i, remaining_budget)]	

	# Decidir subornar
	opt1 = components[i][1][(party+1)%2] + knapsack(i+1, remaining_budget - components[i][0], party)
	# Decidir não subornar
	opt2 = components[i][1][party] + knapsack(i+1, remaining_budget, party)

	memo[(i,remaining_budget)] = max(opt1, opt2)
	# print("opt1 = {}, opt2={}, memo[({},{})]".format( opt1, opt2, i, remaining_budget))

	return memo[(i,remaining_budget)]

# begin
pd_size, prism_size, rivalities, budget = map(int, input().split())

for i in range(MAX_CONGRESSMEN):
	graph.append([])
	visited.append(False)
	cost.append(0)
# print(cost)

pd_costs = list(map(int, input().split()))
for i in range(pd_size):
	cost[i] = pd_costs[i]

prism_costs = list(map(int, input().split()))
for i in range(prism_size):
	cost[DELTA + i] = prism_costs[i]



for i in range(rivalities):
	source, dest = map(int, input().split())
	# print("{}->{}".format(source, dest))
	graph[source-1].append(DELTA + dest-1)
	graph[DELTA + dest-1].append(source-1)


# print(graph)

for i in range(pd_size):
	if not visited[i]:
		bfs(i)
for i in range(prism_size):
	if not visited[DELTA + i]:
		bfs(DELTA + i)


better_pd = knapsack(0, budget, 0)
memo = {}
better_prism = knapsack(0, budget, 1)
print("{} {}".format(better_pd, better_prism))