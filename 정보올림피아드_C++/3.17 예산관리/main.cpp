/*
��������� ���� �ʴ� ������ �پ��� Ȱ���� �Ϸ��� �Ҷ�
�ִ�� ����� �� �ִ� ������ ���Ͻÿ�.

input : 
���� : B
Ȱ���� �� : n
������ Ȱ����
*/

 
#include <iostream>

using namespace std;

int b, n, cost[22], sum = 0;

void input() {
	cin >> b;
	cin >> n;
	for (int i = 1; i <= n; i++)	{
		cin >> cost[i];
	}
}

void f(int act, int usedCost) {
	if (act > n) {
		if (usedCost <= b && sum < usedCost)
			sum = usedCost;
		return;
	}


	f(act + 1, usedCost + cost[act]);
	f(act + 1, usedCost);
	

}

int main() {
	input();
	f(0, 0);
	cout << sum;
	 
	return 0;
}