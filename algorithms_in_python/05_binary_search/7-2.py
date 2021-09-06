# 이진탐색 재귀함수로 구현

n, target = map(int, input().split())
array = list(map(int, input().split()))


def binary_search(array, target, start, end):
    mid = (start + end) // 2
    if target == array[mid]:
        return mid
    elif target < array[mid]:
        return binary_search(array, target, 0, mid - 1)
    else:
        return binary_search(array, target, mid + 1, end)


print(binary_search(array, 7, 0, n - 1))
