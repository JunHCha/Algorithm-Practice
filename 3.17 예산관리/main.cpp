/*
예산범위를 넘지 않는 선에서 다양한 활동을 하려고 할때
최대로 사용할 수 있는 비용액을 구하시오.

input : 
예산 : B
활동의 수 : n
각각의 활동비
*/

#define _CRT_SECURE_NO_WARNINGS
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
	system("pause");
	return 0;
}