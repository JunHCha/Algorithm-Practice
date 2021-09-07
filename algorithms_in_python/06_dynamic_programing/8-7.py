# 가로 길이가 N, 세로 길이가 2인 직사각형 형태의 얇은 바닥이 있다. 태일이는 이 바닥을 1 x 2, 2 x 1, 2 x 2 덥개를 이용해 채우려고 한다

# 바닥을 채우는 모든 경우의 수를 구하시오.

# 예를 들어 2 x 3 크기의 바닥을 채우는 경우의 수는 5가지다.

# 입력 조건:

# 첫째 줄에 N이 주어진다. (1 ≤ N ≤ 1000)

# 출력 조건:

# 둘째 줄에 2 x N 크기의 바닥을 채우는 방법의 수를 796796으로 나눈 나머지를 출력한다.

# my answer
n = int(input())
d = [0] * 1001

d[1] = 1
d[2] = 3


def tile(x):
    if d[x] != 0:
        return d[x]
    d[x] = tile(x - 1) + 2 * tile(x - 2)
    return d[x]


print("my answer: " + str(tile(n) % 796796))

# solution
d = [0] * 1001

d[1] = 1
d[2] = 3
for i in range(3, n + 1):
    d[i] = (d[i - 1] + 2 * d[i - 2]) % 796796

print("solution: " + str(d[n]))
