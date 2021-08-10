/*
n * n���� ���� �־�����.
��ġ�� �ʴ� �� ���� �� �࿡�� ���� �ϳ��� ���� n���� ���� �ּ����� ���Ͻÿ�.

*/

// ���� ���ð� ������ ����

 
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
	 
	return 0;
}
