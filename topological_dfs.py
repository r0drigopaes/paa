DEBUG = True

graph = []
visited = []
vertices = 9
top_sorting = []
names = {}

def dfs(u):
    global visited, graph, top_sorting

    if (DEBUG):
        print("Visiting: {}".format(u))

    visited[ u ] = True
    for v in graph[ u ]:
        if not visited[ v ]:
            dfs(v)
    top_sorting.append(u)

# Ilustra a criação de um grafo direcionado
def init_directed_graph():    
    global visited, graph
    
    visited = [False] * vertices
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

    graph[0].append(1)
    graph[0].append(7)
    graph[1].append(2)
    graph[1].append(7)
    graph[2].append(5)
    graph[3].append(2)
    graph[3].append(4)
    graph[4].append(5)
    graph[6].append(7)    

    if (DEBUG):
        print(graph)


init_directed_graph()
for i in range(vertices):
	if not visited[i]:
		dfs(i)

print("Toplogical order:")
while top_sorting:
	print(names[top_sorting.pop()])

