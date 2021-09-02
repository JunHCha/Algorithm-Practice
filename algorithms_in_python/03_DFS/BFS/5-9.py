# BFS 구현
from collections import deque

q = deque()


def bfs(graph, visited, node):
    visited[node] = True
    q.append(node)
    print("visit: ", node)

    while q:
        print("queue: ", list(q))
        cur_node = q.popleft()
        for adj_node in graph[cur_node]:
            if not visited[adj_node]:
                visited[adj_node] = True
                q.append(adj_node)
                print("visit: ", adj_node)


graph = [
    [],
    # 1번 노드
    [2, 3, 8],
    # 2번 노드
    [1, 7],
    # 3번 노드
    [1, 4, 5],
    # 4번 노드
    [3, 5],
    # 5번 노드
    [3, 4],
    # 6번 노드
    [7],
    # 7번 노드
    [2, 6, 8],
    # 8번 노드
    [1, 7],
]

visited = [False] * 9


bfs(graph, visited, 1)
