# 하나의 수열에는 다양한 수가 존재한다. 이 수를 큰 수부터 작은 수의 순서로 정렬하시오.

# 입력 조건: 첫째 줄에 수열에 속한 수의 개수 N이 주어진다. (1 ≤ N ≤ 500)

# 둘째 줄부터 N 개의 수가 입력된다.

n = int(input())
array = []

for _ in range(n):
    array.append(int(input()))

array.sort(reverse=True)

for num in array:
    print(num, end=" ")
