# Implementacao do algoritmo de Prim O(E log V) em Python
# Note que a unica funcao que representa a implementacao do algoritmo eh a funcao prim(graph,Vi=0,edge=[],vis=[])
# A funcao add_edge eh apenas auxiliar, e a funcao primDesconexo(graph) eh um adicional, e nao costuma sequer ser
# implementada para o algoritmo de Prim (pois no caso de um grafo ser desconexo, Kruskal eh a solucao ideal).
from heapq import heappop, heappush

MAXV = 7 # numero de vertices no grafo
# graph = [[] for x in xrange(MAXV)]

graph = []
la = [0,1,0,1,0,0,0]
lb = [1,0,1,1,1,0,0]
lc = [0,1,0,0,1,0,0]
ld = [1,1,0,0,1,1,0]
le = [0,1,1,1,0,1,1]
lf = [0,0,0,1,1,0,1]
lg = [0,0,0,0,1,1,0]

graph.append(la)
graph.append(lb)
graph.append(lc)
graph.append(ld)
graph.append(le)
graph.append(lf)
graph.append(lg)

print(graph)
def add_edge(v, u, w):
    graph[v].append((u,w))
    graph[u].append((v,w)) # considera que o grafo eh nao direcionado

# Se o grafo for totalmente conectado, Vi pode receber qualquer vertice sem diferenca no peso total da arvore gerada
# Se o grafo for desconexo, apenas a parte conectada a Vi tera sua arvore geradora minima calculada
# O retorno eh uma lista de tuplas edge[v]=(w,u), que representa, para cada v, a aresta u->v com peso w, usada para
# conectar a sub-arvore de v a sub-arvore de u na arvore geradora minima
def prim(graph, Vi=0, edge=[], vis=[]):
    # edge[v] = (pesoDaAresta(u->v), u)
    # Se edge[] ou vis[] nao tiverem sido gerados ainda, geramos. Geralmente esta condicao nao existe, e ambas as listas
    # sao geradas dentro do proprio prim; porem, para manter o primDesconexo em O(V + E log V), permitimos que sejam
    # passadas pelos parametros da funcao.
    if edge == []:
        edge = [(-1,-1)] * len(graph)
    if vis == []:
        vis = [False] * len(graph)

    edge[Vi] = (0,-1)
    heap = [(0,Vi)]

    while True:
        v = -1
        while len(heap) > 0 and (v < 0 or vis[v]):
            v = heappop(heap)[1]

        if v < 0 or edge[v][0] < 0:
            break
        vis[v] = True

        for (u, w) in graph[v]:
            if edge[u][0] < 0 or edge[u][0] > w:
                edge[u] = (w, v)
                heappush(heap, (edge[u][0],u))

    return edge

# Se o grafo for desconexo, pode-se usar:
def primDesconexo(graph):
    edge = [(-1,-1)] * len(graph)
    vis = [False] * len(graph)
    for i in xrange(len(graph)):
        if edge[i][0] == -1:
            prim(graph, i, edge, vis)
    return edge

prim(graph)    