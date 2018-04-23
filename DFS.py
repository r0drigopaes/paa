from queue import *

DEBUG = True

graph = []
visited = []

def dfs(u):
    global visited, graph

    if (DEBUG):
        print(u)

    visited[ u ] = True
    for v in graph[ u ]:
        if not visited[ v ]:
            dfs(v)

# Ilustra a criação de um grafo direcionado
def init_directed_graph():    
    global visited, graph

    vertices = 4
    visited = [False] * vertices
    # Lista de adjacências para cada vértice
    for i in range(0,vertices):
        graph.append( [] )
    
    graph[0].append(1) # 0 -> 1
    graph[0].append(2) # 0 -> 2
    graph[1].append(2) # 1 -> 2
    graph[2].append(3) # 2 -> 3
    if (DEBUG):
        print(graph)
    
    dfs(0)  

init_directed_graph()