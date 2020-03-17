/*
배낭에 W무게만큼 물건을 담으려고 한다.
물건들은 무게와 가격을 갖고있다.
가격이 최대가 되게 할때 그 최댓값을 구하시오.

input :
물건의 개수 n (1 <= n <= 100), 무게 w (1 <= w <= 10000)
wi (무게)
vi (가격)
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int n, w, wi[101], vi[101];

void input() {
	cin >> n;
	cin >> w;
	for (int i = 0; i < n; i++)	{
		cin >> wi[i + 1]; cin >> vi[i + 1];
	}
}

int max(int a, int b) {
	return a > b ? a : b;
}

int f(int index, int remainWeight) {
	if (index > n) {
		return 0;
	}
	if (wi[index] <= remainWeight)
		return max(f(index + 1, remainWeight), f(index + 1, remainWeight - wi[index]) + vi[index]); // 가장 깊은 트리에서부터 값이 결졍되는 꼴 (void 선언이었다면, terminal 에서부터 v 값을 정하면서 내려왔을것)

	if (wi[index] > remainWeight)
		return f(index + 1, remainWeight);

}

int main() {
	input();
	cout << f(0, w);
	system("pause");
	return 0;
}