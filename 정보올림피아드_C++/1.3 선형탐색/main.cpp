/*
https://www.acmicpc.net/problem/1920
����
N���� ���� A[1], A[2], ��, A[N]�� �־��� ���� ��, �� �ȿ� X��� ������ �����ϴ��� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �ڿ��� N(1��N��100,000)�� �־�����. ���� �ٿ��� N���� ���� A[1], A[2], ��, A[N]�� �־�����. ���� �ٿ��� M(1��M��100,000)�� �־�����. ���� �ٿ��� M���� ������ �־����µ�, �� ������ A�ȿ� �����ϴ��� �˾Ƴ��� �ȴ�. ��� �������� ������ int �� �Ѵ�.

���
M���� �ٿ� ���� ����Ѵ�. �����ϸ� 1��, �������� ������ 0�� ����Ѵ�.
*/

 
#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int n, m, n_container[100001];

int solve(int start, int end, int target) {
	if (start > end) return 0;
	int medium = (start + end) / 2;
	if (n_container[medium] == target) return 1;
	else if (n_container[medium] > target) return solve(start, medium - 1, target);
	else return solve(medium + 1, end, target);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", n_container + i);
	}
	sort(n_container, n_container + n);
	scanf("%d", &m);
	int temp;
	for (int i = 0; i < m; i++) {
		scanf("%d", &temp);
		printf("%d\n", solve(0, n - 1, temp));
	}
	 
	return 0;
}







/*�ݺ��� Ǯ��
 
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, n_container[100001], m_container[100001];

int solve(int start, int end, int index) {
	while (start <= end) {
		int medium = (start + end) / 2;
		if (n_container[medium] == m_container[index])
			return 1;
		if (n_container[medium] < m_container[index])
			start = medium + 1;
		else
			end = medium - 1;
	}
	return 0;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> n_container[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> m_container[i];
	}
	sort(n_container, n_container + n);

	for (int i = 0; i < m; i++) {
		cout << solve(0, n - 1, i) << endl;
	}

	 
	return 0;
}
*/