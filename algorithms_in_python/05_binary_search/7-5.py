# 전자 매장에 부품이 N개 있다. 각 부품은 정수 형태의 고유번호가 있다.

# 어느날 M 개 종류의 부품에 대한 대량 주문이 들어와서 견적서를 작성해야 한다.

# 가게 안에 모든 부품이 있는지 확인하라.

# 입력 조건:

# 첫째 줄에 정수 N이 주어진다. (1 ≤ N ≤ 1,000,000)

# 둘째 줄에 공백으로 구분하여 N개의 정수가 주어진다.

# 셋쨰 줄에 정수 M이 주어진다. (1 ≤ M ≤ 100,000)

# 넷째 줄에 공백으로 구분하여 M개의 정수가 주어진다.

# 출력 조건:

# 첫째 줄에 각 부품에 대해 yes, no를 공백으로 구분하여 출력한다.
n = int(input())
available = list(map(int, input().split()))
m = int(input())
requests = list(map(int, input().split()))

available.sort()


def binary_search(array, target, start, end):
    mid = (start + end) // 2
    if target == array[mid]:
        return "yes"
    elif start >= end:
        return "no"
    elif target < array[mid]:
        return binary_search(array, target, 0, mid - 1)
    elif target > array[mid]:
        return binary_search(array, target, mid + 1, end)


for target in requests:
    print(binary_search(available, target, 0, n - 1), end=" ")
