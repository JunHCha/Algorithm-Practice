# 당신은 음식점의 계산을 도와주는 점원이다.
# 카운터에는 거스름돈으로 사용할 500원, 100원, 50원, 10원짜리 동전히 무한히 존재한다고 가정한다.
# 손님에게 거슬러 줘야 할 돈이 N원일 때 거슬러 줘야 할 동전의 최소 개수를 구하라.
# N은 항상 10의 배수이다.

N = int(input())
count = 0
coin_type = [500, 100, 50, 10]

for coin in coin_type:
    count += N // coin
    N %= coin

print(count)
