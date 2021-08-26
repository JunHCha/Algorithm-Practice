N, M = map(int, input().split())
cards = []
res = -1
for i in range(N):
    numbers = list(map(int, input().split()))
    res = max(res, min(numbers))

print(res)
