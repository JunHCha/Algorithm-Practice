# 바텀 업 피보나치

d = [0] * 200

d[1] = 1
d[2] = 1
n = 100

for i in range(3, 100 + 1):
    d[i] = d[i - 1] + d[i - 2]

print(d[n])
