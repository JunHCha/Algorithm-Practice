# N * M 크기의 미로가 있다. 시작 위치는 (1,1)이고 (N,M)에 출구가 있다.

# 괴물이 있는 부분은 0으로, 갈 수 있는 길은 1로 표시되어 있다.

# 이때 탈출하기 위한 최소 칸의 개수를 구하라. (처음, 마지막 칸 포함)

from collections import deque


n, m = map(int, input().split())
maze = []
count = 0

for _ in range(n):
    maze.append(list(map(int, input())))

q = deque()
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def isMaze(x, y):
    return x >= 0 and x < n and y >= 0 and y < m


def bfs(maze, start):
    q.append(start)
    maze[start[0]][start[1]] += 1
    while q:
        cur_position = q.popleft()
        cur_count = maze[cur_position[0]][cur_position[1]]
        for i in range(4):
            nx = cur_position[0] + dx[i]
            ny = cur_position[1] + dy[i]
            if isMaze(nx, ny) and maze[nx][ny] == 1:
                maze[nx][ny] = cur_count + 1
                q.append((nx, ny))


bfs(maze, (0, 0))
print(maze[n - 1][m - 1] - 1)
