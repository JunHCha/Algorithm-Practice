# 메모이제이션으로 피보나치 구현하기
# 100번째 피보나치 수를 구할 때 일반적인 재귀로는 절대 못구한다.
# 탑 다운
d = [0] * 200


def fibo(x):
    if x == 1 or x == 2:
        return 1

    if d[x] != 0:
        return d[x]

    d[x] = fibo(x - 1) + fibo(x - 2)
    return d[x]


print(fibo(100))
