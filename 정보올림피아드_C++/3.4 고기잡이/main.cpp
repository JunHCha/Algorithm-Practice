/*
https://www.acmicpc.net/problem/7573
����
�ѱ����� �Ĵܿ��� ������ �ſ� �߿��� �ܹ��� ���޿��̴�. �ݸ�, ���� �³�ȭ�� ���� �ٴ幰�� �µ� ���, �׸��� ���ݱ��� �������̷� �����⸦ ���� ����� ���� �츮������ �ٴٿ��� �������� ���� �پ��� �ִ�. ���ο����� �� ������ �ɰ��ϰ� �����Ͽ�, �����⸦ ���� �� �ִ� ���� ���⼭ �������� �谡 ����� �� �ִ� �׹��� ���� ������ �ξ���. ������� �ٴ� ǥ�� ��ó�� ��� ������, �׹��� ���̴� �߿����� �ʴ�. ���� �׹��� ���̰� l�� �������� ������ �� �ְ�, �����⸦ ���� ��, �׹��� �� ���� ���̰� 1 �̻� ������ ���簢�� ������� ġ�� �ȴ�. ���� ���, l = 10�̶��, ĥ �� �ִ� �׹��� ����� 1��4, 2��3, 3��2, 4��1�� ���� 4���� ������ ���簢���� �ȴ�.

���⸦ ���� �� �ִ� ���� N��N ũ���� ������ ������� �Ǿ� �ִ�. �� �𴫿��� ��ǥ�� �־�����, ���� ���� �� ���� (1,1)�̰�, ���� ������ �Ʒ� ���� (N,N)�̴�. �� M ������ �����Ⱑ ���� �ٸ� �� ���� �� ������ ��� ������, ������� �������� �ʴ´�. �������� ��� �� �� ���� ��ġ�� ��� �ڽ��� �����ʰ� �Ʒ������� �׹��� ģ��. �ϴ� �׹��� ġ��, �׹� ��, �׸��� �׹��� ��ģ ��������� ���� �� �ִ�. ���� ���, ���� �׸��� N = 7, l = 10 �̰� M = 6 ������ �����Ⱑ (2,2), (2,4), (3,3), (5,6), (6,2), (7,4)�� ��� ���� ��, (2,2)�� ���� �������� �谡 2��3 ������� �׹��� ģ ���� ���̰� �ִ�. �̶� �������� ��� �� 3������ �����⸦ ���� �� �ִ�. ���⸦ ���� �� �ִ� ���� ������ �׹��� ġ�� ���� ����.



���⸦ ���� �� �ִ� ����, �������� ��ġ, �׹��� ���� �־����� �� �� ���� �׹�ġ��� ���� �� �ִ� ���� ���� �������� �������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù ��° �ٿ��� �������� ũ��, �׹��� ����, �������� ���� ��Ÿ���� �� ���� ���� N, l, M�� �ϳ��� ������ �ΰ� �־�����. ��, 2 �� N �� 10,000, 4 �� l �� 100, 1 �� M ��100 �̴�. l�� l �� 4N - 4�� �����ϴ� ¦���̴�. �� ��° �ٺ��� ���� M ���� �ٿ��� �� �������� ��ǥ�� �ϳ��� ������ �ΰ� �־�����. �������� ��ǥ ������ �������� �־�����.

���
ù �ٿ� �־��� �Է¿��� ���� �� �ִ� ���� ���� �������� �������� �ϳ��� ������ ����Ѵ�.
*/

// DP�� �賶���� Ǯ�� �ٽ� �ͼ� ����

 
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
	 
	return 0;
}