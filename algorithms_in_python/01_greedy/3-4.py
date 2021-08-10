# 어떠한 수 N이 1이 될 때까지 다음의 두 과정 중 하나를 반복적으로 선택하여 수행하려고 한다.
# 단, 두 번째 연산은 N이 K로 나누어떨어질 때만 선택가능하다.

# 1. N에서 1을 뺀다.
# 2. N을 K로 나눈다.

# N과 K가 주어질 때 N이 1이 될 때까지 최소 수행횟수를 구하시오.


# 입력조건:
# 첫째 줄에 N(2≤ N ≤ 100000)과 K(2≤ K ≤ 100000)이 공백으로 주어진다. N은 항상 K보다 크거나 같다.

N, K = map(int, input().split())
count = 0

while True:
    target = (N // K) * K
    count += N - target
    N = target

    if N < K:
        break

    N //= K
    count += 1

count += N - 1
print(count)
