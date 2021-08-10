/*
https://www.acmicpc.net/problem/9506
����
� ���� n�� �ڽ��� ������ ��� ������� �հ� ������, �� ���� ��������� �Ѵ�.

���� ��� 6�� 6 = 1 + 2 + 3 ���� �������̴�.

n�� ���������� �ƴ��� �Ǵ����ִ� ���α׷��� �ۼ��϶�.

�Է�
�Է��� �׽�Ʈ ���̽����� �� �� �������� n�� �־�����. (2 < n < 100, 000)

�Է��� �������� -1�� �־�����.

���
�׽�Ʈ���̽� ���� ���ٿ� �ϳ��� ����ؾ� �Ѵ�.

n�� ���������, n�� n�� �ƴ� ������� ������ ��Ÿ���� ����Ѵ�(���� ��� ����).

�̶�, ������� ������������ �����ؾ� �Ѵ�.

n�� �������� �ƴ϶�� n is NOT perfect. �� ����Ѵ�.
*/

 
#include <iostream>
#include <vector>

std::vector<int> n;

void solve(int val) {
	int sum = 0;
	std::vector<int> container;
	for (int i = 1; i < val; i++) {
		if (val % i == 0) {
			sum += i;
			container.push_back(i);
		}
	}

	if (sum == val) {
		std::cout << val << " =";
		for (int i = 0; i < container.size(); i++) {
			std::cout << " " << container.at(i);
			if (!(i == container.size() - 1))
				std::cout << " +";
		}
		std::cout << std::endl;
	}
	else {
		std::cout << val << " is NOT perfect." << std::endl;
	}
}

int main() {	
	while (1) {
		int temp;
		std::cin >> temp;
		if (temp == -1) {
			break;
		}
		n.push_back(temp);
	}

	for (int i = 0; i < n.size(); i++) {
		solve(n.at(i));
	}
	 
	return 0;
}