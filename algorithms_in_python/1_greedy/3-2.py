# 동빈이가 생각한 큰수의 법칙은 다양한 수로 이루어진 배열이 있을 때 주어진 수들을 M번 더하여 가장 큰 수를 만드는 법칙이다.
# 단, 배열의 특정 인덱스에 해당하는 수가 연속해서 K번을 초과하여 더해질 수 없다.
# 예를 들어 2,4,5,4,6으로 이루어진 배열이 있을 때 M이 8이고, K가 3이라면, 6 + 6 + 6 + 5 + 6 + 6 + 6 + 5 = 46 이 큰 수이다.

# 입력 조건 :

# 첫째 줄에 N(2 ≤ N ≤1000), M(1 ≤ M ≤ 10000), K(1≤K≤10000)의 자연수가 주어지며 공백으로 구분된다.

# 둘째 줄에 N개의 자연수가 공백을 갖고 주어진다. 자연수는 1이상 10000이하이다.

# K는 M보다 작다.

N, M, K = map(int, input().split())

numbers = list(map(int, input().split()))
numbers.sort()

first = numbers[-1]
second = numbers[-2]

count = 0
count = int((M / (K + 1))) * K
count += M % (K + 1)

res = 0
res += count * first
res += (M - count) * second

print(res)
