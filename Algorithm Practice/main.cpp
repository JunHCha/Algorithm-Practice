//https://www.acmicpc.net/problem/2562
/*
����
9���� ���� �ٸ� �ڿ����� �־��� ��, �̵� �� �ִ��� ã�� �� �ִ��� �� ��° �������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

���� ���, ���� �ٸ� 9���� �ڿ���

3, 29, 38, 12, 57, 74, 40, 85, 61

�� �־�����, �̵� �� �ִ��� 85�̰�, �� ���� 8��° ���̴�.

�Է�
ù ° �ٺ��� ��ȩ ��° �ٱ��� �� �ٿ� �ϳ��� �ڿ����� �־�����. �־����� �ڿ����� 100 ���� �۴�.

���
ù° �ٿ� �ִ��� ����ϰ�, ��° �ٿ� �ִ��� �� ��° �������� ����Ѵ�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define MIN_INT -10001

using namespace std;

int maxNum, ans, container[10];

int main() {
	maxNum = MIN_INT;
	ans = -1;
	for (int i = 0; i < 9; i++) {
		cin >> container[i];
	}
	for (int i = 0; i < 9; i++)	{
		if (container[i] > maxNum) {
			maxNum = container[i];
			ans = i;
		}
	}
	cout << maxNum << endl;
	cout << ans + 1;

	system("pause");
	return 0;
}