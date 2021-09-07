# 개미 전사는 부족한 식량을 메꾸고자 메뚜기 마을의 식량창고를 몰래 공격중이다.

# 메뚜기 마을에는 여러 개의 식량창고가 있는데 식량창고는 일직선으로 이어져 있다.

# 각 식량창고에서는 정해진 수의 식량을 저장하고 있다.

# 개미 전사는 식량창고를 선택적으로 약탈하여 식량을 빼앗을 계획이다.

# 이때 메뚜기 정찰병은 식량창고 중 서로 인접한 식량창고가 공격받으면 바로 알아챌 수 있다.

# 따라서 개미전사는 최소 한 칸 이상 떨어진 식량창고를 약탈해야 한다.

# 개미 전사를 위해 식량창고 N개에 대한 정보가 주어졌을 때 얻을 수 있는 식량의 최댓값을 구하시오

# 입력 조건:

# 첫째 줄에 식량창고 개수 N이 주어진다 (3 ≤ N ≤ 100)

# 둘쨰 줄에 식량창고에 저장된 식량 개수 K가 주어진다  (0 ≤ K ≤ 1,000)

# 출력 조건:

# 첫째 줄에 개미전사가 얻을 수 있는 식량의 최댓값을 출력한다.

## own sol
n = int(input())
array = list(map(int, input().split()))
array.insert(0, -1)

d = [-1] * 101

for i in reversed(range(1, n + 1)):
    if i >= n - 1:
        d[i] = array[i]
        continue

    d[i] = array[i] + max(d[i + 2 :])

print("my answer: " + str(max(d[: n + 1])))

## answer
array.pop(0)
d = [0] * 100

d[0] = array[0]
d[1] = max(array[0], array[1])
for i in range(2, n):
    d[i] = max(d[i - 1], d[i - 2] + array[i])

print("sol answer: " + str(d[n - 1]))
