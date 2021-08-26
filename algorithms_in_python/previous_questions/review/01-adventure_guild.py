N = int(input())
fears = list(map(int, input().split()))

fears.sort()
count = 0
while N:
    size = 0
    for i in range(fears[0]):
        size += 1
        if fears[i] <= size:
            count += 1
            fears = fears[i + 1 :]
            N -= size
            break
    N -= 1

print(count)
