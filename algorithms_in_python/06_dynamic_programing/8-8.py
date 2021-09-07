# N 종류의 화폐가 있다. 이 화폐를 최소개수로 그 가치 합이 M이 되도록 하려고 한다.

# 각 화폐는 몇 개든지 사용할 수 있으며, 구성은 같지만 순서만 다른 것은 같은 경우로 한다.

# 입력 조건:

# 첫째 줄에 N, M이 주어진다 (1 ≤ N ≤ 100, 1≤ M ≤ 10,000)

# 이후 N개 줄에 화폐 가치가 주어진다. 화폐가치는 10000이하의 자연수이다.

# 출력 조건:

# 첫째 줄에 M원을 만들기 위한 최소 화폐 개수를 출력한다.

# 불가능일 때는 -1을 출력한다.

# my answer
n, m = map(int, input().split())
money = []
for _ in range(n):
    money.append(int(input()))

d = [-1] * 10001

for unit in money:
    d[unit] = 1

for i in range(1, m + 1):
    compare_list = []
    for unit in money:
        if i - unit > 0 and d[i - unit] > 0:
            compare_list.append(d[i - unit])
    if len(compare_list):
        d[i] = min(compare_list) + 1

print("my answer: " + str(d[m]))

# solution
d = [10001] * (m + 1)
d[0] = 0
for i in range(n):
    for j in range(money[i], m + 1):
        if d[j - money[i]] != 10001:
            d[j] = min(d[j], d[j - money[i]] + 1)

if d[m] == 10001:
    print("solution: -1")
else:
    print("solution: " + str(d[m]))
