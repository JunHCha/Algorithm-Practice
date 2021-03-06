/*
https://www.acmicpc.net/problem/2566
문제
<그림 1>과 같이 9×9 격자판에 쓰여진 81개의 자연수가 주어질 때, 이들 중 최댓값을 찾고 그 최댓값이 몇 행 몇 열에 위치한 수인지 구하는 프로그램을 작성하시오.

예를 들어, 다음과 같이 81개의 수가 주어지면



이들 중 최댓값은 90이고, 이 값은 5행 7열에 위치한다.

입력
첫째 줄부터 아홉 번째 줄까지 한 줄에 아홉 개씩 자연수가 주어진다. 주어지는 자연수는 100보다 작다.

출력
첫째 줄에 최댓값을 출력하고, 둘째 줄에 최댓값이 위치한 행 번호와 열 번호를 빈칸을 사이에 두고 차례로 출력한다. 최댓값이 두 개 이상인 경우 그 중 한 곳의 위치를 출력한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int map[9][9], maxNum, x, y;

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (map[i][j] > maxNum) {
				maxNum = map[i][j];
				x = i + 1;
				y = j + 1;
			}
		}
	}
	cout << maxNum << endl;
	cout << x << " " << y;
	system("pause");
	return 0;
}

