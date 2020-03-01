/*
https://www.acmicpc.net/problem/9663
문제
N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.

N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. (1 ≤ N < 15)

출력
첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define MAX_NUM 15

using namespace std;

int n, col[MAX_NUM], incline[2 * MAX_NUM], decline[2 * MAX_NUM], cnt;


void solve(int r) {
	if (r >= n) {
		cnt++;
		return;
	}
	for (int c = 0; c < n; c++) {
		if (!col[c] && !incline[r + c] && !decline[n + (r - c)]) {
			col[c] = incline[r + c] = decline[n + (r - c)] = 1;
			solve(r + 1);
			col[c] = incline[r + c] = decline[n + (r - c)] = 0;
		}			
	}
	

}

int main() {
	cin >> n;
	solve(0);
	cout << cnt << endl;
	system("pause");
	return 0;
}