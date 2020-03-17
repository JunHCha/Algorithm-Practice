/*
https://www.acmicpc.net/problem/7573
문제
한국인의 식단에서 생선은 매우 중요한 단백질 공급원이다. 반면, 지구 온난화로 인한 바닷물의 온도 상승, 그리고 지금까지 마구잡이로 물고기를 잡은 결과로 점점 우리나라의 바다에서 물고기의 수가 줄어들고 있다. 정부에서는 이 문제를 심각하게 생각하여, 물고기를 잡을 수 있는 곳과 여기서 고기잡이 배가 사용할 수 있는 그물의 폭에 제한을 두었다. 물고기는 바다 표면 근처에 살기 때문에, 그물의 높이는 중요하지 않다. 따라서 그물은 길이가 l인 직선으로 생각할 수 있고, 물고기를 잡을 때, 그물은 한 변의 길이가 1 이상 정수인 직사각형 모양으로 치게 된다. 예를 들어, l = 10이라면, 칠 수 있는 그물의 모양은 1×4, 2×3, 3×2, 4×1과 같이 4가지 형태의 직사각형이 된다.

고기를 잡을 수 있는 곳은 N×N 크기의 모눈종이 모양으로 되어 있다. 각 모눈에는 좌표가 주어지며, 가장 왼쪽 위 모눈이 (1,1)이고, 가장 오른쪽 아래 모눈이 (N,N)이다. 총 M 마리의 물고기가 서로 다른 모눈 위에 한 마리씩 살고 있으며, 물고기는 움직이지 않는다. 고기잡이 배는 한 모눈 위에 위치를 잡고 자신의 오른쪽과 아래쪽으로 그물을 친다. 일단 그물을 치면, 그물 안, 그리고 그물에 걸친 물고기들을 잡을 수 있다. 예를 들면, 다음 그림은 N = 7, l = 10 이고 M = 6 마리의 물고기가 (2,2), (2,4), (3,3), (5,6), (6,2), (7,4)에 살고 있을 때, (2,2)에 놓인 고기잡이 배가 2×3 모양으로 그물을 친 예를 보이고 있다. 이때 고기잡이 배는 총 3마리의 물고기를 잡을 수 있다. 고기를 잡을 수 있는 영역 밖으로 그물을 치는 경우는 없다.



고기를 잡을 수 있는 영역, 물고기의 위치, 그물의 폭이 주어졌을 때 한 번의 그물치기로 잡을 수 있는 가장 많은 물고기의 마릿수를 구하는 프로그램을 작성하시오.

입력
첫 번째 줄에는 모눈종이의 크기, 그물의 길이, 물고기의 수를 나타내는 세 개의 정수 N, l, M이 하나의 공백을 두고 주어진다. 단, 2 ≤ N ≤ 10,000, 4 ≤ l ≤ 100, 1 ≤ M ≤100 이다. l은 l ≤ 4N - 4을 만족하는 짝수이다. 두 번째 줄부터 이후 M 개의 줄에는 각 물고기의 좌표가 하나의 공백을 두고 주어진다. 물고기의 좌표 순서는 무작위로 주어진다.

출력
첫 줄에 주어진 입력에서 잡을 수 있는 가장 많은 물고기의 마릿수를 하나의 정수로 출력한다.
*/

// DP랑 배낭문제 풀고 다시 와서 보기

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, w, m;
int dx[4] = { -1, 1, 1, -1 };
int dy[4] = { 1, 1, -1, -1 };

struct Coord {
	int x, y;
};
vector<int> sol;
vector<Coord> fish;

bool safe(int a, int b) {
	return(1 <= a && a <= n) && (1 <= b && b <= n);
}

bool isBoundary(Coord start, Coord end, Coord target) {
	if (start.x <= end.x) {
		if (start.y <= end.y)
			return (start.x <= target.x && target.x <= end.x) && (start.y <= target.y && target.y <= end.y);
		else
			return (start.x <= target.x && target.x <= end.x) && (end.y <= target.y && target.y <= start.y);
	} 
	else {
		if (start.y <= end.y)
			return (end.x <= target.x && target.x <= start.x) && (start.y <= target.y && target.y <= end.y);
		else
			return (end.x <= target.x && target.x <= start.x) && (end.y <= target.y && target.y <= start.y);
	}
}

bool cmp(int a, int b) {
	return a > b;
}

void search(int x, int y) {
	int cnt = 0;
	for (int a = 1; a < w / 2; a++) {
		int b = w / 2 - a;
		for (int i = 0; i < 4; i++) {
			int x_coord = x + dx[i] * a, y_coord = y + dy[i] * b;
			Coord webEnd{ x_coord, y_coord };
			if (safe(webEnd.x, webEnd.y)) {

				//cout << "in Fish "<< x << " " << y <<", webEnd : " << webEnd.x << " " << webEnd.y << " is Safe" << endl;

				for (int j = 0; j < fish.size(); j++) {
					if (isBoundary(Coord{ x, y }, webEnd, fish.at(j))) {

						//cout << "fish " << fish.at(j).x << " " << fish.at(j).y << " is in boundary" << endl << endl;

						cnt++;
					}
				}
				sol.push_back(cnt);
				cnt = 0;
			}
		}
	}
}

void solve() {
	for (int idx = 0; idx < fish.size(); idx++) {
		search(fish.at(idx).x, fish.at(idx).y);
	} 
}

void input() {
	cin >> n;
	cin >> w;
	cin >> m;
	for (int i = 0; i < m; i++)	{
		int x, y;
		cin >> x;
		cin >> y;
		fish.push_back(Coord{ x, y });
	}
}

int main() {
	input();
	solve();
	sort(sol.begin(), sol.end(), cmp);
	cout << sol.at(0) << endl;
	system("pause");
	return 0;
}