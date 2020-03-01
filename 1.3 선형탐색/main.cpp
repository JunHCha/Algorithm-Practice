/*
https://www.acmicpc.net/problem/1920
문제
N개의 정수 A[1], A[2], …, A[N]이 주어져 있을 때, 이 안에 X라는 정수가 존재하는지 알아내는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 N(1≤N≤100,000)이 주어진다. 다음 줄에는 N개의 정수 A[1], A[2], …, A[N]이 주어진다. 다음 줄에는 M(1≤M≤100,000)이 주어진다. 다음 줄에는 M개의 수들이 주어지는데, 이 수들이 A안에 존재하는지 알아내면 된다. 모든 정수들의 범위는 int 로 한다.

출력
M개의 줄에 답을 출력한다. 존재하면 1을, 존재하지 않으면 0을 출력한다.
*/

#define _CRT_SECURE_NO_WARNINGS
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
	system("pause");
	return 0;
}







/*반복문 풀이
#define _CRT_SECURE_NO_WARNINGS
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

	system("pause");
	return 0;
}
*/