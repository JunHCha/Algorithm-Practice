/*
n개의 원소로 이루어진 집합이 있을때, 최대로 가능한 부분합을 구하시오.
(2 <= n <= 100) (-1000부터 1000 사이의 원소)
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int n, c[100];
int maxx = -999999;

void f(int start, int end) {
	if (start > end) return;
	int res = 0;
	for (int i = start; i <= end; i++) {
		res += c[i];
	}
	if (res > maxx)
		maxx = res;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)	{
		cin >> c[i];
	}
	for (int i = 0; i < n; i++)	for (int j = i; j < n; j++) {
		f(i, j);
	}
	cout << maxx << endl;
	system("pause");
	return 0;
}