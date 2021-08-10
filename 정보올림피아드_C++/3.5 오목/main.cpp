/*
https://www.acmicpc.net/problem/2615

����
������ �ٵ��ǿ� ���� �ٵϾ˰� �� �ٵϾ��� ����� ���Ƽ� �ܷ�� �����̴�. �ٵ��ǿ��� 19���� �����ٰ� 19���� �������� �׷��� �ִµ� �������� ���������� �Ʒ��� 1��, 2��, ... ,19���� ��ȣ�� �ٰ� �������� ���ʿ������� ���������� 1��, 2��, ... 19���� ��ȣ�� �ٴ´�.



���� �׸������� ���� ���� ���� �ٵϾ��� ���������� �ټ� ���� ���̸� �� ���� �̱�� �ȴ�. ���⼭ �������̶� ����, ���� �Ǵ� �밢�� ���� ��θ� ���Ѵ�. ��, ���� �׸��� �������� �̱� ����̴�. ������ ���� �� �̻��� ���������� ���� ��쿡�� �̱� ���� �ƴϴ�.

�Է����� �ٵ����� � ���°� �־����� ��, �������� �̰����, ����� �̰���� �Ǵ� ���� �ºΰ� �������� �ʾҴ����� �Ǵ��ϴ� ���α׷��� �ۼ��Ͻÿ�. ��, �������� ����� ���ÿ� �̱�ų� ������ �Ǵ� ����� �� ���� �̻󿡼� ���ÿ� �̱�� ���� �Է����� ������ �ʴ´�.

�Է�
19�ٿ� �� �ٸ��� 19���� ���ڷ� ǥ���Ǵµ�, ���� �ٵϾ��� 1, �� �ٵϾ��� 2, ���� ������ �ʴ� �ڸ��� 0���� ǥ�õǸ�, ���ڴ� �� ĭ�� �� ǥ�õȴ�.

���
ù�ٿ� �������� �̰��� ��쿡�� 1��, ����� �̰��� ��쿡�� 2��, ���� �ºΰ� �������� �ʾ��� ��쿡�� 0�� ����Ѵ�. ������ �Ǵ� ����� �̰��� ��쿡�� ��° �ٿ� ���ӵ� �ټ� ���� �ٵϾ� �߿��� ���� ���ʿ� �ִ� �ٵϾ�(���ӵ� �ټ� ���� �ٵϾ��� ���η� ���� ���, �� �� ���� ���� �ִ� ��)�� ������ ��ȣ��, ������ ��ȣ�� ������� ����Ѵ�.
*/

 
#include <iostream>

using namespace std;

int map[20][20]; // ������ 19 * 19 ������ �̷��� ���ϸ� Ʋ����...

void input() {
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			cin >> map[i][j];
		}
	}
}

bool search1(int color, int row, int col, int cnt) {
	for (; color == map[row - 1][col + 1]; row--, col++)
		cnt++;
	return cnt == 5 ? 1 : 0;
}

bool search2(int color, int row, int col, int cnt) {
	for (; color == map[row][col + 1]; col++)
		cnt++;
	return cnt == 5 ? 1 : 0;
}

bool search3(int color, int row, int col, int cnt) {
	for (; color == map[row + 1][col + 1]; row++, col++)
		cnt++;
	return cnt == 5 ? 1 : 0;
}
bool search4(int color, int row, int col, int cnt) {
	for (; color == map[row + 1][col]; row++)
		cnt++;
	return cnt == 5 ? 1 : 0;
}

void solve() {
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (map[i][j]) {
				if (map[i + 1][j - 1] != map[i][j] && search1(map[i][j], i, j, 1)) {
					cout << map[i][j] << endl;
					cout << i + 1 << " " << j + 1;
					return;
				}
				if (map[i][j - 1] != map[i][j] && search2(map[i][j], i, j, 1)) {
					cout << map[i][j] << endl;
					cout << i + 1 << " " << j + 1;
					return;
				}
				if (map[i - 1][j - 1] != map[i][j] && search3(map[i][j], i, j, 1)) {
					cout << map[i][j] << endl;
					cout << i + 1 << " " << j + 1;
					return;

				}
				if (map[i - 1][j] != map[i][j] && search4(map[i][j], i, j, 1)) {
					cout << map[i][j] << endl;
					cout << i + 1 << " " << j + 1;
					return;
				}
			}
		}
	}
	cout << 0;
	return;
}

int main() {
	input();
	solve();
	 
	return 0;
}
