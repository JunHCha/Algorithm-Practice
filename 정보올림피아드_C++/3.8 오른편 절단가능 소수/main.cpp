/*
�����̰� ���󿡼� ���� �����ϴ� ���� �Ҽ��̰�, ��̴� �Ҽ��� ������ ��� ���̴�. ���� �����̰� ���� �����־� �ϴ� �Ҽ� 7331�̴�.

7331�� �Ҽ��ε�, �ű��ϰԵ� 733�� �Ҽ��̰�, 73�� �Ҽ��̰�, 7�� �Ҽ��̴�. ��, ���ʺ��� 1�ڸ�, 2�ڸ�, 3�ڸ�, 4�ڸ� �� ��� �Ҽ��̴�! �����̴� �̷� ���ڸ� �ű��� �Ҽ���� �̸� �ٿ���.

�����̴� N�ڸ��� ���� �߿��� � ������ �ű��� �Ҽ����� �ñ�������. N�� �־����� ��, �����̸� ���� N�ڸ� �ű��� �Ҽ��� ��� ã�ƺ���.

�Է�
ù° �ٿ� N(1 �� N �� 8)�� �־�����.

���
N�ڸ� �� �߿��� �ű��� �Ҽ��� ������������ �����ؼ� �� �ٿ� �ϳ��� ����Ѵ�.
*/

 
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
	 
	return 0;
}