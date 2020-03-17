/*
https://www.acmicpc.net/problem/2294

문제
n가지 종류의 동전이 있다. 이 동전들을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다. 그러면서 동전의 개수가 최소가 되도록 하려고 한다. 각각의 동전은 몇 개라도 사용할 수 있다.

사용한 동전의 구성이 같은데, 순서만 다른 것은 같은 경우이다.

입력
첫째 줄에 n, k가 주어진다. (1 ≤ n ≤ 100, 1 ≤ k ≤ 10,000) 다음 n개의 줄에는 각각의 동전의 가치가 주어진다. 동전의 가치는 100,000보다 작거나 같은 자연수이다. 가치가 같은 동전이 여러 번 주어질 수도 있다.

출력
첫째 줄에 사용한 동전의 최소 개수를 출력한다. 불가능한 경우에는 -1을 출력한다.
*/


#define _CRT_SECURE_NO_WARNINGS
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
	system("pause");
	return 0;
}
