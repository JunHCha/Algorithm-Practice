# 정수 N이 입력되면 00시 00분 00초 부터 N시 59분 59초까지의 모든 시각 중에서 3이 하나라도 포함되는 모든 경우의 수를 구하는 프로그램을 작성하시오

n = int(input())

cnt = 0
for h in range(0, n + 1):
    for m in range(0, 60):
        for s in range(0, 60):
            if "3" in str(h) + str(m) + str(s):
                cnt += 1
            s += 1
        m += 1
    h += 1

print(cnt)
