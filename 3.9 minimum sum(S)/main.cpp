/*
n * n개의 수가 주어진다.
겹치지 않는 각 열과 각 행에서 수를 하나씩 뽑은 n개의 수의 최소합을 구하시오.

*/

// 교재 예시가 오류가 있음

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int n, map[11][11], visited[11];
int minn = 1000001;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
}

void dfs(int index, int res) {
	if (index == n) {
		if (minn > res) minn = res;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			dfs(index + 1, res + map[index][i]);
			visited[i] = 0;
		}
	}

}


int main() {
	input();
	dfs(0, 0);
	
	cout << minn;
	system("pause");
	return 0;
}
