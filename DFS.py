from queue import *

def dfs(graph,vstd,fr):
    print( "Visited " + str(fr) )
    vstd[ int(fr) ] = True
    for u in graph[ int(fr) ]:
        if not vstd[ int(u) ]:
            dfs(graph,vstd,u)
        pass
    pass

def searchDfs(graph, vertex, fr, ar):
    vstd = []
    for x in range(0,vertex):
        vstd.append(False)
        pass
    dfs( graph, vstd, fr )
    return vstd[int(ar)]

def initGraphDirect():
    graph = [[]]
    v = 4
    for x in range(0,v-1):
        graph.append( [] )
    graph[0].append(1)
    graph[0].append(2)
    graph[1].append(2)
    graph[2].append(3)
    print(graph)
    searchDfs(graph,v,0,3)
    pass

def initGraphUndirected():
    graph = [[]]
    v = 4
    for x in range(0,v-1):
        graph.append( [] )
    graph[0].append(1)
    graph[1].append(0)
    graph[0].append(2)
    graph[2].append(0)
    graph[1].append(2)
    graph[2].append(1)
    graph[2].append(3)
    graph[3].append(2)
    print(graph)
    searchDfs(graph,v,0,3)
    pass


initGraphDirect()

initGraphUndirected()


