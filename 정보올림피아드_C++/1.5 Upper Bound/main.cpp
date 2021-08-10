/*
n���� �̷���� �������տ��� k ���� ū ���� ó������ �����ϴ� ��ġ�� ã���ÿ�.
*/

 
#include <iostream>
#include <stdio.h>
#include <algorithm>

#define MAX_INT 1000001

using namespace std;

int n, m, container[MAX_INT], ans;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)	{
		cin >> container[i];
	}
	cin >> m;
	cout << upper_bound(container, container + n, m) - container + 1;
	 
	return 0;
}

/*
int n, m, container[MAX_INT], ans;

int solve(int start, int end, int target) {
	while (start < end) {
		int mid = (start + end) / 2;
		if (container[mid] <= target) start = mid + 1;
		else end = mid;
	}
	return end + 1;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> container[i];
	}
	cin >> m;
	cout << solve(0, n, m); // m�� ������ �ִ� ��� ������ �������� ����� 1 ~ n + 1 ������ �˻�
	 
	return 0;
}
*/

