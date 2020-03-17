/*
1도, 5도, 10도 단위로 온도조절 버튼이 있는 리모컨이 있다.
목표 온도가 주어질때, 버튼 누름의 최소 횟수를 구하시오.

입력
온도 a, b 가 입력된다 ( 0 <= a, b <= 40)

출력
목표온도가 되는 버튼누름의 최소횟수를 출력
*/
#define _CRT_SECRUE_NO_WARNINGS

#include <iostream>
#include <queue>

using namespace std;

int a, b, res = 41;

struct ELE { int cur, count; };

void bfs(int temp, int cnt) { // bfs는 어차피 queue만 갖고 다니면 되니까 굳이 함수처리도 필요없고, 함수 매개변수로 깊이값을 갖고 있을 필요도 없다. queue 에만 저장해놓고 관리하면 됨
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
	system("pause");
	return 0;
}


/* DFS 풀이

#define _CRT_SECRUE_NO_WARNINGS

#include <iostream>

using namespace std;

int a, b, res = 41;

void dfs(int temp, int cnt) {
	if (cnt > res) {
		return;
	}
	// 이 부분이 중요한데, cnt 상한을 두지 않으면 +10, -10 만 반복하다가 다음 가지를 탐색하지를 못한다.

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
	system("pause");
	return 0;
}
*/