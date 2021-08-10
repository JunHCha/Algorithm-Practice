/*
https://www.acmicpc.net/problem/2667
����
<�׸� 1>�� ���� ���簢�� ����� ������ �ִ�. 1�� ���� �ִ� ����, 0�� ���� ���� ���� ��Ÿ����. ö���� �� ������ ������ ����� ������ ������ ������ �����ϰ�, ������ ��ȣ�� ���̷� �Ѵ�. ���⼭ ����Ǿ��ٴ� ���� � ���� �¿�, Ȥ�� �Ʒ����� �ٸ� ���� �ִ� ��츦 ���Ѵ�. �밢���� ���� �ִ� ���� ����� ���� �ƴϴ�. <�׸� 2>�� <�׸� 1>�� �������� ��ȣ�� ���� ���̴�. ������ �Է��Ͽ� �������� ����ϰ�, �� ������ ���ϴ� ���� ���� ������������ �����Ͽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.



�Է�
ù ��° �ٿ��� ������ ũ�� N(���簢���̹Ƿ� ���ο� ������ ũ��� ������ 5��N��25)�� �Էµǰ�, �� ���� N�ٿ��� ���� N���� �ڷ�(0Ȥ�� 1)�� �Էµȴ�.

���
ù ��° �ٿ��� �� �������� ����Ͻÿ�. �׸��� �� ������ ���� ���� ������������ �����Ͽ� �� �ٿ� �ϳ��� ����Ͻÿ�.

*/

 
#include <stdio.h>
#include <algorithm>

#define MAX_NUM 26

using namespace std;

int n, count_;
int map[MAX_NUM][MAX_NUM], ans[625];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool isSafe(int x, int y) {
	return (x >= 0 && x < n) && (y >= 0 && y < n);
}

bool cmp(int a, int b) {
	return a < b;
}

void input() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)	{
			scanf("%1d", &map[i][j]);
		}
	}
}

void dfs(int x, int y, int cnt) {
	map[x][y] = cnt;
	for (int i = 0; i < 4; i++) {
		if (map[x + dx[i]][y + dy[i]] == 1 && isSafe(x + dx[i], y + dy[i])) {
			dfs(x + dx[i], y + dy[i], cnt);
		}
	}
}

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				count_++;
				dfs(i, j, count_);
			}
		}
	}
	for (int i = 0; i < n; i++)	{
		for (int j = 0; j < n; j++) {
			if (map[i][j])
				ans[map[i][j]-2]++;
		}
	}
	count_--;
	sort(ans, ans + count_, cmp);
	printf("%d\n", count_);
	for (int i = 0; i < count_; i++) {
		printf("%d\n", ans[i]);
	}
}

int main() {
	count_ = 1;
	input();
	solve();
	 
	return 0;
}