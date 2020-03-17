/*
수빈이가 세상에서 가장 좋아하는 것은 소수이고, 취미는 소수를 가지고 노는 것이다. 요즘 수빈이가 가장 관심있어 하는 소수 7331이다.

7331은 소수인데, 신기하게도 733도 소수이고, 73도 소수이고, 7도 소수이다. 즉, 왼쪽부터 1자리, 2자리, 3자리, 4자리 수 모두 소수이다! 수빈이는 이런 숫자를 신기한 소수라고 이름 붙였다.

수빈이는 N자리의 숫자 중에서 어떤 수들이 신기한 소수인지 궁금해졌다. N이 주어졌을 때, 수빈이를 위해 N자리 신기한 소수를 모두 찾아보자.

입력
첫째 줄에 N(1 ≤ N ≤ 8)이 주어진다.

출력
N자리 수 중에서 신기한 소수를 오름차순으로 정렬해서 한 줄에 하나씩 출력한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> v;

int isPrime(int x) {
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)	return 0;
	return 1;
}

void dfs(int num, int length) {
	if (length == N && isPrime(num)) {
		v.push_back(num);
		return;
	}
	if (!isPrime(num)) return;
	dfs(num * 10 + 1, length + 1);
	dfs(num * 10 + 3, length + 1);
	dfs(num * 10 + 7, length + 1);
	dfs(num * 10 + 9, length + 1);
}

int main() {
	cin >> N;
	dfs(2, 1);
	dfs(3, 1);
	dfs(5, 1);
	dfs(7, 1);
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i) << endl;
	}
	system("pause");
	return 0;
}