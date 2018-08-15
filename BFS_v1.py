from queue import *

def bfs(graph, vertex, fr, ar):
    dist = []
    vstd = []
    for x in range(0,vertex):
        dist.append(-1)
        vstd.append(False)

    dist[ int(fr) ] = 0
    vstd[ int(fr) ] = True
    q = Queue()
    q.put( fr )
    while not q.empty():
        u = q.get()
        print( "Vértice " + str(u) + " com distância " + str(dist[int(u)]) )
        for w in graph[ int(u) ]:
            if not vstd[ int(w) ]:
                dist[ int(w) ] = int(dist[int(u)]) + 1
                vstd[ int(w) ] = True
                q.put(w)
    return vstd[ int(ar) ]


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
    bfs(graph,v,0,3)

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
    bfs(graph,v,0,3)

initGraphDirect()

initGraphUndirected()
