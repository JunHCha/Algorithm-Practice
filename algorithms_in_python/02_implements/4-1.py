# 여행가 A는 N * N 크기의 정사각형 공간 위에 서있다. 이 공간은 1 * 1 크기의 정사각형으로 나누어져 있다. 가장 왼쪽 위 좌표는 (1, 1)이며, 가장 오른쪽 아래 좌표는 (N, N)에 해당한다. 여행가 A는 상, 하, 좌, 우 방향으로 이동할 수 있으며, 시작은 항상 (1,1)이다. 여행가 A의 이동계획서는 L,R,U,D 중 하나의 문자가 띄어쓰기를 통해 반복적으로 적혀있다.

# L,R,U,D는 left, right, up, down 방향으로 1칸 씩 이동함을 의미한다.

# 이때 정사각형 공간을 벗어나는 움직임은 무시된다.

# 계획서가 주어졌을 때 A의 최종 좌표를 출력하는 프로그램을 작성하시오.

# 입력조건:

# 첫째 줄에 N이 주어진다 (1 ≤ N ≤ 100)

# 둘째 줄에 A의 계획서가 주어진다. (1 ≤ 이동 횟수 ≤ 100)

# 출력조건:

# 최종 목적지 좌표 X,Y를 공백으로 구분하여 출력한다.

n = int(input())
x, y = 1, 1
plans = input().split()

dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]
move_types = ["L", "R", "U", "D"]

for plan in plans:
    for i in range(len(move_types)):
        if plan == move_types[i]:
            nx = x + dx[i]
            ny = y + dy[i]
    if nx < 1 or ny < 1 or nx > n or ny > n:
        continue

    x, y = nx, ny

print(x, y)
