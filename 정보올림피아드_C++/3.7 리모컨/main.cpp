/*
1��, 5��, 10�� ������ �µ����� ��ư�� �ִ� �������� �ִ�.
��ǥ �µ��� �־�����, ��ư ������ �ּ� Ƚ���� ���Ͻÿ�.

�Է�
�µ� a, b �� �Էµȴ� ( 0 <= a, b <= 40)

���
��ǥ�µ��� �Ǵ� ��ư������ �ּ�Ƚ���� ���
*/
#define _CRT_SECRUE_NO_WARNINGS

#include <iostream>
#include <queue>

using namespace std;

int a, b, res = 41;

struct ELE { int cur, count; };

void bfs(int temp, int cnt) { // bfs�� ������ queue�� ���� �ٴϸ� �Ǵϱ� ���� �Լ�ó���� �ʿ����, �Լ� �Ű������� ���̰��� ���� ���� �ʿ䵵 ����. queue ���� �����س��� �����ϸ� ��
	queue<ELE> Q;
	Q.push(ELE{ temp, cnt });
	while (!Q.empty()) {
		ELE temp = Q.front();
		Q.pop();
		if (temp.cur == b) {
			if (res > temp.count) res = temp.count;
			break;
		}
		else if (temp.cur > b) {
			Q.push({ temp.cur - 10, temp.count + 1 });
			Q.push({ temp.cur - 5, temp.count + 1 });
			Q.push({ temp.cur - 1, temp.count + 1 });
		}
		else {
			Q.push({ temp.cur + 10, temp.count + 1 });
			Q.push({ temp.cur + 5, temp.count + 1 });
			Q.push({ temp.cur + 1, temp.count + 1 });
		}
	}
}


int main() {
	cin >> a; cin >> b;
	bfs(a, 0);
	cout << res;
	 
	return 0;
}


/* DFS Ǯ��

#define _CRT_SECRUE_NO_WARNINGS

#include <iostream>

using namespace std;

int a, b, res = 41;

void dfs(int temp, int cnt) {
	if (cnt > res) {
		return;
	}
	// �� �κ��� �߿��ѵ�, cnt ������ ���� ������ +10, -10 �� �ݺ��ϴٰ� ���� ������ Ž�������� ���Ѵ�.

	if (temp == b) {
		if (res > cnt) {
			res = cnt;
		}
		return;
	}
	else if (temp > b) {
		dfs(temp - 10, cnt + 1);
		dfs(temp - 5, cnt + 1);
		dfs(temp - 1, cnt + 1);
	}
	else {
		dfs(temp + 10, cnt + 1);
		dfs(temp + 5, cnt + 1);
		dfs(temp + 1, cnt + 1);
	}

}

int main() {
	cin >> a; cin >> b;
	dfs(a, 0);
	cout << res;
	 
	return 0;
}
*/