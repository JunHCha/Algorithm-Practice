/*
https://www.acmicpc.net/problem/2667
문제
<그림 1>과 같이 정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 철수는 이 지도를 가지고 연결된 집들의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 대각선상에 집이 있는 경우는 연결된 것이 아니다. <그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다. 지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.



입력
첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고, 그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.

출력
첫 번째 줄에는 총 단지수를 출력하시오. 그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.

*/

#define _CRT_SECURE_NO_WARNINGS
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
	system("pause");
	return 0;
}