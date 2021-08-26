from typing import List


N, M, K = map(int, input().split())
numbers = list(map(int, input().split()))
numbers.sort()

res = (M // (K + 1)) * (K * numbers[-1] + numbers[-2])
remains = M % (K + 1)
while remains:
    res += numbers[-1]
    remains -= 1

print(res)
