/*
https://www.acmicpc.net/problem/2294

����
n���� ������ ������ �ִ�. �� �������� ������ ����ؼ�, �� ��ġ�� ���� k���� �ǵ��� �ϰ� �ʹ�. �׷��鼭 ������ ������ �ּҰ� �ǵ��� �Ϸ��� �Ѵ�. ������ ������ �� ���� ����� �� �ִ�.

����� ������ ������ ������, ������ �ٸ� ���� ���� ����̴�.

�Է�
ù° �ٿ� n, k�� �־�����. (1 �� n �� 100, 1 �� k �� 10,000) ���� n���� �ٿ��� ������ ������ ��ġ�� �־�����. ������ ��ġ�� 100,000���� �۰ų� ���� �ڿ����̴�. ��ġ�� ���� ������ ���� �� �־��� ���� �ִ�.

���
ù° �ٿ� ����� ������ �ּ� ������ ����Ѵ�. �Ұ����� ��쿡�� -1�� ����Ѵ�.
*/


 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, cnt;
vector<int> coin, res;

int cmp(int a, int b) {
	return a > b;
}

void input() {
	cin >> n;
	cin >> k;
	for (size_t i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		coin.push_back(temp);
	}
	sort(coin.begin(), coin.end(), cmp);
}

void f(int coinIndex, int cost) {
	
	if (cost > k) {
		cost = cost - coin[coinIndex];
		return;
	}

	if (cost == k) {
		res.push_back(cnt);
		return;
	}

	for (int i = 0; i <= n; i++)	{
		if (coinIndex + i < n) {
			cnt++;
			f(coinIndex + i, cost + coin[coinIndex + i]);
			cnt--;
		}
	}
}

int main() {
	input();
	f(0, 0);
	sort(res.begin(), res.end());
	cout << res[0] << endl;
	 
	return 0;
}
