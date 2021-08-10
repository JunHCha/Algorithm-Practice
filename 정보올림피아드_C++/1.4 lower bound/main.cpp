/*
n���� �̷���� �������տ��� ���ϴ� �� k �̻��� ���� ó������ �����ϴ� ��ġ�� ã���ÿ�.
*/

 
#include <iostream>
#include <stdio.h>
#include <algorithm>

#define MAX_INT 1000001

using namespace std;

int n, m, container[MAX_INT], ans;

int solve(int start, int end, int target) {
	while (start < end) {
		int mid = (start + end) / 2;
		if (container[mid] < target) start = mid + 1;
		else end = mid;
	}
	return end;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)	{
		cin >> container[i];
	}
	cin >> m;
	cout << solve(0, n, m) + 1; // m�� ������ �ִ� ��� ������ Ŭ���� ����� 1 ~ n + 1 ������ �˻�
	 
	return 0;
}





/* STL Ǯ��
int n, m, container[MAX_INT];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)	{
		scanf("%d", container + i);
	}
	scanf("%d", &m);
	printf("%d\n", lower_bound(container, container + n, m) - container + 1);
	 
	return 0;
}
*/