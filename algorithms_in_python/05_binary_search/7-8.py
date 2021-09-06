# 떡의 길이가 일정하지 않지만 한 봉지 안에 들어가는 떡의 총 길이는 절단기로 잘라서 맞춰준다.

# 절단기에 높이 (H)를 지정하면 줄지어진 떡을 한 번에 절단한다.

# 손님이 왔을 때 요청한 총 길이가 M일 때 적어도 M만큼의 떡을 얻기 위해 절단기에 설정할 수 있는 높이의 최댓값을 구하시오

# 입력조건:

# 첫째 줄에 떡의 개수 N과 요청한 떡의 길이 M이 주어진다. (1 ≤ N ≤ 1,000,000, 1 ≤ M ≤ 2,000,000,000)

# 둘째 줄에 떡의 개별 높이가 주어진다. 떡 높이 총합은 항상 M 이상이다. 높이는 10억보다 작거나 같은 양의 정수 혹은 0이다.

# 출력조건:

# 적어도 M 만큼의 떡을 집에 가져가기 위해 절단기에 설정할 수 있는 높이의 최댓값을 출력한다.

n, m = map(int, input().split())
cakes = list(map(int, input().split()))

cakes.sort()


def determination(cakes, h):
    sum = 0
    for cake in cakes:
        diff = cake - h
        sum += diff if diff > 0 else 0
    if sum == m:
        return "found"
    elif sum > m:
        return "large"
    else:
        return "small"


def binary_search(cakes, start, end):
    mid = (start + end) // 2
    if determination(cakes, mid) == "found" or start >= end:
        return mid
    elif determination(cakes, mid) == "small":
        return binary_search(cakes, 0, mid - 1)
    elif determination(cakes, mid) == "large":
        return binary_search(cakes, mid + 1, end)


print(binary_search(cakes, 0, cakes[-1]))
