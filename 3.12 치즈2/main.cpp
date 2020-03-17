/*
https://www.acmicpc.net/problem/2636
문제
아래 <그림 1>과 같이 정사각형 칸들로 이루어진 사각형 모양의 판이 있고, 그 위에 얇은 치즈(회색으로 표시된 부분)가 놓여 있다. 판의 가장자리(<그림 1>에서 네모 칸에 X친 부분)에는 치즈가 놓여 있지 않으며 치즈에는 하나 이상의 구멍이 있을 수 있다.

이 치즈를 공기 중에 놓으면 녹게 되는데 공기와 접촉된 칸은 한 시간이 지나면 녹아 없어진다. 치즈의 구멍 속에는 공기가 없지만 구멍을 둘러싼 치즈가 녹아서 구멍이 열리면 구멍 속으로 공기가 들어가게 된다. <그림 1>의 경우, 치즈의 구멍을 둘러싼 치즈는 녹지 않고 ‘c’로 표시된 부분만 한 시간 후에 녹아 없어져서 <그림 2>와 같이 된다.



다시 한 시간 후에는 <그림 2>에서 ‘c’로 표시된 부분이 녹아 없어져서 <그림 3>과 같이 된다.



<그림 3>은 원래 치즈의 두 시간 후 모양을 나타내고 있으며, 남은 조각들은 한 시간이 더 지나면 모두 녹아 없어진다. 그러므로 처음 치즈가 모두 녹아 없어지는 데는 세 시간이 걸린다. <그림 3>과 같이 치즈가 녹는 과정에서 여러 조각으로 나누어 질 수도 있다.

입력으로 사각형 모양의 판의 크기와 한 조각의 치즈가 판 위에 주어졌을 때, 공기 중에서 치즈가 모두 녹아 없어지는 데 걸리는 시간과 모두 녹기 한 시간 전에 남아있는 치즈조각이 놓여 있는 칸의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에는 사각형 모양 판의 세로와 가로의 길이가 양의 정수로 주어진다. 세로와 가로의 길이는 최대 100이다. 판의 각 가로줄의 모양이 윗 줄부터 차례로 둘째 줄부터 마지막 줄까지 주어진다. 치즈가 없는 칸은 0, 치즈가 있는 칸은 1로 주어지며 각 숫자 사이에는 빈칸이 하나씩 있다.

출력
첫째 줄에는 치즈가 모두 녹아서 없어지는 데 걸리는 시간을 출력하고, 둘째 줄에는 모두 녹기 한 시간 전에 남아있는 치즈조각이 놓여 있는 칸의 개수를 출력한다.

*/

#define _CRT_SECURE_NO_WARNINGS
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
	system("pause");
	return 0;
}
