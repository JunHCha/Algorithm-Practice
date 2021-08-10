/*
https://www.acmicpc.net/problem/2562
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

 
#include <iostream>
#include <vector>

int maxNum = 0, minNum = 100;
int maxIndex = -1, minIndex = -1;
int container[9];

int main() {
	for (int i = 0; i < 9; i++)	{
		std::cin >> container[i];
	}
	for (int i = 0; i < 9; i++)	{
		if (container[i] >= maxNum) { maxIndex = i + 1; maxNum = container[i]; }
	}
	std::cout << maxNum << std::endl;
	std::cout << maxIndex;
	 
	return 0;
}