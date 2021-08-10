/*
https://www.acmicpc.net/problem/2178
N��Mũ���� �迭�� ǥ���Ǵ� �̷ΰ� �ִ�.

1	0	1	1	1	1
1	0	1	0	1	0
1	0	1	0	1	1
1	1	1	0	1	1
�̷ο��� 1�� �̵��� �� �ִ� ĭ�� ��Ÿ����, 0�� �̵��� �� ���� ĭ�� ��Ÿ����. �̷��� �̷ΰ� �־����� ��, (1, 1)���� ����Ͽ� (N, M)�� ��ġ�� �̵��� �� ������ �ϴ� �ּ��� ĭ ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. �� ĭ���� �ٸ� ĭ���� �̵��� ��, ���� ������ ĭ���θ� �̵��� �� �ִ�.

���� �������� 15ĭ�� ������ (N, M)�� ��ġ�� �̵��� �� �ִ�. ĭ�� �� ������ ���� ��ġ�� ���� ��ġ�� �����Ѵ�.

�Է�
ù° �ٿ� �� ���� N, M(2 �� N, M �� 100)�� �־�����. ���� N���� �ٿ��� M���� ������ �̷ΰ� �־�����. ������ ������ �پ �Է����� �־�����.

���
ù° �ٿ� ������ �ϴ� �ּ��� ĭ ���� ����Ѵ�. �׻� ������ġ�� �̵��� �� �ִ� ��츸 �Է����� �־�����.
*/

 
#include <stdio.h>
#include <queue>
#define MAX_SIZE 100

using namespace std;

int n, m, map[MAX_SIZE][MAX_SIZE], visited[MAX_SIZE][MAX_SIZE], d;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
struct VERTEX {
	int x, y;
};

bool safe(int x, int y) {
	return (0 <= x && x < n) && (0 <= y && y < m);
}

void input() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)	{
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	
}



void bfs(int x, int y) {
	queue<VERTEX> q;
	q.push(VERTEX{ x, y });
	visited[x][y] = 1;
	while (!q.empty()) {
		VERTEX temp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)	{
			int x = temp.x + dx[i]; int y = temp.y + dy[i];
			if (map[x][y] == 1 && visited[x][y] == 0 && safe(x, y)) {
				visited[x][y] = visited[temp.x][temp.y] + 1;
				q.push(VERTEX{ x,y });
			}
		}
	}
}

int solve() {
	bfs(0, 0);
	return visited[n - 1][m - 1];
}

int main() {
	input();
	printf("%d\n", solve());

	 
	return 0;
}

