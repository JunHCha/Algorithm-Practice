/*
https://www.acmicpc.net/problem/2636
����
�Ʒ� <�׸� 1>�� ���� ���簢�� ĭ��� �̷���� �簢�� ����� ���� �ְ�, �� ���� ���� ġ��(ȸ������ ǥ�õ� �κ�)�� ���� �ִ�. ���� �����ڸ�(<�׸� 1>���� �׸� ĭ�� Xģ �κ�)���� ġ� ���� ���� ������ ġ��� �ϳ� �̻��� ������ ���� �� �ִ�.

�� ġ� ���� �߿� ������ ��� �Ǵµ� ����� ���˵� ĭ�� �� �ð��� ������ ��� ��������. ġ���� ���� �ӿ��� ���Ⱑ ������ ������ �ѷ��� ġ� ��Ƽ� ������ ������ ���� ������ ���Ⱑ ���� �ȴ�. <�׸� 1>�� ���, ġ���� ������ �ѷ��� ġ��� ���� �ʰ� ��c���� ǥ�õ� �κи� �� �ð� �Ŀ� ��� �������� <�׸� 2>�� ���� �ȴ�.



�ٽ� �� �ð� �Ŀ��� <�׸� 2>���� ��c���� ǥ�õ� �κ��� ��� �������� <�׸� 3>�� ���� �ȴ�.



<�׸� 3>�� ���� ġ���� �� �ð� �� ����� ��Ÿ���� ������, ���� �������� �� �ð��� �� ������ ��� ��� ��������. �׷��Ƿ� ó�� ġ� ��� ��� �������� ���� �� �ð��� �ɸ���. <�׸� 3>�� ���� ġ� ��� �������� ���� �������� ������ �� ���� �ִ�.

�Է����� �簢�� ����� ���� ũ��� �� ������ ġ� �� ���� �־����� ��, ���� �߿��� ġ� ��� ��� �������� �� �ɸ��� �ð��� ��� ��� �� �ð� ���� �����ִ� ġ�������� ���� �ִ� ĭ�� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ��� �簢�� ��� ���� ���ο� ������ ���̰� ���� ������ �־�����. ���ο� ������ ���̴� �ִ� 100�̴�. ���� �� �������� ����� �� �ٺ��� ���ʷ� ��° �ٺ��� ������ �ٱ��� �־�����. ġ� ���� ĭ�� 0, ġ� �ִ� ĭ�� 1�� �־����� �� ���� ���̿��� ��ĭ�� �ϳ��� �ִ�.

���
ù° �ٿ��� ġ� ��� ��Ƽ� �������� �� �ɸ��� �ð��� ����ϰ�, ��° �ٿ��� ��� ��� �� �ð� ���� �����ִ� ġ�������� ���� �ִ� ĭ�� ������ ����Ѵ�.

*/

 
#include <iostream>

using namespace std;

int n, m, cheese[102][102], hour, res;
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 };

void input() {
	cin >> n;
	cin >> m;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
		cin >> cheese[i][j];
	}
}

bool done() {
	int count = 0;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
		if (cheese[i][j] < 1 || cheese[i][j] > 1)
			cheese[i][j] = 0;
		else {
			cheese[i][j] = 1;
			count++;
		}
	}

	/*
	cout << hour << " " << count << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << cheese[i][j];
		}
		cout << endl;
	}
	*/

	if (count == 0)
		return 1;
	else {
		res = count;
		return 0;
	}
	
}

void solve(int x, int y) {
	if (x < 1 || x > n || y < 1 || y > m) return;
	if (cheese[x][y] == 0) {
		cheese[x][y] = -1;
		for (int i = 0; i < 4; i++)
			solve(x + dx[i], y + dy[i]);
	}
	if (cheese[x][y] >= 1)
		cheese[x][y]++;
}

int main() {
	input();
	for (hour = 0; !done(); hour++) solve(1, 1);
	cout << hour << endl;
	cout << res;
	 
	return 0;
}
