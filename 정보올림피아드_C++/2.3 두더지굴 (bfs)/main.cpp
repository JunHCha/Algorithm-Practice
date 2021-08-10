/*
https://www.acmicpc.net/problem/2667
����
<�׸� 1>�� ���� ���簢�� ����� ������ �ִ�. 1�� ���� �ִ� ����, 0�� ���� ���� ���� ��Ÿ����. ö���� �� ������ ������ ����� ������ ������ ������ �����ϰ�, ������ ��ȣ�� ���̷� �Ѵ�. ���⼭ ����Ǿ��ٴ� ���� � ���� �¿�, Ȥ�� �Ʒ����� �ٸ� ���� �ִ� ��츦 ���Ѵ�. �밢���� ���� �ִ� ���� ����� ���� �ƴϴ�. <�׸� 2>�� <�׸� 1>�� �������� ��ȣ�� ���� ���̴�. ������ �Է��Ͽ� �������� ����ϰ�, �� ������ ���ϴ� ���� ���� ������������ �����Ͽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.



�Է�
ù ��° �ٿ��� ������ ũ�� N(���簢���̹Ƿ� ���ο� ������ ũ��� ������ 5��N��25)�� �Էµǰ�, �� ���� N�ٿ��� ���� N���� �ڷ�(0Ȥ�� 1)�� �Էµȴ�.

���
ù ��° �ٿ��� �� �������� ����Ͻÿ�. �׸��� �� ������ ���� ���� ������������ �����Ͽ� �� �ٿ� �ϳ��� ����Ͻÿ�.

*/

 
#include <iostream>
#include <stdio.h>
#include <queue>
#include <algorithm>

#define MAX_SIZE 25

using namespace std;

struct VERTEX
{
	int x, y;
};


int n, cnt;
int map[MAX_SIZE][MAX_SIZE], ans[MAX_SIZE * MAX_SIZE];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, -1, 0, 1 };

bool safe(int a, int b) {
	return (0 <= a && a < n) && (0 <= b && b < n);
}

bool cmp(int a, int b) {
	return a < b;
}

void input() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)	{
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
}

void bfs(int x, int y, int value) {
	queue<VERTEX> Q;
	Q.push(VERTEX{ x,y });
	map[x][y] = value;
	while(!Q.empty()) {
		VERTEX temp = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++)	{
			if (safe(temp.x + dx[i], temp.y + dy[i]) && map[temp.x + dx[i]][temp.y + dy[i]] == 1) {
				Q.push(VERTEX{ temp.x + dx[i], temp.y + dy[i] });
				map[temp.x + dx[i]][temp.y + dy[i]] = value;
			}
		}
	}
	
}

void solve() {
	for (int i = 0; i < n; i++)	{
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				cnt++;
				bfs(i, j, cnt + 1);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j])	ans[map[i][j] - 2]++;
		}
	}
	sort(ans, ans + cnt, cmp);
}

void print() {
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++) {
		printf("%d\n", ans[i]);
	}
}

int main() {
	input();
	solve();
	print();
	 
	return 0;
}