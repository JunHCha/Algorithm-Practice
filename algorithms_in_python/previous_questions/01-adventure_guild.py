# 한 마을에 모험가가 N명 있습니다.

# 모험가 길드에서는 N명의 모험가를 대상으로 '공포도'를 측정하였는데, '공포도'가 높으면 쉽게 공포를 느껴 위험상황 대처 능력이 떨어집니다.

# 길드장은 모험가 그룹을 안전하게 구성하고자 공포도가 X인 모험가는 반드시 X명 이상으로 구성한 모험가 그룹에 참여해야 여행을 떠날 수 있도록 규정했습니다.

# N 명의 모험가에 대한 정보가 주어졌을 때, 여행을 떠날 수 있는 그룹 수의 최댓값을 구하세요.

# 모든 모험가가 그룹에 포함될 필요는 없습니다.


# 입력 조건:

# 첫쨰 줄에 모험가의 수 N이 주어집니다. (1 ≤ N ≤ 100000)
# 둘째 줄에 모험가의 공포도 값을 N 이하의 자연수로 주어지며, 공백으로 구분됩니다.

N = int(input())
fear = list(map(int, input().split()))
fear.sort()

group = 0
count = 0
for i in fear:
    count += 1
    if count >= i:
        group += 1
        count = 0

print(group)
