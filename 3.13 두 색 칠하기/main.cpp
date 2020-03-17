/*
https://www.acmicpc.net/problem/13265
문제
어린 토니킴은 색칠공부를 좋아한다.

토니킴은 먼저 여러 동그라미와 동그라미 두 개를 연결하는 직선들 만으로 그림을 그리고 (모든 동그라미들 사이에 직선이 있을 필요는 없다), 연결된 두 동그라미는 서로 색이 다르게 되도록 색을 칠하고자 한다.

이 그림을 색칠하는데 필요한 최소의 색의 개수를 구하는 문제는 어렵기 때문에 토니킴은 2 가지 색상으로 색칠이 가능한지의 여부만을 알고 싶어한다.

동그라미들의 번호와 동그라미들이 서로 연결된 직선에 대한 정보가 주어졌을 때, 이 동그라미들이 2 가지 색상으로 색칠이 가능한지 알아내자.

입력
입력의 첫 줄에는 테스트 케이스의 개수 T 가 주어진다.

그 다음 줄부터 각 테스트 케이스에 대해 동그라미의 개수 n(n<=1000)과 직선들의 개수 m(m<=100,000)이 주어지고, 그 다음 줄부터 m 줄에 걸쳐 동그라미들이 연결된 직선에 대한 정보가 주어진다. (x y) 로 주어지면 동그라미 x 와 동그라미 y 가 직선으로 서로 연결되었다는 의미이다. 동그라미들의 숫자는 1 부터 n 까지이다.

출력
각 테스트 케이스에 대해서 possible 이나 impossible 을 출력한다. 2 가지 색상으로 색칠이 가능하면 possible. 불가능하면 impossible 이다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int t, n, m;
vector<int> G[1001];
int visited[1001];

void dfs(int node, int color) {
	int can = 1;
	visited[node] = color;
	for (int i = 0; i < G[node].size(); i++) {
		if (visited[G[node][i]] == color) {
			can = 0;
		}
	}

	if (!can) {
		visited[node] = -1;
		return;
	}
		
	for (int i = 0; i < G[node].size(); i++)	{
		if (visited[G[node][i]] == 0) {
			if (color == 1)
				dfs(G[node][i], 2);
			else
				dfs(G[node][i], 1);
		}
	}
	
}

bool possible(int size) {
	for (int i = 0; i < size; i++)	{
		if (visited[i + 1] == -1) return 0;
	}
	return 1;
}

void bufferReset(int size) {
	for (int i = 0; i < size; i++)	{
		G[i + 1].clear();
		visited[i + 1] = 0;
	}
}

void solve() {
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> m;
		for (int i = 0; i < m; i++)	{
			int s, e;
			cin >> s; cin >> e;
			G[s].push_back(e);
			G[e].push_back(s);
		}
		for (int i = 0; i < n; i++)	{
			if (visited[i + 1] == 0)
				dfs(i + 1, 1);
		}

		if (possible(n)) {
			cout << "possible" << endl;
		}
		else {
			cout << "impossible" << endl;
		}

		bufferReset(n);
	}
}

int main() {
	solve();
	system("pause");
	return 0;
}
