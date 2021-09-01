# 현민이는 게임 캐릭터가 맵 안에서 움직이는 시스템을 개발중이다.

# 캐릭터는 1x1 크기의 정사각형으로 이루어진 N x M 직사각형 위에 있다. 각각의 칸은 육지 혹은 바다이다.

# 캐릭터는 동서남북 중 한 곳을 바라본다.

# 맵의 각 칸은 (A, B)로 나타낼 수 있고, A는 북으로 부터 떨어진 칸의 개수, B는 서로부터 떨어진 칸의 개수이다.

# 캐릭터는 상하좌우로 움직일 수 있고, 바다로 된 공간은 갈 수 없다.

# 캐릭터의 움직임 메뉴얼은 다음과 같다.

# 1. 현재 위치, 현재 방향 기준 왼쪽(반시계 90도)부터 차례대로 갈 곳을 정한다.
# 2. 캐릭터의 왼쪽에 아직 안간 칸이 있다면, 왼쪽 회전후 전진한다. 이미 가본 칸이면 회전만 하고 1단계로 돌아간다.
# 3. 만약 네 방향 모두 가봤거나 바다로 되어있는 칸인 경우는, 방향을 유지한 채로 한 칸 뒤로 가고 1단계로 돌아간다. 뒤쪽 방향이 바다라면 움직임을 멈춘다.

# 캐릭터를 이동시킨 뒤 캐릭터가 방문한 칸의 수를 출력하는 프로그램을 만드시오.

# 입력 조건:

# 첫째줄에 세로크기 N과 가로크기 M이 공백으로 구분되어 입력 (3≤ N, M ≤ 50)

# 둘째 줄에 게임 캐릭터의 좌표 (A, B)와 바라보는 방향 d가 공백으로 구분하여 입력

# d의 값은 0, 1, 2, 3으로, 각각 북, 동, 남, 서를 의미한다.

# 셋째 줄부터 맵이 육지인지 바다인지 정보를 입력한다. 0은 육지, 1은 바다이다.

n, m = map(int, input().split())
x, y, direction = map(int, input().split())

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

visited = [[0] * m for _ in range(n)]
visited[x][y] = 1


def turn_left():
    global direction
    direction -= 1
    if direction == -1:
        direction = 3


maps = []
for i in range(n):
    maps.append(list(map(int, input().split())))

movable = True
while movable:

    for i in range(4):
        turn_left()
        nx = x + dx[direction]
        ny = y + dy[direction]

        if maps[nx][ny] == 1 or visited[nx][ny] == 1:
            if i == 3:
                nx = x - dx[direction]
                ny = y - dx[direction]
                if maps[nx][ny] == 1:
                    movable = False
                    break
                x = nx
                y = ny
                break

        else:
            x = nx
            y = ny
            visited[nx][ny] = 1
            break

count = 0
for line in visited:
    count += line.count(1)

print(count)
