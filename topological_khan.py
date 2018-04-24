from collections import deque

DEBUG = True

graph = []
top_sorting = deque([])
indegree = []
names = {}

vertices = 9

def khan():
	global graph, top_sorting, indegree

	deleted = [False] * len(graph)
	q = deque([])

	# Adiciona na fila todos os vértices que não possuem
	# nenhuma aresta chegando nele.
	for i in range(len(graph)):
		if (indegree[i] == 0):
			q.append(i)
	
	while q:
		u = q.popleft()
		if (DEBUG):
			print("Visiting: {}".format(u))

		top_sorting.append(u)
		deleted[u] = True
		for v in graph[ u ]:
			if (not deleted[v]):
				indegree[v] -= 1
				if (indegree[v] == 0):
					q.append(v)

	return len(graph) == len(top_sorting)


def add_edge(u, v):
	graph[u].append(v)
	indegree[v] += 1

# Ilustra a criação de um grafo direcionado
def init_directed_graph():    
    global indegree, graph
    
    indegree = [0] * vertices

    # Lista de adjacências para cada vértice
    for i in range(vertices):
        graph.append( [] )
    
    # Exemplo de grafo em: https://docs.google.com/presentation/d/190PjxCX75m6VpJrNdR02j4yZJJPTGXl3OxQnrL_ON08/edit#slide=id.g43a0ef4df_024
    names[0] = "cueca"
    names[1] = "calças"
    names[2] = "cinto"
    names[3] = "camisa"
    names[4] = "gravata"
    names[5] = "terno"
    names[6] = "meia"
    names[7] = "sapato"
    names[8] = "relógio"

    add_edge(0,1)
    add_edge(0,7)    
    add_edge(1,2)
    add_edge(1,7)
    add_edge(2,5)
    add_edge(3,2)
    add_edge(3,4)
    add_edge(4,5)
    add_edge(6,7)


    if (DEBUG):
        print(graph)


init_directed_graph()
khan()

print("Toplogical order:")
while top_sorting:
	print(names[top_sorting.popleft()])