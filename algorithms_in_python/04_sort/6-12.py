# 동빈이는 두 배열 A, B를 갖고 있다. 두 배열은 N개의 원소로 구성되어 있으며, 배열의 원소는 모두 자연수이다.

# 동빈이는 최대 K번의 바꿔치기 연산을 할 수 있는데, A에 있는 원소 하나와 B에 있는 원소 하나를 골라서 바꾸는 것이다.

# 최종 목표는 배열 A의 모든 원소의 합이 최대가 되도록 하는 것이다.

# k 번의 바꿔치기 이후 A의 모든 원소 합이 최대가 되는 프로그램을 작성하시오

# 입력조건: 첫째 줄에 N, K가 공백으로 구분되어 입력된다. (1 ≤ N ≤ 100,000, 0≤ K ≤ N)

# 둘째 줄에 배열 A의 원소가 공백으로 구분되어 입력된다.

# 셋째 줄에 배열 B의 원소가 공백으로 구분되어 입력된다. 모든 원소는 10,000,000보다 작은 자연수이다.

# 출력조건: K번의 바꿔치기 이후 만들 수 있는 A의 모든 원소 합의 최댓값을 구한다.

n, k = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

a.sort()
b.sort(reverse=True)

for i in range(k):
    if a[i] < b[i]:
        a[i], b[i] = b[i], a[i]
    else:
        break

print(sum(a))
