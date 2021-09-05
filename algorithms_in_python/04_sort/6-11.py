# N명의 학생 정보가 있다. 학생 정보는 학생의 이름과 학생의 성적으로 구분된다.

# 각 학생의 이름과 성적 정보가 주어질 때 성적이 낮은 순서대로 학생의 이름을 출력하시오

# 입력조건: 첫째 줄에 학생 수 N이 입력된다 (1 ≤ N ≤ 100,000)

# 둘째 줄부터 학생의 이름과 점수가 공백으로 구분되어 입력된다.

# 출력조건: 모든 학생의 이름을 성적이 낮은 순서대로 출력한다.

data = []
n = int(input())

for _ in range(n):
    input_data = input().split()
    student = (input_data[0], input_data[1])
    data.append(student)

data.sort(key=lambda student: student[1])

for student in data:
    print(student[0], end=" ")
