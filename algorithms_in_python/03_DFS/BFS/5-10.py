# N * M 크기의 얼음 틀이 있다. 구멍이 뚫린 부분은 0, 칸막이는 1로 표시된다.

# 구멍이 뚫린 부분끼리 상,하,좌,우 붙어있는 경우 연결된 것으로 간주한다.

# 얼음 틀 모양이 주어졌을 때 생성되는 총 아이스크림 개수를 구하라.

# 입력조건:

# 첫 번째 줄에 얼음 틀의 세로 길이 N과 가로 길이 M이 주어진다. (1≤N, M ≤ 1000)

# 둘째 줄부터 얼음 틀의 형태가 주어진다.

n, m = map(int, input().split())

ice_frame = []
for _ in range(n):
    ice_frame.append(list(map(int, input())))

dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]


def isFrame(x, y):
    return x >= 0 and x < n and y >= 0 and y < m


def dfs(graph, x, y, cnt):
    graph[x][y] = cnt
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if isFrame(nx, ny) and graph[nx][ny] == 0:
            dfs(graph, nx, ny, cnt)


count = -1
for i in range(n):
    for j in range(m):
        if ice_frame[i][j] == 0:
            dfs(ice_frame, i, j, count)
            count -= 1

print(-1 * (count + 1))
for i in range(n):
    print(ice_frame[i])
