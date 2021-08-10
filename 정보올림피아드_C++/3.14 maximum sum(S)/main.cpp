/*
n���� ���ҷ� �̷���� ������ ������, �ִ�� ������ �κ����� ���Ͻÿ�.
(2 <= n <= 100) (-1000���� 1000 ������ ����)
*/

 
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
	 
	return 0;
}