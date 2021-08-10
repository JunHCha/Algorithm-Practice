/*
https://www.acmicpc.net/problem/9663
����
N-Queen ������ ũ�Ⱑ N �� N�� ü���� ���� �� N���� ���� ������ �� ���� ���� �����̴�.

N�� �־����� ��, ���� ���� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� �־�����. (1 �� N < 15)

���
ù° �ٿ� �� N���� ���� ������ �� ���� ���� ����� ���� ����Ѵ�.
*/

 
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
	 
	return 0;
}