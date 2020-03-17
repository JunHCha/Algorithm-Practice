/*
https://www.acmicpc.net/problem/2501
����
� �ڿ��� p�� q�� ���� ��, ���� p�� q�� �������� �� �������� 0�̸� q�� p�� ����̴�.

6�� ���� ���

6 �� 1 = 6 �� 0
6 �� 2 = 3 �� 0
6 �� 3 = 2 �� 0
6 �� 4 = 1 �� 2
6 �� 5 = 1 �� 1
6 �� 6 = 1 �� 0
�׷��� 6�� ����� 1, 2, 3, 6, �� �� ���̴�.

�� ���� �ڿ��� N�� K�� �־����� ��, N�� ����� �� K��°�� ���� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� K�� ��ĭ�� ���̿� �ΰ� �־�����. N�� 1 �̻� 10,000 �����̴�. K�� 1 �̻� N �����̴�.

���
ù° �ٿ� N�� ����� �� K��°�� ���� ���� ����Ѵ�. ���� N�� ����� ������ K������ ��� K��° ����� �������� ���� ��쿡�� 0�� ����Ͻÿ�.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

int n, k;
std::vector<int> container;

int main() {
	std::cin >> n;
	std::cin >> k;

	for (int i = 1; i <= n; i++) {
		if (!(n % i)) {
			container.push_back(i);
		}
	}
	
	if (container.size() < k) std::cout << 0;
	else std::cout << container.at(k - 1);
	
	system("pause");
	return 0;
}
