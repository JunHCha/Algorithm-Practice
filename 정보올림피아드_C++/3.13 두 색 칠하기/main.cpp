/*
https://www.acmicpc.net/problem/13265
����
� ���Ŵ�� ��ĥ���θ� �����Ѵ�.

���Ŵ�� ���� ���� ���׶�̿� ���׶�� �� ���� �����ϴ� ������ ������ �׸��� �׸��� (��� ���׶�̵� ���̿� ������ ���� �ʿ�� ����), ����� �� ���׶�̴� ���� ���� �ٸ��� �ǵ��� ���� ĥ�ϰ��� �Ѵ�.

�� �׸��� ��ĥ�ϴµ� �ʿ��� �ּ��� ���� ������ ���ϴ� ������ ��Ʊ� ������ ���Ŵ�� 2 ���� �������� ��ĥ�� ���������� ���θ��� �˰� �;��Ѵ�.

���׶�̵��� ��ȣ�� ���׶�̵��� ���� ����� ������ ���� ������ �־����� ��, �� ���׶�̵��� 2 ���� �������� ��ĥ�� �������� �˾Ƴ���.

�Է�
�Է��� ù �ٿ��� �׽�Ʈ ���̽��� ���� T �� �־�����.

�� ���� �ٺ��� �� �׽�Ʈ ���̽��� ���� ���׶���� ���� n(n<=1000)�� �������� ���� m(m<=100,000)�� �־�����, �� ���� �ٺ��� m �ٿ� ���� ���׶�̵��� ����� ������ ���� ������ �־�����. (x y) �� �־����� ���׶�� x �� ���׶�� y �� �������� ���� ����Ǿ��ٴ� �ǹ��̴�. ���׶�̵��� ���ڴ� 1 ���� n �����̴�.

���
�� �׽�Ʈ ���̽��� ���ؼ� possible �̳� impossible �� ����Ѵ�. 2 ���� �������� ��ĥ�� �����ϸ� possible. �Ұ����ϸ� impossible �̴�.
*/

 
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
	 
	return 0;
}
