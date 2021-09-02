# DFS 구현
def dfs(graph, visited, node):
    visited[node] = True
    print("dfs visit: ", node)
    for adj_node in graph[node]:
        if not visited[adj_node]:
            dfs(graph, visited, adj_node)


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


dfs(graph, visited, 1)
