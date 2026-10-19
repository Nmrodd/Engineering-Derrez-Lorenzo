"""Recherche en largeur sur un petit graphe non oriente."""
from collections import deque

def bfs_shortest_path(graph, start, goal):
    queue=deque([(start,[start])]); seen={start}
    while queue:
        state,path=queue.popleft()
        if state == goal: return path
        for nxt in graph.get(state,[]):
            if nxt not in seen:
                seen.add(nxt);queue.append((nxt,path+[nxt]))
    return None

if __name__ == '__main__':
    g={'A':['B','C'],'B':['A','D'],'C':['A','D'],'D':['B','C','E'],'E':['D']}
    path=bfs_shortest_path(g,'A','E')
    print(path, 'mouvements :',len(path)-1)
    assert len(path)-1 == 3
