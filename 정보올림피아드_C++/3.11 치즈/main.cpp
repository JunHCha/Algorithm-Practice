/*
https://www.acmicpc.net/problem/2638
����
N��M (5��N, M��100)�� ������ ���� ���� ���� ġ� <�׸� 1>�� ���� ǥ�õǾ� �ִ�. ��, N �� ���� ������ ���̰�, M �� ���� ������ ���̴�. �� ġ��� �õ� ������ �ؾ߸� �ϴµ� �ǳ��µ��� ��������� ����� �����Ͽ� õõ�� ��´�. �׷��� �̷��� ������ ����� ġ��� �� ġ�� ����(�� �� ���簢�� ���)�� 4�� �߿��� ��� 2�� �̻��� �ǳ��µ��� ����� ������ ���� ��Ȯ�� �ѽð����� ��� ������ ������. ���� �Ʒ� <�׸� 1> ���� ���� ġ��(ȸ������ ǥ�õ� �κ�)��� C�� ǥ�õ� ��� ġ�� ���ڴ� �� �ð� �Ŀ� �������.



<�׸� 2>�� ���� ġ�� ���ο� �ִ� ������ ġ�� �ܺ� ����� �������� �ʴ� ������ �����Ѵ�. �׷��� �� �� ������ ������ ġ�� ���ڴ� ���� �ʰ� C�� ǥ�õ� ġ�� ���ڸ� �������. �׷��� �� �ð� ��, �� �������� �ܺΰ��Ⱑ ���ԵǸ� <�׸� 3>������ ���� C�� ǥ�õ� ġ�� ���ڵ��� ������� �ȴ�.



�������� �� �����ڸ����� ġ� ������ �ʴ� ������ �����Ѵ�. �Է����� �־��� ġ� ��� ��� �������µ� �ɸ��� ��Ȯ�� �ð��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ��� �������� ũ�⸦ ��Ÿ���� �� ���� ���� N, M (5��N, M��100)�� �־�����. �� ���� N���� �ٿ��� ������ ���� ���ڿ� ġ� �ִ� �κ��� 1�� ǥ�õǰ�, ġ� ���� �κ��� 0���� ǥ�õȴ�. ����, �� 0�� 1�� �ϳ��� �������� �и��Ǿ� �ִ�.

���
������δ� �־��� ġ� ��� ��� �������µ� �ɸ��� ��Ȯ�� �ð��� ������ ù �ٿ� ����Ѵ�.
*/
 
#include <iostream>

using namespace std;

int n, m, hour, total;
int cheese[101][101];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void input() {
	cin >> n;
	cin >> m;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		cin >> cheese[i][j];
}

bool done() {
	int count = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		if (cheese[i][j] > 2 || cheese[i][j] < 1)
			cheese[i][j] = 0;
		else {
			cheese[i][j] = 1;
			count++; 
		}
	}
	
	/*
	cout << "hour : " << hour << ", done : "<< (count == 0) << endl;
	for (int i = 0; i < n; i++)	{
		for (int j = 0; j < m; j++) {
			cout << cheese[i][j] << " ";
		}
		cout << endl;
	}
	*/
	return count == 0;
}

void solve(int x, int y) {
	
	if (x < 0 || x >= n || y < 0 || y >= m) return;
	if (cheese[x][y] == 0) {
		cheese[x][y] = -1;
		for (int i = 0; i < 4; i++) solve(x + dx[i], y + dy[i]);
	}
	else if (cheese[x][y] > 0) {
		cheese[x][y]++;
	}	
}

int main() {
	input();
	for (hour = 0; !done(); hour++) solve(0, 0);
	cout << hour;
	 
	return 0;
}


/*
 
#include <iostream>

int n, m, hour, total;
int cheese[101][101], temp[101][101];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

using namespace std;

void input() {
	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> cheese[i][j];
			temp[i][j] = cheese[i][j];
			if (temp[i][j] == 1) total++;
		}
	}
}

void copy() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cheese[i][j] = temp[i][j];
		}
	}
}

void fillTemp(int x, int y) {
	if (x < 1 || x > n || y < 1 || y > m) return;
	if (temp[x][y] == 0) {
		temp[x][y] = 2;
		for (int i = 0; i < 4; i++)
			fillTemp(x + dx[i], y + dy[i]);
	}
}
	

bool check(int x, int y) {
	int s = 0;
	for (int i = 0; i < 4; i++)
		if (cheese[x + dx[i]][y + dy[i]] == 2)
			if (x + dx[i] >= 1 && x + dx[i] <= n && y + dy[i] >= 1 && y + dy[i] <= m)
				s++;
	return s >= 2;
}

void solve() {
	fillTemp(1, 1);
	copy();
	while (total) {
		for (int i = 1; i <= n; i++) 
			for (int j = 1; j <= m; j++) 
				if (cheese[i][j] == 1 && check(i, j)) {
					temp[i][j] = 2;
					total--;
				}
		copy();
		hour++;
	}
}

int main() {
	input();
	solve();
	cout << hour;
	 
	return 0;
}
*/


