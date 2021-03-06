/*
n개로 이루어진 정수집합에서 원하는 수 k 이상인 수가 처음으로 등장하는 위치를 찾으시오.
*/

#define _CRT_SECURE_NO_WARNINGS
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
	cout << solve(0, n, m) + 1; // m이 수열에 있는 모든 수보다 클때를 대비해 1 ~ n + 1 범위를 검색
	system("pause");
	return 0;
}





/* STL 풀이
int n, m, container[MAX_INT];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)	{
		scanf("%d", container + i);
	}
	scanf("%d", &m);
	printf("%d\n", lower_bound(container, container + n, m) - container + 1);
	system("pause");
	return 0;
}
*/